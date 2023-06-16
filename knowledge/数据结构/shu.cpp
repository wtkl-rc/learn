/**
 * 顺序结构，用数组实现，一般只用于完全二叉树，因为浪费空间
 * 
 * 链二叉树：一个数据域和一个指针域
*/
#include<iostream>

using namespace std;

typedef struct BiTNode{
    char data;    //结点数据域
    struct BiTree *lchild, *rchild;  //左右孩子指针
}*BiTree;

/**
 * 遍历二叉树的方法，前序遍历，后序遍历，中序遍历，层序遍历
*/

//前序遍历
void qxbl(BiTree T){
    if(T==NULL){
        return ;
    }
    cout<<T->data<<endl;

    qxbl(T->lchild);
    qxbl(T->rchild);    //递归思想
}
//推导遍历结果？？

//已知前序遍历和中序遍历可以确定唯一的二叉树，知后序和中序也可以


//二叉树的建立    传入的是指针，指向根节点的指针
void createtree(BiTree T){  
    char ch;
    cin>>ch;
    if(T->data=='#'){
        T->data=NULL;
    }else{
        BiTree T1=new BiTNode;
        if(T1==NULL){
            exit(0);
        }
        T1->data=ch;     //生成根节点
        createtree(T1->lchild);

        createtree(T1->rchild);
    }
}



/**
 * 线索二叉树
 * 原因：指针域使用不充分
 * n个结点有2n个指针域，n个结点的二叉树有n-1（就是有多少个不为空的指针域，有多少条箭头）条分支路线，存在2n-（n-1）=n+1个空指针域
 * 
 * 把指向前驱，指向后继的指针称为线索，加上线索的二叉链表称为线索链表，相应的二叉树称为线索二叉树
 * 
 * 把l和r改为前驱和后继   线索化懂？
 * 
 * 那我们怎么知道lchild指向左孩子还是后继？
 * ltag为0指向该节点的左孩子，为1指向该结点的前驱
 * rtag为0指向该节点的右孩子，为1指向该结点的后继
*/



//线索二叉树的实现

typedef enum{            
    link,thread
}pointtag;





