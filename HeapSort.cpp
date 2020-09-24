/*
 * @Description: 堆排序 0(nlogn)
 * @Author: Ialboon
 * @Date: 2020-09-23 10:57:54
 * @LastEditTime: 2020-09-24 18:28:52
 * @LastEditors: Ialboon
 */
#include<iostream>
#include "SqList.cpp"

//已知L->r[s..m]中记录的关键字除L->r[s]之外均满足堆的定义
//本函数调整L->r[s]的关键字，使L->r[s..m]成为一个大顶堆
template<class T>
void HeapAdjust(SqList<T> *L,int s,int m){
    int temp,j;
    temp=L->r[s];
    //沿关键字较大的孩子结点向下筛选
    for(j=2*s;j<=m;j*=2){
        if(j<m&&L->r[j]<L->r[j+1])
            ++j;//j为关键字中较大的记录的下标
        if(temp>=L->r[j])
            break;//rc因插入在位置s上
        L->r[s]=L->r[j];
        s=j;
    }
    L->r[s]=temp;//插入
}

template<class T>
void HeapSort(SqList<T> *L){
    int i;
    for(i=L->length/2;i>0;i--)//把L中的r构建成一个大顶堆
        HeapAdjust(L,i,L->length);
    for(i=L->length;i>1;i--){
        swap(L,1,i);//将堆顶记录和当前未经排序子序列的最后一个记录交换
        HeapAdjust(L,1,i-1);//将L->r[1..i-1]重新调整未大顶堆
    }
}

int main(){
    SqList<int> *sq;
    sq->length=9;
    sq->r=new int [10]{0,9,1,5,8,3,7,4,6,2};
    HeapSort(sq);
    for(int i=1;i<=sq->length;i++){
        cout<<sq->r[i]<<" ";
    }
}