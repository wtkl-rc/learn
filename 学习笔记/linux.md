# 1.查看端口占用

lsof -i:8080

# 2.ubuntu 安装mysql

```
sudo spt-get install mysql-server
apt-get isntall mysql-client
sudo apt-get install libmysqlclient-dev

登录mysql，密码mysql
mysql -u root -p 
```

在mysql里面，有个mysql的数据库，里面的user表，host跟user



新建一个用户

```
create user 'username'@'host' identified 'password'
username是用户名
host指定在哪个主机上可以登录，%所有主机
password 这你都不知道你可以去死了
```

用户授权

```
update user set host='%' where user='username';    更改主机

flush privileges刷新

GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' WITH GRANT OPTION;

需要先更该主机在授予权限才可以，mysql8和之前版本的一些语法不相同
```

刷新权限

```
flush privileges
```

```
INSERT INTO user 
          (host, user, password, 
           select_priv, insert_priv, update_priv) 
           VALUES ('%', 'rcnie', 
           'fcuk', 'Y', 'Y', 'Y');
```





```
查看安装的mysql
rpm -qa | grep -i mysql
```

apt-get

```
sudo apt-cache madison package
```

# 命令格式

command  [-option]选项可以省略   [parameter]  ，[]表示可选选项

使用ll查看文件的前面的 - 是文件的意思，d是目录的意思

# 常用命令

ls list  查看当前目录内容

pwd  print work directory 查看当前目录

cd change directory 切换目录

touch 如果文件不存在，新建文件

mkdir make directory 创建目录

rm remove 删除指定文件

## ls 

ls -a -l , ls -al  , ls -al /etc

-a 显示所有文件包括以 . 开头的隐藏文件

-l 文件形态、权限、拥有者、文件大小

## cd

cd [dirName]

~ 当前用户的用户目录

. 当前所在的目录

.. 上一级

## cat

显示文件内容

cat [-n] filename

-n 由1开始对所有输出的行数的编号

例：cat /etc/profile 查看etc目录下的profile文件内容

## more

以分页形式显示文件内容

more filename

回车 向下滚动一行

空格 向下滚动以屏

b 向上滚动一屏

q或者ctrl+c 退出more

## tail

查看文件末尾的容

tail [-f] filename 

-f 动态读取文件末尾内容并显示，通常用于读取日志

例：tail -20 /etc/profile 显示末尾的20行

## mkdir

创建目录

-p 多层目录的创建

例：mkdir -p 1/2/3

## rmdir

删除空目录

rmdir [-p] dirname

 -p 子目录被删除后父目录为空目录则一并删除

例： rmdir ii*使用通配符

## rm

删除文件或者目录

-r 递归删除，就是非空目录也可以删除

-f 无需确定直接删除

## cp

用于复制文件或者目录

cp [-r] sourse dest

sourse源  dest目标

-r 如果复制的是目录的时候

## mv

为文件或者目录改名、转移位置

mv sourse dest

例：mv hello.txt hi.txt

## tar

对文件进行打包、解包、压缩、解压

tar [-zcxvf] filename [files]

包文件后缀为.tar表示只打了包

包文件后缀为.tar.gz表示打包的同时还进行了压缩

-z z代表的是gzip,通过gzip命令处理文件，gzip可以对文件压缩或者解压

-c create 创建新的包文件

-x extract 实现从包文件中还原文件

-v verbose 显示命令的执行过程

-f f代表的是file 用于指定包文件的名称

例:

tar -cvf test.tar test 

tar -zcvf test.tar.gz  test  压缩文件

tar -zxvf test.tar.gz 解压文件

tar -zxvf hello.tar.gz -C  usr/local 中间的-c表示解压到指定的文件目录

## find

在指定目录下查找文件

find dirname -option filename

find . -name "*.java" 在当前目录和子目录，根据名字，查找.java 的文件

## grep

在指定的文件中查找指定的文本内容

grep word filename 

例：grep hello *.java 在所有java文件中查找hello

# 文本编辑vi/vim

vi是linux中的一个文本编辑工具类似记事本，vim是由vi发展而来的文本编辑工具，功能更加强大

命令模式command mode

插入模式 insert mode 

底行模式 last line mode

## 命令模式

移动光标：gg移动到开头、G移动到尾

## 插入模式

在命令模式中按i a o 进入

## 底行模式

命令模式中 : 或者 / 进入

通过 / 进入可以对文本内容进行查找

通过 : 进入可以输入wq 保存并退出 、q! 不保存退出 、set nu 显示行号

# 软件安装

二进制安装

​	软件针对具体平台编译打包发布，只要解压、修改配置就可以安装

rpm安装

