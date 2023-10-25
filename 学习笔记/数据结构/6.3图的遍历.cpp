#include <iostream>
using namespace std;

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

//链队列
struct LinkQueen{
    int daata;
    LinkQueen *next;
};

/**
 * 防止遍历过的结点再次被遍历，设置一个辅助的数组，开始值为假，遍历过后为真
 * 有两搜索方式，广度优化搜索，深度优化搜索
*/



/**
 * 广度优化搜索
 * 用队列的形式，例如结点v0入队，结点v0出队
 * 结点v1，v2入队，结点v1出队，结点v1下面的邻接点入队，以此类推
*/

//6-10广度优化搜素
void bfstraverse(ALGraph g){
    int v,u,w;
    int v1,u1,w1;
    LinkQueen q; //队列q

    int visited[10];  //标志数组

    for(v=0;v<g.vexnum;v++){
        visited[v]=0;         //置空标志数组
    }
    InitQuene(q);  //初始化队列q



    for(v=0;v<g.vexnum;v++){
        if(!visited[v]){        //v尚未被访问
            
            visited[v]=1;
            v1=getvex(g,v);     //??应该也是从头一维数组中获取值
            enqueue(q,v);       //入队

            while(!queueempty(q)){      //判断队列是否为空
                dequeue(q,u);              //队头元素出队，并置为u
                u1=getvex(g,u);


                //让出队的那个结点，将后面的结点全部入队，
                for(w=firstadjvex(g,u1);w>=0;w=nextadjvex(g,u1,getvex(g,w))){ //遍历出队的那个结点
                    
                    if(!visited[w]){                   //w为u的尚未被访问的邻接顶点，结点未被访问
                        visited[w]=1;                  //逻辑就是一共只有那么多个头结点，所以遍历一个设置一个为1
                        w1=getvex(g,w);                
                        cout<<w1;
                        enqueue(q,w);               //入队
                    }
                }
            }
        }
    }
}

//队列的初始化
void InitQuene(LinkQueen &q){

}

//队头元素出队，并置为u
void dequeue(LinkQueen &q,int u){

}

//入队
void enqueue(LinkQueen &q,int v){

}

//队列是否为空
int queueempty(LinkQueen Q){

}


//在图中查找第一个邻接点
int firstadjvex(ALGraph g,int u1){

}

//查找下一个邻接点
//已知图中的一个顶点v以及v的一个邻接点w，返回相对于w的下一个邻接点
int nextadjvex(ALGraph g,int v,int w){

}

//
int getvex(ALGraph g,int v){
 
}


/**深度优化搜索
 * 就是递归，进入一个结点，在访问下一个结点，如果没有了就跳回上一个结点
*/

/**
 * 6-11
 * 深度优化搜索
*/

void DFS(ALGraph g,int v){
    //从第v个顶点开始遍历图
    //g是图,g.vertice是顶点一维数组，
    int w,w1;
    w=getvex(g,v);         //反回第v个顶点
    
    w1=g.vertices[w].data;
    cout<<w1;

    nextadjvex();
    DFS(g,);

}

int main(){
    system("pause");
    return 0;
}