/*
 * Copyright (C) 2010 Bluecherry, LLC
 *
 * Confidential, all rights reserved. No distribution is permitted.
 */

#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>

#include <libbluecherry.h>

extern struct bc_db_ops bc_db_sqlite;
extern struct bc_db_ops bc_db_psql;
extern struct bc_db_ops bc_db_mysql;

static pthread_mutex_t db_lock =
	PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP;

struct bc_db_handle bcdb = {
	.db_type	= BC_DB_SQLITE,
	.dbh		= NULL,
	.db_ops		= NULL,
};

void bc_db_lock(void)
{
	if (pthread_mutex_lock(&db_lock) == EDEADLK)
		bc_log("E: Deadlock detected in db_lock!");
}

void bc_db_unlock(void)
{
	if (pthread_mutex_unlock(&db_lock) == EPERM)
		bc_log("E: Unlocking db_lock owned by another thread!");
}

void bc_db_close(void)
{
	bc_db_lock();

	if (bcdb.db_ops)
		bcdb.db_ops->close(bcdb.dbh);
	bcdb.dbh = NULL;
	bcdb.db_ops = NULL;

	bc_db_unlock();
}

int bc_db_open(void)
{
	struct config_t cfg;
	long type;
	int ret = 0;

	bc_db_lock();

	if (bcdb.dbh != NULL) {
		bc_db_unlock();
		return 0;
	}

	config_init(&cfg);
	if (!config_read_file(&cfg, BC_CONFIG)) {
		bc_log("E(%s): Error parsing config at line %d", BC_CONFIG,
		       config_error_line(&cfg));
		goto db_error;
	}

	if (!config_lookup_int(&cfg, BC_CONFIG_DB ".type", &type)) {
		bc_log("E(%s): Could not get db type", BC_CONFIG);
		goto db_error;
	}

	switch (type) {
	case BC_DB_SQLITE:
		bcdb.db_type = BC_DB_SQLITE;
		bcdb.db_ops = &bc_db_sqlite;
		bcdb.dbh = bcdb.db_ops->open(&cfg);
		break;
	case BC_DB_PSQL:
	case BC_DB_MYSQL:
	default:
		bc_log("E(%s): Invalid db type %ld", BC_CONFIG, type);
	}

db_error:
	if (!bcdb.dbh) {
		bcdb.db_ops = NULL;
		ret = -1;
	}

	config_destroy(&cfg);

	bc_db_unlock();

	return ret;
}

int bc_db_query(const char *sql, ...)
{
	va_list ap;
	int ret;

	va_start(ap, sql);
	ret = bcdb.db_ops->query(bcdb.dbh, sql, ap);
	va_end(ap);

	return ret;
}

int bc_db_get_table(int *nrows, int *ncols, char ***res, const char *fmt, ...)
{
	va_list ap;
	int ret;

	va_start(ap, fmt);
	ret = bcdb.db_ops->get_table(bcdb.dbh, nrows, ncols, res, fmt, ap);
	va_end(ap);

	return ret;
}

void bc_db_free_table(char **res)
{
	bcdb.db_ops->free_table(bcdb.dbh, res);
}

char *bc_db_get_val(char **rows, int ncols, int row, const char *colname)
{
	int i;

	for (i = 0; i < ncols; i++) {
		if (strcmp(colname, rows[i]) == 0)
			break;
	}

	return (i == ncols) ? NULL : rows[((row + 1) * ncols) + i];
}

int bc_db_get_val_int(char **rows, int ncols, int row, const char *colname)
{
	char *val = bc_db_get_val(rows, ncols, row, colname);

	return val ? atoi(val) : -1;
}

int bc_db_get_val_bool(char **rows, int ncols, int row, const char *colname)
{
	char *val = bc_db_get_val(rows, ncols, row, colname);

	return val ? (atoi(val) ? 1 : 0) : 0;
}

long unsigned bc_db_last_insert_rowid(void)
{
	return bcdb.db_ops->last_insert_rowid(bcdb.dbh);
}
