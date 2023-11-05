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

