/*
 * @Description: 选择排序
 * @Author: Ialboon
 * @Date: 2020-09-22 16:16:49
 * @LastEditTime: 2020-09-22 16:18:28
 * @LastEditors: Ialboon
 */
#include<iostream>
#include "SqList.cpp"
//升序
template <class T> 
void BubbleSort(SqList<T> *L){
    int i,j;
    bool flag=true;
    //如果遍历了一遍发现没有交换，则不需要继续遍历
    //每次循环找到位置i的最优数字
    for (i=1;i<L->length && flag;i++){
        flag=false;
        for(j=L->length-1;j>=i;j--){
            if(L->r[j]>L->r[j+1]){
                swap(L,j,j+1);
                flag=true;//发生了交换
            }
        }
    }
}