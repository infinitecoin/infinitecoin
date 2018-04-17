Infinitecoin
---
Infinitecoin is a fork of Litecoin version. Like Litecoin it uses scrypt as a proof of work scheme.

	- Total coins will be about 90,600 millions 
	- 30 sec block target
	- Difficulty retargets once every hour
	- initially 524,288 (2^19) coins per block, halves every 1 month (86,400 blocks).
	- The default ports are 9321(connect) and 9322(json rpc).

无限币的技术参数：
---
更多：https://ifc.1e9.cc/start-page.html

	- 无限币是从莱特币分支而来，使用scrypt工作量证明机制进行产矿
	- 每30秒产生一个区块。
	- 最初每区块524,288 (2^19) 个无限币，每86,400区块产出减半
	- 每区块调整难度，从发布起开始加速。
	- 每次交易需要等待3个确认（约10~12秒钟）
	- 总计约906亿无限币
	- 通信端口 9321, RPC-端口9322
	- Scrypt Proof-of-Work 算法.

Development process
===================
2018-04-10
--
1. Fix the problem that IFC can't start after Linux system is turned off IPv6.

2018-03-22
--
community official version 1.8.8.2, this version is modified and compiled based on the original 1.8.8.0 source code.
1. increased direct click transactions in transaction records, ID can jump to block browser query transaction records.
2. repair the receiving currency form, modify the first label in the address book form, cause the second tags to be modified bug.
3. about page image replacement, and increased the community's official website link.
4. repair of the lower right corner in the state of typos "kind" correct "clock"
5. improve the mining state of the lower right corner of Chinese display
6. verify that all English in the message window is translated into Chinese.
7. perfect the Chinese tray right click menu language display
8. improve the Chinese language display page.
9. The options page improves the Chinese language display
10. Improve the Chinese language display in the rest of the warning box
11. increase the number of connections to the default network nodes to 32, improve the block synchronization speed.
12. Upgrade the QT version to 4.8.7 to improve security
13. modify the default location of block data, which is the Infinitecoin folder under the current software running directory.
14. there will be vc++ rumtime error error when repairing json-rpc and console.

2018-3-15
--
1. increase the number of connections to the default network nodes to 32, improve the block synchronization speed.
2. perfect Chinese Translation
3. Upgrade the QT version to 4.8.7 to improve security
4. modify the default location of block data, which is the Infinitecoin folder under the current software running directory.


(Older)2015-4
---
Developers work in their own trees, then submit pull requests when
they think their feature or bug fix is ready.

The patch will be accepted if there is broad consensus that it is a
good thing.  Developers should expect to rework and resubmit patches
if they don't match the project's coding conventions (see coding.txt)
or are controversial.

The master branch is regularly built and tested, but is not guaranteed
to be completely stable. Tags are regularly created to indicate new
official, stable release versions of Litecoin.

Feature branches are created when there are major new features being
worked on by several people.

From time to time a pull request will become outdated. If this occurs, and
the pull is no longer automatically mergeable; a comment on the pull will
be used to issue a warning of closure. The pull will be closed 15 days
after the warning if action is not taken by the author. Pull requests closed
in this manner will have their corresponding issue labeled 'stagnant'.

Issues with no commits will be given a similar warning, and closed after
15 days from their last activity. Issues closed in this manner will be 
labeled 'stale'. 

开发进程
===================
最新windows系统钱包的下载，其他版本的钱包请自行编译
-----
https://ifc.1e9.cc/archives/108.html

2018-4-17
---
1. 将源码提交到github

2018-4-10
------
1. 修复linux系统关闭ipv6后的ifc无法启动的问题


2018-03-22
-----
0. 社区正式版1.8.8.2，此版本基于原版1.8.8.0源码修改编译
1. 交易记录中增加了直接点击交易ID即可跳转到区块浏览器查询交易记录
2. 修复接收货币表格、地址簿表格中修改第一个标签会导致错误第二个标签被修改的bug
3. 关于页面图片更换，并增加了社区的官网链接
4. 修复右下角状态中的错别字“种”改正为“钟”
5. 完善右下角挖矿状态中文显示
6. 验证消息窗口中的所有英文全部翻译成中文
7. 托盘中右键菜单完善中文语言显示
8. 挖矿页面完善中文语言显示
9. 选项页面完善中文语言显示
10. 完善其余警告框中的中文语言显示
11. 增加默认网络节点连接数到32个，提高区块同步速度
12. 升级qt版本为4.8.7，提升安全性
13. 修改区块数据默认存放的位置为当前软件运行目录下的Infinitecoin文件夹
14. 修复json-rpc和控制台时会出现 vc++ rumtime error的错误
