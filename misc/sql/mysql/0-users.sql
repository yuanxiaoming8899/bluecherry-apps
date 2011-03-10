CREATE TABLE Users (
	id integer PRIMARY KEY NOT NULL AUTO_INCREMENT,
	username varchar(40),
	password varchar(64),
	salt CHAR(4),
	name varchar(60),
	email varchar(60),
	phone varchar(15),
	notes varchar(255),
	access_setup boolean,
	access_remote boolean,
	access_web boolean,
	access_backup boolean,
	access_relay boolean,
	access_device_list varchar(255) DEFAULT '',
	access_ptz_list varchar(255) DEFAULT '',
	access_schedule varchar(168) DEFAULT '111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111'
);

INSERT INTO Users VALUES (1, 'Admin', 'b22dec1d6cfa580962f3a3796a5dc6b3', '1234', 'Bluecherry Admin', NULL, NULL, NULL, 1, 1, 1, 1, 1, '', '', 111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111);

CREATE TABLE ActiveUsers (
	id integer PRIMARY KEY NOT NULL AUTO_INCREMENT,
	ip varchar(20),
	from_client boolean,
	time integer,
	kick boolean
);