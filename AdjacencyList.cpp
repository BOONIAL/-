/*
 * @Description: 邻接表存储图
 * @Author: Ialboon
 * @Date: 2020-08-27 09:28:23
 * @LastEditTime: 2020-08-28 14:16:25
 * @LastEditors: Ialboon
 */
#include<iostream>
using namespace std;

//边表节点,存储图的位置信息
class EdgeNode{
public:
    int adjvex;//储存顶点对应的下标
    EdgeNode *next;//下一个节点
    //EdgeNode():next(NULL){};
};

//顶点表节点
template<class T>
class VertexNode{
public:
    T data;
    EdgeNode *firstedge;
};

//邻接表的信息
template<class T>
class AdjList{
public:
    VertexNode<T> *adjlist;
    int numNode,numEdge;//节点数和边数
    void init(){
        adjlist=new VertexNode<T>[numNode];
    }
};

//无向图创建领接表
template<class T>
void CreateALGraph(AdjList<T> *G){
    int i,j,k;
    EdgeNode *e;
    
    //读入顶点数和边数
    cin>>G->numNode>>G->numEdge;

    G->init();
    //读入顶点信息
    for(i=0;i<G->numNode;i++){
        cin>>G->adjlist[i].data;
        G->adjlist[i].firstedge=NULL;
    }
    
    //建立边表
    for(k=0;k<G->numEdge;k++){
        //获得一条边的两个点
        cin>>i>>j;

        //尾插法,i->j
        e=new EdgeNode;
        //存对应的节点下标
        e->adjvex=j;
        e->next=G->adjlist[i].firstedge;
        G->adjlist[i].firstedge=e;
        
        //j->i
        e=new EdgeNode;
        //存对应的节点下标
        e->adjvex=i;
        e->next=G->adjlist[j].firstedge;
        G->adjlist[j].firstedge=e;
    }
}