​	按照redhat的包管理规范进行打包，使用rpm命令进行安装，不能自行解决库依赖问题

yum安装

​	在线安装，本质上还是rpm安装，自动下载安装包安装，安装过程解决库依赖问题

源码编译安装

​	源码自行编译

## java安装

自行安装的软件一般在 usr/local

配置环境变量 etc/profile

JAVA_HOME=路径

PATH=$JAVA_HOME/bin:$PATH

重新加载profile文件，source /etc/profile

检查安装否成功 java -version

## tomcat安装

启动tomcat直接进入bin目录执行start的shell脚本

验证是否启动成功

1 查看启动日志

​	more apach-tomcat/logs/catalina.out

2 查看进程 

​	ps -ef | grep tomcat

ps -ef 可以查看当前运行的所有进程的详细信息

| 在linux中称为管道符，可以将前一个命令的输出给后一个命令作为输入



停止tomcat服务

1 运行shutdown.sh

2 通过ps 获取进程id 直kill -9 进程id

kill是用于结束进程的命令 -9表示强制结束



## 防火墙

查看防火墙状态

​	systemctl status firewalld 、 firewall-cmd --state

暂时关闭防火墙

​	systemctl stop firewalld

永久关闭防火墙

​	system disable firewalld

开启防火墙

​	systemctl start firewalld

开放指定端口

​	firewall-cmd --zone=pulic --add-port=8080/tcp --permanent

关闭指定端口

​	firewall-cmd --zone=public --remove-port=8080/tcp --permanent

立即生效

​	firewall-cmd --reload

查看开放端口

​	firewall-cmd --zone=public --list-ports 



systemctl 是管理linux中服务的命令，可以对服务进行启动，停止，重启、查看状态等操作

firewall-cmd 是linux中专门用于控制防火墙的命令

## rpm

### 查询

rpm -qa 查询当前系统中安装的所有软件 q是查询，a是all

rpm -qa | grep mysql 查询系统中安装的名称带mysql的软件

### 卸载

rpm -e --nodeps 软件名字 

### 安装

需要按照顺序安装rpm文件

rpm -ivh 文件名

## 安装mysql

mariadb与mysql冲突，安装之前要删除

需要yum install net-tools 

## 启动mysql

systemctl status mysqld 查看mysql服务状态

systemctl start mysqld 启动服务

可以设置开机启动mysql服务

systemctl enable mysqld  开机启动mysql服务

netstat -tunlp 查看已经启动的服务

netstat -tunlp | grep mysqld

## 登录mysql

查看临时密码

cat var/log/mysqld.log 查看文件内容  | grep password

mysql -uroot -p

修改密码

set global validate_password_length=4  设置密码长度最低位数

set global validate_password_policy=LOW 设置密码安全等级低，便于修改成root

set password= password('root') 设置密码为root

开启访问权限

grant all on *.* to 'root'@'%'identified by 'root'   @是匹配所有ip地址

flush privileges

## yum

yum list 软件名

yum install 软件名

# 项目部署

/app目录放jar包

## nohup

no hang up 不挂起 用于不挂断地运行指定命令,退出终端不会影响程序的运行

nohup command [arg..] [&]

command 要执行的命令

arg 一些参数，可以指定输出文件

& 让命令在后台运行

例：nohup java -jar hello.jar &>hello.log &  后台运行java -jar 命令,并将日志输出到hello.jar文件

## maven安装

配置环境变量

mvn -version 检查是成功

修改配置文件设置本地仓库

vim maven/conf/settings.xml

<localRepository>/usr/local/repo</localRepository>

## shell脚本

## 权限

linux中权限分为 r读 w写 x执行

linux的文件调用权限分为三级：文件所有者owner  	用户组group 	其他用户other users

只有文件的所有者和超级用户可以修改文件或目录的权限

执行shell脚本要有对此脚本的执行权限

例:

-r--r--r--  

表示文件类型

r-- 表示文件所有者对文件只有读权限没有写和执行

r-- （第二个）表示用户组，第三个表示其他用户

## chmod

7 rwx	6 rw-	5 r-x	4 r--	3 -wx	2 -w-	1 --x	0 ---

例：chmod 777 文件名

## 设置静态ip

/etc/sysconfig/network-scripts/ifcfg-ens33(不固定)

bootproto= static 

ipaddr = "192.168.138.100" 设置的静态ip地址

netmask="255.255.255.0" 子网掩码

gateway="192.168.138.2" 网关地址

dns1="192.168.138.2" dns服务器

systemctl  restart network

# 安装anaconda

```
wget -c 'https://repo.anaconda.com/archive/Anaconda3-2023.09-0-Linux-x86_64.sh' -P /home/krisnat/Downloads
```

