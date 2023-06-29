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

//可以用malloc=开辟空间也可以用数组开辟空间

//顺序表达的存储结构
typedef struct {
    ElemType *elem;
    int Length;
}SqList;


//初始化
Status InitList_Sq(SqList &L){        //引用传递
    L.elem= new ElemType[MAXSIZE];
    if(!L.elem)exit(OVERLOW);
    L.Length=0;
    return OK;
}

//销毁线性表
void DestoryList(SqList &L){
if(!L.elem)delete L.elem;
} 

//清空线性表
void ClearList(SqList &L){
    if(!L.elem)
    {
        L.Length=0;  //将线性表长度置为零
    }
}

//求线性表的长度
int GetLength(SqList L){
    return (L.Length);
}

//判断线性表是否为空
int IsEmpty(SqList L){
    if(L.Length==0)
    {
        return 0;
    }
    else return 1;
}

//线性表取值(根据位置i获取相应的值)
int GetElem(SqList L,ElemType &e,int i){

    if(i<1||i>L.Length){
        return ERROR;
    }
    e=L.elem[i-1];
    return OK;
}

//查找 o(n)
int LocateElem(SqList L,ElemType e){
    for(int i=0;i<L.Length;i++){
        if(L.elem[i]==e)
        {
            return i+1;
        }
    }
    return ERROR;
}

//插入 第i个位置插入元素e O（n）
Status ListInsert_Sq(SqList &L,int i,ElemType e)
{
    if(i<1||i>L.Length+1)
    {
        return ERROR;
    }
    if(L.Length==MAXSIZE)
    {
        return ERROR;
    }
    for(int j=L.Length-1;j>=i-1;j--)
    {
        L.elem[j+1]=L.elem[j];
        L.elem[i-1]=e;
        L.Length++;
        return OK;
    }
}

//删除 将表的第i个结点删除o(n)
Status ListDelete(SqList &L,int i,ElemType &e){
   
    if(i<1||i > L.Length)
    {
        return ERROR;
    }

    for(int j=i;j<=L.Length-1;j++){
        L.elem[j-1]=L.elem[j];
    }

    L.Length--;
    return OK;
}