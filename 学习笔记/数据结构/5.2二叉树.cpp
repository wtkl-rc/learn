#include <iostream>
using namespace std;

//二叉链表存储
typedef struct BiTNode{
    char data;    //结点数据域
    BiTree lchild, rchild;  //左右孩子指针
}*BiTree;

//三叉链表
typedef struct TriNode {
    int data;  //数据域
    struct TriNode* lchild, *rchinld;  //左孩子右孩子
    struct TriNode* parent;  //双亲结点
};


//双亲链表
typedef struct BPTNode {//结点结构
    int data;  //数据域
    struct TriNode* parent;  //双亲结点
    char LTTag;   //左孩子标志域  表示是双亲的左孩子还是右孩子
};

typedef struct BPTree{//树结构
    BPTNode * nodes;
    int num_node;   //结点数目
    int root;     //根结点位置
};


/*
创建树的时候他是怎么做到每个结点和每个结点有相关的
*/


//二叉树上的查找算法
int search(BiTree &T,char x){
    if(T!=NULL){
        if(T->data==x){
            return 1;   //返回该结点，这里的1表示成功的意思
        }else{
                        //查找左右子树，左子树成功返回左结点
            return (search(T->lchild,x))!=0?search(T->lchild,x):search(T->rchild,x);
        }
    }
    return 0;
}

//中序遍历的递归算法
void InOrderTraverse(BiTree T){
    if(T!=NULL){
        InOrderTraverse(T->lchild);
        cout<<T->data;
        InOrderTraverse(T->rchild);
    }
}

//先序遍历建立二叉链表  根左右 
//结点与结点之间没有联系
void CreateBiTree(BiTree &T){
    char ch;
    ch='#';
    cin>>ch;
    if(ch=='#'){
        exit;
    }else{
        BiTree p =new BiTNode;
        p->data=ch;
        CreateBiTree(p->lchild);
        CreateBiTree(p->rchild);
    }
}

//5.4复制二叉数
void Copy(BiTree &T,BiTree &NewT){
    if(T!=NULL){
        NewT=new BiTNode;
        NewT->data=T->data;
        Copy(T->lchild,NewT->lchild);
        Copy(T->rchild,NewT->rchild);
    }else{
        NewT=NULL;
        exit;
    }
}


//5.5计算二叉树的深度
int Depth(BiTree &T){           //把每次递归都视为一个根节点
    int ldep,rdep,max;
    if(T!=NULL){            //如果不为null就对这个结点的左右子树进行查找
        ldep=Depth(T->lchild);//左子树深度
        rdep=Depth(T->rchild);//右子树深度
        max=ldep>rdep?ldep:rdep;
        return max+1;           //返回的是在这个结点左右子树的最深深度，如果为叶子则深度为1
    }else{
        return 0;
    }
}

//计算两个二叉数是否相等
int isequal(BiTree t1,BiTree t2){
    

}
//5.6统计二叉树中结点的个数
int NodeCount(BiTree T){
    if(T!=NULL){
        int LCount,RCount;
        
        LCount=NodeCount(T->lchild);
        RCount=NodeCount(T->rchild);
        return LCount+RCount;
    }else{
        return 0;
    }
}

