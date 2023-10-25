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

//学生表
// typedef struct {
//     char num[8];
//     char name[8];
//     int score;
// }ElemType;

//一般linklist指向头结点
typedef struct Lnode{
   ElemType  data;
    struct Lnode *next; 
}LNode,*LinkList;       //linklist是一个指向lnode的 指针数据类型  struct *LNode ok 反正就是一个数据类型，指向lnode的指针

//单链表的初始化,生成新结点作为头结点，用头指针L指向头结点
Status InitList_L(LinkList &L){
    L= new Lnode;    //L=(LinkList)malloc(sizeof(Lnode))   L是头指针，指向头结点，结点内的next为null
    L->next=NULL;
    return OK;
}

//判断链表是否为空
int ListEmpty(LinkList L){
    if(L->next){
        return 0;
    }
    else return 1;
}

//销毁单链表L，L为头指针
Status DestoryList_L(LinkList &L){
   LinkList p;
   while(L!=NULL){
    p=L;
    L=L->next;
    delete p;
   }
   return OK;
}


//清空单链表，链表存在但表中无元素，头指针和头结点仍然存在
Status ClearList(LinkList &L){
   LinkList p,q; 
   p=L->next;       //指向头结点
    while(p!=NULL){
       q=p->next;   //q指向首元结点    //这一句不能放在后面，因为de掉了会报错
        delete p;
        p=q;
    }
    L->next=NULL;
    return OK;
}

//求链表的表长，传入为头结点指针，则L->为首元结点
Status ListLength_L(LinkList L){
  LinkList p;           
  int i=0;
  p=L->next;        //指向首元结点
  while(p!=NULL){
    i++;
    p=p->next;
  }
  return i;
}

// 取值(第i个元素的值，用e返回)             ??操作5
Status GetElem_L(LinkList L,int i,ElemType &e){
   LinkList p =L->next;    //首元结点
    int j=1;
    return j;
}


/**查找
 * 按值查找：根据指定数据获取该数据所在的位置（返回地址）
 * 按值查找：根据指定位置数据获取该数据所在的位置序号（是第几个数据元素）
 * 
*/
Lnode *LocateElem_L(LinkList L,ElemType e){  //查找值为e的元素，找到则返回L中值为e的元素的地址，失败则返回NULL
    LinkList p=L->next;
    while(e!=p->data && p!=NULL){
        p=p->next;
    } 
     return p;
}

int LocateElem_L1(LinkList L,ElemType e){
    LinkList p=L->next;
    int j=1;
    while(p->data!=e&&p!=NULL){
        j++;
        p=p->next;
    }
   if(p!=NULL)
    {
        return j;
    }
    else return 0;
}

//插入在第i个结点前插入值为e的新结点
Status Insert_L(LinkList &L,int i,ElemType e){
    LinkList p=L->next;
    int j=1;
    while(j!=i-1&&p!=NULL){
        j++;
        p=p->next;
    }

    if(p==NULL||j>i-1){     //i大于表长+1，或者小于1，插入位置非法       ??
        return ERROR;
    }  
    
   LinkList s =new LNode;
    s->data=e;
    p->next=s->next;
    p->next=s;
    return OK;

}

//删除第i个结点的元素   10
int delete_L(LinkList &L,int i){
    LinkList p,q;
    int j=1;
    p=L->next;

    while(p!=NULL&&j<i){    //先找到结点i前面那个结点
        p=p->next;
        j++;
    }

    if(p==NULL||i<1){      //如果找到的结点是空结点
        return ERROR;
    }

    q=p->next;          
    p->next=q->next;
    delete q;
    return OK;
}

/**
 * 头插法，元素插入在链表头部，叫前插法    
 * a b c d e
 * 逆位输入n个元素的值
*/
void CreateList_H(LinkList &L,int n){  
    L=new Lnode;   
    L->next=NULL;   //先建立带头结点的空链表，头指针为L，L为头结点，L->next为首元结点

    for(int i=0;i<n;i++){
        LinkList p=new Lnode;
        cin>>p->data;
        p->next=L->next;        //？？
        L->next=p;
    }
}


//尾插法                            ??  引用传递，为什么要L=new Lnode
void CerateList_R(LinkList &L,int n){
    //正位序输入n个元素的值，建立带表头结点的单链表L   
    int i;
    L=new Lnode;
    L->next=NULL;   //头结点
    LinkList r=L;
    for(i=0;i<n;i++){
       LinkList p=new Lnode;
        cin>>p->data;
        r->next=p;
        r=p;
    }
}



