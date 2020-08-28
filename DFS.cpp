/*
 * @Description: 邻接表的dfs
 * @Author: Ialboon
 * @Date: 2020-08-28 10:40:44
 * @LastEditTime: 2020-08-28 14:36:21
 * @LastEditors: Ialboon
 */
#include<iostream>
#include "AdjacencyList.cpp"
using namespace std;

//0:未访问 1:已访问
int visited[50];

template<class T>
void DFS(AdjList<T> *G, int i){
    EdgeNode *p;
    cout<<G->adjlist[i].data<<" ";
    p=G->adjlist[i].firstedge;
    while (p)
    {
       if(!visited[p->adjvex]){
           visited[p->adjvex]=1;
           DFS(G,p->adjvex);
           visited[p->adjvex]=0;
       }
       p=p->next;
    }
}

template<class T>
void DFSTraverse(AdjList<T> *G){
    int i;
    for(i=0;i<G->numNode;i++)
        visited[i]=0;
    for(i=0;i<G->numNode;i++)
        if(!visited[i])
            DFS(G,i);
}

int main(){
    AdjList<int> *adj=new AdjList<int>;
    CreateALGraph(adj);
    DFSTraverse(adj);
}