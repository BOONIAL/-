/*
 * @Description: 关键路径求解决工程完成需要的最短时间问题
 * etv:顶点的最早发生时间
 * ltv:顶点的最晚发生时间，超出此时间将会延误整个工期
 * ete:弧最早发生时间
 * lte:弧最晚发生时间，不推迟工期的最晚开工时间
 * @Author: Ialboon
 * @Date: 2020-09-05 16:20:42
 * @LastEditTime: 2020-09-06 10:03:27
 * @LastEditors: Ialboon
 */

#include<iostream>
#include<stack>
using namespace std;

//事件最早和最晚发生时间数组
int *etv,*ltv;
//存储拓扑序列的栈
stack<int> stac;

class EdgeNode{
public:
    //权重
    int adjvex;
    int weight;
    EdgeNode *next;
};

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
    int i,j,k,temp;
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
        cin>>i>>j>>temp;

        //尾插法,i->j
        e=new EdgeNode;
        //存对应的节点下标
        e->adjvex=j;
        e->weight=temp;
        e->next=G->adjlist[i].firstedge;
        G->adjlist[i].firstedge=e;
    }
}

//改装拓扑排序，求
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
    //初始化
    etv=new int[GL->numNode];
    for(i=0;i<GL->numNode;i++)
        etv[i]=0;
    while (!sta.empty())
    {
        //将弹出的顶点序号压入拓扑序列的栈
        gettop=sta.top();
        stac.push(gettop);
        
        e=GL->adjlist[gettop].firstedge;
        sta.pop();
        count++;
        //对此顶点弧表遍历
        for(;e;e=e->next){
            k=e->adjvex;
            //入度-1,如果入度为0进栈
            if(!(--(GL->adjlist[k].in)))
                sta.push(k);
            //求各顶点最早发生时间值，在此之前前置工程未完成
            if((etv[gettop]+e->weight)>etv[k])
                //栈顶etv+节点权重
                etv[k]=etv[gettop]+e->weight;
        }
    }
    //如果出点小于顶点，则存在环
    if(count<GL->numNode)
        return false;
    else
        return true;
}

template<class T>
void CriticalPath(AdjList<T> *GL){
    EdgeNode *e;
    int i,gettop,k,j;
    //声明活动最早发生时间和最迟发生时间变量
    int ete,lte;
    //求拓扑序列，计算数组etv和stac的值
    TopologicalSort(GL);
    //初始化
    ltv=new int[GL->numNode];
    for(i=0;i<GL->numNode;i++)
        ltv[i]=etv[GL->numNode-1];
    while (!stac.empty())
    {
        gettop=stac.top();
        stac.pop();
        for(e=GL->adjlist[gettop].firstedge;e;e=e->next){
            //求各顶点事件的最迟发生时间ltv值
            k=e->adjvex;
            //求各顶点时间最晚发生时间ltv
            if(ltv[k]-e->weight<ltv[gettop])
                //如果在推迟，则赶不上某个节点
                ltv[gettop]=ltv[k]-e->weight;
        }
    }
    //求ete、lte和关键活动
    for(j=0;j<GL->numNode;j++){
        for(e=GL->adjlist[j].firstedge;e;e=e->next){
            k=e->adjvex;
            //活动最早发生时间，弧尾事件发生才开始
            ete=etv[j];
            //在下一个节点开始前必须做完
            lte=ltv[k]-e->weight;
            //两者相等即在关键路径上，即没有多余时间
            if(ete==lte){
                printf("<v%d,v%d>=%d ",GL->adjlist[j].data,GL->adjlist[k].data,e->weight);
            }
        }
    }
}

int main(){
    AdjList<int> *GL=new AdjList<int>;
    CreateALGraph(GL);
    CriticalPath(GL);
}