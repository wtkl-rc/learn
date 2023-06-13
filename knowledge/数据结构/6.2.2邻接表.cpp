#include <iostream>
using namespace std;

/**
 * 6.2.2
 * 邻接表
 * 存储结构
 * 是由一个顺序存储的顶点表和n个链式存储的边表组成的
 * 顶点表由顶点结点组成
 * 边表由边（或弧）结点组成的一个单链表
 * 
 * 表头结点是一个一维数组，然后指向边表，边表是链表
 * 
 * 十字邻接表
 * 邻接多重表
*/

//顶点结点
typedef struct VNode{
    int data;           //数据
    ArcNode* firstarc;  //指针指向弧结点
}VNode,AdjList[10];
//边或弧结点
typedef struct ArcNode{
    int adjvex;            //该边所指向的顶点的位置
    ArcNode* nextarc;   //指向下一条边的指针
    int* value;         //该边或弧的相关信息
}ArcNode;
//图
typedef struct {
    AdjList vertices;   //图关联顶点结点
    int kind;
    int vexnum,arcnum;  //arc弧 vex顶点
}ALGraph;


//6-7无向图的创建方法
int createudg(ALGraph &g){
    
    int i,j,k,IncInfo;
    ArcNode *pi, *pj;
    int  v1,v2;
    
    //输入并赋值给g.vexnum和g.arcnum

    
    //构造表头数组为null
    for(i=0;i<g.vexnum;i++){
        cin>>g.vertices[i].data;
        g.vertices[i].firstarc=NULL;  
    }

    //输入各边并构造邻接表
    for(i=0;i<g.arcnum;i++){
        cin>>v1;                //输入边的始点终点，因为是无向表，所以v1指向v2，则v2也指向v1
        cin>>v2;

        k=LocateVex(g,v1);
        j=LocateVex(g,v2);    //确定输入的v1的值在表头一维数组中的位置


        if(!(pi=new ArcNode)){                          
            exit(-1);
        }
        pi->adjvex=k;     //令这条边指向它指向的结点，也就是v1

        //头插法插入链表
        pi->nextarc=g.vertices[i].firstarc;   //让pi的nex指针指向和表头指向的一样
        g.vertices[i].firstarc=pi;             //再让表头指向pi，也就相当于插入了pi这条边

        if(!(pj=new ArcNode)){                  //因为是无向表，则在v2中也要重新再创建一遍
            exit(-1);
        }
        pj->adjvex=i;
        pj->nextarc=g.vertices[i].firstarc;
        g.vertices[j].firstarc=pj;
    }
}


int LocateVex(ALGraph G,int &v){    //判断v在表土一维数组中的位置
    int i;
    for(i=0;i<G.vexnum;i++){      
        if(G.vertices[i].data==v){
            return i;
        }
    }
    return -1;
}         


//6-8查找首个邻接点
int firstadjvex(){

}

//6-9查找下一个邻接点
int nextadjvex(){

}