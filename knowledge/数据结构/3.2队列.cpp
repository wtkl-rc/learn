#include <iostream>
using namespace std;

/**
 * 3.2.3顺序队列
 * 
*/
const int maxsize=10;

typedef struct {
    
    int front;      //队头指针
    int rear;      //队尾指针
    int *base; //队列存储空间的基地址
}sqqueue;

/**
 * 会出现假溢出现象，也就是后一个数组的后面满了但前面没有满
 * 解决方法是循环队列，首尾相连
 * 
*/

//3-13循环顺序队列的初始化
int initqueue(sqqueue &q){
    q.base=new int(10);   //开辟一块空间
    if(!q.base){
        exit;
    }
    q.front=0;         //为什么指针是0
    q.rear=0;           //因为开辟的空间为数组，base是数组的头指针
}

/**
 * 如何判断队列是否为空或满
 * 因为队列为空或满都满足条件q.front=q.rear
 * 方法一：
 * 少用一个存储单元，比如队列有6个容量但只能存储5个数据，多一个空的
 * 队空的条件：rear==front
 * 队满的条件：front==（rear+1）%maxsize
 * 方法二：
 * 设置一个标志变量，
 * 队空条件：front==rear&&flag==0   我也不知道为什么可以这样，应该是入队无论进几个直接设置为1
 * 队满条件：front==rear&&flag==1   出队无论几个直接设置为0
 * 方法三：
 * 设置一个计数器
 * 
*/

//3-14循环顺序队列的入队操作
    
int enqueue(sqqueue &q,int e){
    //设置一个标志变量的方法
    int flag;
    //在循环顺序队列q中插入新的元素w，使其成为新的元素的队尾    
    if(flag==1&&q.rear==q.front){       //判断队列是否为空
        return 0;
    }

    q.base[q.rear]=e;    //入队   队尾入队，队头出队
    /**
     * 如果队列长为8
     * 在7的时候加1等于0，所以%取小数
     * 如果为6加1等于7，7%8=0.875。我惊呆了，反正你这样算，他取余都是加一
    */
    q.rear=(q.rear+1)%maxsize;   
    return 1;
}

//3-15循环顺序队列的出队操作
int dequeue(sqqueue &q,int &e){//设置一个标志变量的方法
    //删除循环顺序队列q中的队首元素，并用e返回其值

    int flag;  //我也不知道这个值该设置为多少，我认为这应该是个全局变量，在入队和出队里面都可以操作这个值

    if(q.front==q.rear&&flag==0){  //当前队空
        return 0;
    }
    e=q.base[q.front];     //队头出？

    q.front=(q.front+1)%maxsize;
    return 1;
}


//3-16求长度
int queuelength(sqqueue q){ //设置一个标志变量法
    //返回循环顺序队列中数据元素的个数
    if(q.front==q.rear&&flag==1){   //队满
        return maxsize;
    }else{
        return (q.rear-q.front+maxsize)%maxsize;  //不知道是什么东西
    }
}

/**
 * 3.2.4链队
 * 在数据a1之前还有一个头结点q.front指向的是头结点
 * 所以q.front是头结点->next才是数据？？？
*/
    typedef struct qnode{  //这个是链队的数据data和下一个结点
        int data;
        struct qnode* next;  
    }qnode,*queueptr;

    typedef struct{     //这是单独的指向头尾结点的指针
        queueptr *front;   //队首指针
        queueptr *rear;   //队尾指针
    }linkqueue;   //链队列类型

    //队尾入队，队头出队

    //3-17链队的初始化
    int initqueue(linkqueue &q){
    //创建一个空链队列，带头结点
        q.front=new qnode;       //创建新结点

        if(!q.front){           //分配空间失败
            return 0;
        }
        q.front->next=NULL;    //让头结点指向null
        q.rear=q.front;       
        return 1;               //是队尾指针指向头结点
    }

    //3-18链队入队
    int enqueue(linkqueue &q,int e){
        qnode* p=new qnode;     //定义一个指针指向新结点

        p->data=e;              //结点等于data等于e

        /**
         * 下面是书本的写法
         * 具体细节我不知道
         * 但我觉得可以p->next=NULL;
         * 感觉差不多
        */
        p->next=q.rear->next;   
     
        q.rear->next=p;         //让队尾的next指针指向它
        q.rear=p;               //让队尾指针指向它
    }

    //3-19链队出队
    int dequeue(linkqueue &q,int &q){
        //删除连队列中的队首数据元素，并用e返回其值
        if(q.rear==q.front){                  //判断是否空队
            return 0;
        }
        //队头出队
        qnode* p=q.front->next;   //next不懂看前面
        e=p->data;
        q.front->next=p->next;   

        if(p==q.rear){  //如被删除的结点是队尾结点
            q.rear=q.front;    //??
            free(p);
            return 1;
        }
    }

    /**
     * 3.2.5其他队列
     * 1、优先级队列
     * 例如日常生活中，排队时，残障人士可以有优先排队的权利
     * 通常用数字代表优先级，数字越小优先级越高
     * 
     * 可以用两种方式实现：
     * 第一种队列的元素优先级高到低排序，优先级高的在队首
     * 在队首删除元素，但是插入元素时，是插入到队列的合适位置。
     * 
     * 第二种是队列中的元素顺序进入队列，删除元素要选择优先级最高的元素出队
     * 两种算法都是o(n)
     * 
     * 2、双端队列
     * 是一种操作受限的线性结构
     * 队列两端都可以进行入队和出队的操作
     * 前端进的元素排列在队列中后端进的元素的前面，后端进的元素排列在队列中前端进的元素的后面（没有很懂什么鬼意思）
     * 无论是在前端还是后端出队，先取出的元素排列在后取出的元素的前面
     *     入队---> -------------- --->
     *              a1 a2 a3 a4 a5
     *     出队<--- -------------- <---
     * 
     * 输出受限的双端队列
     * 一端允许出队，但允许两端进行入队
     * 输入受限的双端队列
     * 同理
    */






