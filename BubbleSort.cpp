/*
 * @Description: 冒泡排序
 * @Author: Ialboon
 * @Date: 2020-09-22 16:16:49
 * @LastEditTime: 2020-09-22 16:18:43
 * @LastEditors: Ialboon
 */
#include<iostream>
#include "SqList.cpp"
//升序
//简单选择排序
template<class T>
void SelectSort(SqList<T> *L){
    int i,j,min;
    for(i=1;i<L->length;i++){
        min=i;
        for(j=i+1;j<=L->length;j++)
            if(L->r[min]>L->r[j])
                min=j;
        if(i!=min)
            swap(L,i,min);
    }
}