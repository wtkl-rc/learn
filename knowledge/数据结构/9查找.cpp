/**
 * 9.1查找的基本概念
 * 2.查找表
 * 3.平均查找长度（ASL）
 * 通常把查找过程中给定值与关键字值的比较次数的期望值作为衡量一个查找算法效率优劣的标准
 */

// typedef int keytype;     整型关键字类型


//9.2静态表查找

typedef struct{     //记录类型定义
    int key;
}elemtype;

typedef struct{
    elemtype *elem;  //记录存储空间基地址，构造表时按实际长度分配，0好单元留空
    int length;        //表长度
}sstable;


//9.2.1顺序查找
/**
 * 算法9-1顺序查找算法
 * 也称为线性查找法，就是从顺序表的一端，依次将每条记录跟key值对比
 * 如果找到返回下标，找不到就找不到
*/


//算法9-2带监视哨的顺序查找算法
int search_seq(sstable st,int key){
    int i;
    st.elem[0].key=key;   //大概感觉就是把key放到0位置，这样好像方便确定越界吧
    for(i=st.length;st.elem[i].key!=key;i--);
    return i;  //这里是秒棋啊，上面的循环，循环到==key时就停止，然后，就直接返回。找不到就返回0
}


//9.2.2二分查找
/**
 * 算法9-3二分查找
 * 就是将数组的中间值取出来跟要查找的值相比较，但是数组必须是单调递增
 * 中间值区指针位置相加除二的整数，例如(6+7)/2取整等于6
 * 可以用循环或递归实现
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
 * 9.2.3分块查找
 * 
*/





/**
 * 9.3动态表查找
*/
typedef struct BiTNode{
    char data;    //结点数据域
    BiTree lchild, rchild;  //左右孩子指针
}*BiTree;


/**
 * 9.3.1二叉排序树
  * 二叉排序树，大概就是一堆数，将他们排序，选一个数出来作为根结点
  * 第二个数跟他比较比他小放在左子树，第三个数比他大放右子树
  * 然后依次类推
 */

//算法9-4二叉排序树的查找

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

//算法9-7构造一颗二叉排序树

//算法9-8二叉排序树删除一个结点


/**
 * 9.3.1平衡二叉树
*/

/**
 * 9.3.3B_树和B+树
*/

/**
 * 9.3.4红黑树
*/

//9.4哈希表
//9.4.1哈希表的定义

/**
 * 9.4.2常用的哈希函数
 * 1.除留余数法
 * 2.直接地址法
 * 3.数字分析法
 * 4.平方取中法
 * 5.折叠法
 * 6.随机数法
 * 
 * 9.4.3处理冲突的方法
 * 1.开放地址发
 * 2.链地址法
 * 3.公共溢出区法
 * 4.再哈希法
 * 
 * 9.4.4哈希表的查找和性能分析
*/

