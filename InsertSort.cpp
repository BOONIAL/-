/*
 * @Description: 选择排序
 * @Author: Ialboon
 * @Date: 2020-09-22 16:16:49
 * @LastEditTime: 2020-09-22 16:19:32
 * @LastEditors: Ialboon
 */
#include<iostream>
#include "SqList.cpp"
//直接插入排序,升序O(n^2)
template<class T>
void InsertSort(SqList<T> *L){
    int i,j,min;
    for(i=2;i<=L->length;i++){
        if(L->r[i-1]>L->r[i]){
            L->r[0]=L->r[i];//设置哨兵
            for(j=i-1;L->r[j]>L->r[0];j--)
                L->r[j+1]=L->r[j];//记录后移
            L->r[j+1]=L->r[0];//插入到正确位置
        }
    }
}