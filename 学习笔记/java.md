## arraylist

arraylist.sort()可以直接将数组进行排序，数组必须是可修改的数组

## 二维数组

第一个下标表示行，第二个下标表示列



string转char[]，s.toCharArray()



char[]长度用length

ArrayList长度用size



char[] 转string    String s1 = String.valueOf(chars);



## ArrayList<Character>

## stringBuilder

ArrayList<Character>转string时我用这个东西

deleteCharAt

append

toString





# java集合

## 1介绍

为了方便操作多个对象，就要存储多个对象，就要用容器（集合）装。

1.集合只能存放对象，例如int数据放进集合，会自动转换为integer类后存入

2.集合存放的是对象的引用，而非对象的本身，对象本身还是在堆内存中

3.集合可以存放不同的类型，不限量的数据类型

## 1.1集合的三种类型

list 有序列表集合，插入有序，元素可重复

set 保证没有重复元素的集合，插入无序，元素不可重复

map 一种键值对查找的映射表集合

LinkedHashMap,保持插入顺序，HashMap不保持插入顺序，排序选择TreeMap

## 2.集合的分类

list接口

1. LinkedList 接口实现类， 链表， 插入删除， 没有同步， 线程不安全
2. ArrayList 接口实现类， 数组， 随机访问， 没有同步， 线程不安全
3. Vector 接口实现类 数组， 同步， 线程安全（Stack 是Vector类的实现类）

set接口

1. HashSet 使用hash表（数组）存储元素

​	LinkedHashSet 链表维护元素的插入次序

1. TreeSet 底层实现为二叉树，元素排好序

![1](D:\something\github\myCollegeLife\picture\learn\java\1.jpg)

collection接口

​	list接口 

​		arrayList类（数组、查询快、增删效率低）、LinkedList类(链表，查询慢，增删除效率高)、Vector类（数组、线程安全，效率低）

​	set接口  

​		TreeSet、HashSet-->LinkedHashSet

![2](D:\something\github\myCollegeLife\picture\learn\java\2.jpg)

