/**
 * 9.1查找的基本概念
 */

// typedef int keytype;     整型关键字类型

typedef struct{     //记录类型定义
    int key;
}elemtype;

typedef struct{
    elemtype *elem;  //记录存储空间基地址，构造表时按实际长度分配，0好单元留空
    int length;        //表长度
}sstable;

//9.2.2二分查找
/**
 * 就是将数组的中间值取出来跟要查找的值相比较，但是数组必须是单调递增
 * 中间值区指针位置相加除二的整数，例如(6+7)/2取整等于6
 * 有两种实现，递归和循环
*/
int serch_bin (sstable st, int key){
    int low=1;
    int high=st.length;
    while(low<=high){
        int mid=(low+high)/2;
        if(key==st.elem[mid].key){
            return mid;
        }else if(key<st.elem[mid].key){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return 0;
}



/**
 * 9.3动态表查找
 * 二叉排序树，大概就是一堆数，将他们排序，选一个数出来作为根结点
 * 第二个数跟他比较比他小放在左子树，第三个数比他大放右子树
 * 然后依次类推
*/
typedef struct BiTNode{
    char data;    //结点数据域
    BiTree lchild, rchild;  //左右孩子指针
}*BiTree;


//算法9-5返回插入位置的二叉排序树的查找算法
int rsearchdst(BiTree t,int key,BiTree f,BiTree &p){
/**
 * 在二叉树中查找key，如果查找成功，指针p指向该结点，返回true
 * 不成功，则p指向查找路径上访问的最后一个结点，返回false
 * 指针f指向当前访问结点的双亲结点，其初始值为null
*/
    if(!t){
        return false;  //树为空直接查找失败
    }
    else if(t->data==key){      //书上是t->data.key 但是我这里没有                                 
        p=f;                   //树的第一个结点就是
        return true;
    }
    else if(t->data>key){     //t->data比较大，往左子树查找
        rsearchdst(t->lchild,key,t,p);  //这个t是双亲结点
    } 
    else{
        rsearchdst(t->rchild,key,t,p);
    }

}

//算法9-6二叉排序树中插入一个新结点
/**
 * 先去查找这个值存不存在，不存在则插入，存在则不插入
*/
int insertdst(BiTree &t,int e){
    BiTree p,s;
   if(!rsearchdst(t,e,nullptr,p)){ //判断e是否已经存在,如果不存在进行插入
    
   }

}