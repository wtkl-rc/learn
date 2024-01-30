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

