#include <iostream>
using namespace std;

const int  TRUE =1;
const int  FALSE= 0;
const int  OK =1;
const int  ERROR= 0;
const int  INFEASIBLE=-1;
const int OVERLOW = -2;
const int MAXSIZE = 100;

typedef char ElemType;
typedef int Status;

typedef struct {
    ElemType data;          //数据域
   struct DuLnode *prior;      //前驱
    struct DuLnode *next;      //??为什么要用struct 不直接用DULISt
}*DuLinkList,DuLnode;      //??为什么*就是指针


/**
 * 在带头结点的双向链表L中第i个位置之前 插入元素e
*/
Status ListInsert_DuL(DuLinkList &L,int i,ElemType e){
    //判断
    //找到i之前的结点
    int j=1;
    DuLinkList p=L->next;
    while(j<i){

    }
    
    //新建结点，连接
    DuLinkList p=new DuLnode;  //??为什么

    cin>>p->data;
    p->next=;


}


//删除




