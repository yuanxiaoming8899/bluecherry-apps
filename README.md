<div class="Box-sc-g0xbh4-0 bJMeLZ js-snippet-clipboard-copy-unpositioned" data-hpc="true"><article class="markdown-body entry-content container-lg" itemprop="text"><div class="markdown-heading" dir="auto"><h2 tabindex="-1" class="heading-element" dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">从源头构建</font></font></h2><a id="user-content-building-from-source" class="anchor" aria-label="永久链接：从源代码构建" href="#building-from-source"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path d="m7.775 3.275 1.25-1.25a3.5 3.5 0 1 1 4.95 4.95l-2.5 2.5a3.5 3.5 0 0 1-4.95 0 .751.751 0 0 1 .018-1.042.751.751 0 0 1 1.042-.018 1.998 1.998 0 0 0 2.83 0l2.5-2.5a2.002 2.002 0 0 0-2.83-2.83l-1.25 1.25a.751.751 0 0 1-1.042-.018.751.751 0 0 1-.018-1.042Zm-4.69 9.64a1.998 1.998 0 0 0 2.83 0l1.25-1.25a.751.751 0 0 1 1.042.018.751.751 0 0 1 .018 1.042l-1.25 1.25a3.5 3.5 0 1 1-4.95-4.95l2.5-2.5a3.5 3.5 0 0 1 4.95 0 .751.751 0 0 1-.018 1.042.751.751 0 0 1-1.042.018 1.998 1.998 0 0 0-2.83 0l-2.5 2.5a1.998 1.998 0 0 0 0 2.83Z"></path></svg></a></div>
<p dir="auto"><a href="https://gitter.im/bluecherrydvr/dev-server?utm_source=badge&amp;utm_medium=badge&amp;utm_campaign=pr-badge&amp;utm_content=badge" rel="nofollow"><img src="https://camo.githubusercontent.com/a317cd2ce140ce8b42d3416b3df7ce60d5dc788f2101fa8860105dad3694183b/68747470733a2f2f6261646765732e6769747465722e696d2f626c75656368657272796476722f6465762d7365727665722e737667" alt="加入聊天：https://gitter.im/bluecherrydvr/dev-server" data-canonical-src="https://badges.gitter.im/bluecherrydvr/dev-server.svg" style="max-width: 100%;"></a><a href="https://join.slack.com/t/bluecherry-public/shared_invite/zt-rhxb117k-m5sCsp_FF0l8cToB56HeYA" rel="nofollow"><img src="https://camo.githubusercontent.com/ba2c736cd15df6103946fb176d8b5f15acdc2df1a97ca00fad8ddd5ea5a812d7/68747470733a2f2f696d672e736869656c64732e696f2f7374617469632f76313f6d6573736167653d6a6f696e2532306368617426636f6c6f723d396366266c6f676f3d736c61636b266c6162656c3d736c61636b" alt="加入我们的 Slack！" data-canonical-src="https://img.shields.io/static/v1?message=join%20chat&amp;color=9cf&amp;logo=slack&amp;label=slack" style="max-width: 100%;"></a></p>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">目前，从源代码构建需要运行预先配置的脚本来生成构建所需的一些文件。</font><font style="vertical-align: inherit;">过去我们使用 chroot 来构建环境，但是可以使用以下命令为您的特定发行版进行构建：</font></font></p>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">在 bluecherry-apps 的根目录中运行以下命令。</font></font></p>
<p dir="auto"><code>scripts/build_pkg_native.sh</code></p>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">例子：</font></font></p>
<p dir="auto"><code>root@buildtest:~/git/bluecherry-apps# scripts/build_pkg_native.sh</code></p>
<p dir="auto"><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">请不要使用“dh”特定命令，脚本会为您生成多个文件（例如 version.h）和 Debian 控制文件。</font></font></strong></p>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">依赖项（服务器）：</font></font></p>
<ul dir="auto">
<li><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">mysql（debian：libmysqlclient-dev）</font></font></li>
<li><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">libbsd（debian：libbsd-dev）</font></font></li>
<li><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">PHP（Debian：php5-dev）</font></font></li>
<li><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">udev（debian：libudev-dev）</font></font></li>
</ul>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">依赖项（libav）：</font></font></p>
<ul dir="auto">
<li><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">亚斯姆</font></font></li>
<li><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">alsa-lib（debian：libasound2-dev）</font></font></li>
</ul>
<p dir="auto"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">捆绑的库：</font></font></p>
<ul dir="auto">
<li><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">库配置</font></font></li>
<li><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">利巴夫</font></font></li>
</ul>
<hr>
</article></div>
