/*
 * @Description: 拓扑排序解决一个工程是否进行
 * @Author: Ialboon
 * @Date: 2020-09-04 21:34:37
 * @LastEditTime: 2020-09-05 16:37:22
 * @LastEditors: Ialboon
 */

#include<iostream>
#include<stack>
//#include "AdjacencyList.cpp"
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
    int in;
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
        cin>>G->adjlist[i].data>>G->adjlist[i].in;
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

template<class T>
bool TopologicalSort(AdjList<T> *GL){
    EdgeNode *e;
    int i,k,gettop;
    int count=0;
    //用栈存储入度为0的下标
    stack<int> sta;
    //将入度为0的下标入栈
    for(i=0;i<GL->numNode;i++)
        if(GL->adjlist[i].in==0)
            sta.push(i);
    while (!sta.empty())
    {
        cout<<GL->adjlist[sta.top()].data<<"->";
        e=GL->adjlist[sta.top()].firstedge;
        sta.pop();
        count++;
        //对此顶点弧表遍历
        for(;e;e=e->next){
            k=e->adjvex;
            //入度-1,如果入度为0进栈
            if(!(--(GL->adjlist[k].in)))
                sta.push(k);
        }
    }
    //如果出点小于顶点，则存在环
    if(count<GL->numNode)
        return false;
    else
        return true;
}

int main(){
    AdjList<int> *GL=new AdjList<int>;
    CreateALGraph(GL);
    TopologicalSort(GL);
}