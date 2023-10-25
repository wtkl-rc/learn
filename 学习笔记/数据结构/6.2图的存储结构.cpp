#include <iostream>
#include <string.h>
using namespace std;
/**
 *在图中元素称为顶点 
 *
 * 1.图的定义:
 * 
 * 无向边：顶点v1到v2没有方向，则称为无向边。如果任意顶点都是无向边，的则成为无向图。
 * g1=（v1,{e1}）顶点集合：v1，边集合：e1   用无序偶对（vi，vj）表示
 * 
 * 有向边：若从顶点vi到vj有方向，则称这条边为有向边，也称为弧。用有序偶对<vi,vj>表示，vi称为弧尾，vj称为弧头
 * 同理有称为向图
 * 
 * 简单图：
 * 若不存在顶点到其自身的边，且同一条边是不重复出现，则称这样的图为简单图
 * 
 *无向完全图：
 在无向图中，任意两点之间都存在边，则成为无向完全图
 * 
 * 含有n个顶点的无向完全图有   n*（n-1）/2条边
 * 
 * 有向完全图：
 * 任意两个顶点之间都存在方向护为相反的两条弧
 * n个顶点有n*（n-1）条边
 * 
 * 对于具有n个顶点和e条边数的图，无向图0<=e<=n,有向图0<=e<=n(n-1)
 * 
 * 有很少条边的或弧的称为稀疏图，反之称为稠密图
 * 
 * 与图的边或弧相关的数称为权，带权的图称为网
 * 
 * 子图懂？
 * 
 * 
 * 2.图的顶点和边间的关系
 * 
 * 
 * 3.连通图的相关术语
 * 在无向图中，如果v到顶点v’有路径，则称v和v’是连通的
 * 如果对于图中的任意两个顶点都是都是连通的，则称g是连通图
 * 
 * 连通分量：           //？？
 * 无向图中的极大连通子图称为连通分量
 * 强调：
 * 要是子图，子图要是连通的，连通子图含有极大顶点数，具有极大定点数的连通子图    //？？220
 * 
 * 
*/


/**
 * 6.2.1
 * 邻接矩阵
 * 无权图用1，0.  有权图用无限和权值
 * 
 * MGraph是一个图的整体定义，adj是邻接矩阵的定义
 * 所以一张图对应一个mgraph里面包含着adj
*/
typedef struct {        //边的定义
    int adj;        //int顶点关系类型
    //对无权图，用0或1表示是否相邻
    //对带权图，则为权值类型
    int *info;  //该弧相关信息的指针
}Adj[5][5];


typedef struct{   //图的定义
    int vexs[5];  //顶点信息 
    Adj arcs;    //邻接矩阵
    int vexnum,arcnum;//顶点数，边数
    int kind;   //图的种类和标志
}MGraph;


//图的创建
int creatgraph(MGraph &G){
    //输入一个值，判断是创建什么图
    char g;
    switch (g)
    {
        case 'D':return createdg(G);    //构造有向图
        // case 'D':                    //构造有向网
        // case 'D':                    //构造无向图
        // case 'D':                    //构造无向网
    }
}

int createdg(MGraph &g){  //构造有向图
    int i,j,k,w;
    int v1,v2;
    cin>>g.vexnum;//顶点数
    cin>>g.arcnum;//输入边数

    for(i=0;i<g.vexnum;i++){  //构造顶点向量，给定点输入值
        cin>>g.vexs[i];       
    }

    for(i=0;i<g.vexnum;i++){        //初始化邻接矩阵，全部赋值为0，null
        for(j=0;j<g.vexnum;j++){
           g.arcs[i][j].adj=0;
           g.arcs[i][j].info=NULL; 
        }
    }

    for(k=0;k<g.arcnum;k++){//构造邻接矩阵  循环次数为边的数量
        //在二维数组中输入v1和v2，定位点。w表示这个点的值，1，0。
        //w就是权值呗就是两个顶点之间的关系，0就是不相邻
        cin>>v1>>v2>>w; 
        
        i=LocateVex(g,v1);          
        j=LocateVex(g,v2);

        g.arcs[i][j].adj=w;         //弧<v1,v2>的权值
        g.arcs[j][i].adj=g.arcs[i][j].adj;//置<v1,v2>的对称弧<v2,v1>
    }
}   



//6-4顶点定位算法
int LocateVex(MGraph G,int &v){   //用于判断顶点在二维数组中的位置
    int i;
    for(i=0;i<G.vexnum;i++){       //通过对顶点一维数组的查找
        if(G.vexs[i]==v){
            return i;
        }
    }
    return -1;
}                            



/** 6-5查找第一个邻接点的算法
 * 就是在二维数组中第一个邻接点
*/
int findfirst(MGraph G,int v){
    if(v<0||v>G.vexnum){         
        return -1;
    }
    for(int i;i<G.vexnum;i++){              //这里的100是指无限，如果小于无限也成立
        if(G.arcs[v][i].adj!=0&&G.arcs[v][i].adj<100){
            return i;
        }
    }
    return -1;
}


//6-6查找下一个邻接点的算法
//就是查找下一个邻接表咯
int nextadjvex(MGraph G,int v,int w){   //已经知道了一个顶点v和一个邻接点w
   if(v<0||v>=G.vexnum){
        return -1;
   }
   for(int i=w+1;i<G.vexnum;i++){         //我也不知道为什么w+1实际问题实际分析
        if(G.arcs[v][i].adj!=0&&G.arcs[v][i].adj<100){
           return i; 
        }
   }
   return -1;
}



