## What

基于内存的key-values数据库

## 应用场景

缓存

任务队列

消息队列

分布式锁 

## linux安装redis

解压安装包

安装gcc yum install gcc-c++

进入redis目录 make

再进入src 执行 make install

## redis配置

./redis-server

### 连接

./redis-cli

### 后台运行

vim redis.conf

daemonize yes 后台运行

再次启动

src/redis-server ./redis.conf

### 启动密码验证

修改conf，requirepass 

启动cli src/redis-cli -h localhost -p 6379 -a 密码（auth 密码）

### 启动远程连接

conf配置 

注释 bind 127....



## 数据类型

key是string类型

value分为5种

string 普通字符串

hash field value 适合存储对象

list 按照插入顺序排序，有重复元素，用做消息队列

set 无序集合，没有重复元素

sorted set 有序集合，没有重复元素，每个元素关联了一个分值，常用于热搜的排行榜

## redis常用命令

### string

set key value

get key

setex key seconds value 设置key的有效秒数

setex key value 当key不存在时才设置返回1为成功

### hash

hset key field value 将哈希表key中的字段field的值设为value

hget key field 获取存储在哈希表中指定字段的值

hdel key field 删除存储在哈希表中的指定字段

hkeys key 获取哈希表中所有字段

hvals key 获取哈希表中所有的值

hgetall key 获取哈希表中指定key的所有字段和值

###  list

lpush key value1 [value2] 将一个或多个值插入到列表头部

lrange key start stop 获取列表指定范围内的元素

rpop key 移除并获取列表的最后一个元素

llen key 获取列表的长度

brpop key1 [key2] timeout 移除并获取列表的最后一个元素,如果列，表没有元素会阻塞列表知道等待超时或发现可弹出元素为止，就是timeout秒后再返回

### set

string类型的无序集合

sadd

smembers  返回成员

scard 返回长度

sinter 两个集合都有的元素，交集

sunion 并集

sdiff 差集 谁减谁

srem 删除

### sorted set

zadd  key score member  添加成员，或更新成员分数

zrange key start stop  返回成员

zincrby key increment menber 指定成员增加分数

zrem key member 移除成员

## 通用命令

keys pattern 查找所有符合给定模式的key

exists key 检查给定key是否存在

type key 返回key所存储的值和类型

ttl key 返回给定key的剩余生存时间

del key 该命令用于在key存在是删除key

## java连接redis

jedis连接

```
<dependency>
    <groupId>redis.clients</groupId>
    <artifactId>jedis</artifactId>
</dependency>
```



spring data redis

```
<dependency>
    <groupId>org.springframework.boot</groupId>
    <artifactId>spring-boot-starter-data-redis</artifactId>
</dependency>
```

配置yml

