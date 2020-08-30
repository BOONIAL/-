/*
 * @Description: 以边为中心构建最小生成树---Kruskal算法
 * @Author: Ialboon
 * @Date: 2020-08-30 14:53:19
 * @LastEditTime: 2020-08-30 17:03:24
 * @LastEditors: Ialboon
 */
#include<iostream>
#include<algorithm>
#include "AdjacencyMatrix.cpp"
using namespace std;

class Edge{
public:
    int begin,end,weight;
};

bool cmp(Edge a,Edge b)
{
    if(a.weight==b.weight) return a.begin<b.begin;
    return a.weight<b.weight;//返回bool值，按权升序排列
}

//MGraph转换成Edge
void trans(Edge *edges,MGraph *G){
    int cnt=0;
    for(int i=0;i<G->numNodes;i++){
        //保持i>j
        for(int j=0;j<i;j++){
            if(G->arc[i][j]!=INFINITY){
                edges[cnt].begin=j;
                edges[cnt].end=i;
                edges[cnt].weight=G->arc[i][j];
                cnt++;
            }  
        }
    }
}

//找到连线顶点的尾部下标
int Find(int *parent,int f){
    while (parent[f]>0)
        f=parent[f];
    return f;
}

void MiniSpanTree_Kruskal(MGraph *G){
    int i,n,m;
    Edge edges[G->numEdges];
    //MGraph转换成Edge
    trans(edges,G);
    //升序排列
    sort(edges,edges+G->numEdges,cmp);
    //判断边与边是否形成环路
    int parent[G->numNodes];
    //初始化
    for(i=0;i<G->numNodes;i++)
        parent[i]=0;
    //循环每一条边
    for(i=0;i<G->numEdges;i++){
        n=Find(parent,edges[i].begin);
        m=Find(parent,edges[i].end);
        //n!=m表明还没有形成环路
        if(n!=m){
            //此顶点n已在生成树中
            parent[n]=m;
            printf("(%d,%d)=%d ",edges[i].begin,edges[i].end,edges[i].weight);
        }
    }
}

int main(){
    MGraph *G=new MGraph;
    CreateMGraph(G);
    MiniSpanTree_Kruskal(G);
}