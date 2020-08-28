/*
 * @Description: 邻接表的BFS
 * @Author: Ialboon
 * @Date: 2020-08-28 14:39:04
 * @LastEditTime: 2020-08-28 15:04:29
 * @LastEditors: Ialboon
 */
#include<iostream>
#include<queue>
#include "AdjacencyList.cpp"
using namespace std;

template <class T>
void BFSTraverse(AdjList<T> *G){
    int i,k;
    EdgeNode *p;
    queue<int>que;
    int visited[50];
    for(i=0;i<G->numNode;i++){
        for(k=0;k<G->numNode;k++)
            visited[k]=0;
        if(!visited[i]){
            visited[i]=1;
            cout<<G->adjlist[i].data<<" ";
            que.push(i);
            while(!que.empty()){
                que.pop();
                p=G->adjlist[i].firstedge;
                while(p){
                    if(!visited[p->adjvex]){
                        visited[p->adjvex]=1;
                        cout<<G->adjlist[p->adjvex].data<<" ";
                        que.push(p->adjvex);
                    }   
                    p=p->next;
                }
            }
        }
    }
}

int main(){
    AdjList<int> *adj=new AdjList<int>;
    CreateALGraph(adj);
    BFSTraverse(adj);
}
