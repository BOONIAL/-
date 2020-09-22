/*
 * @Description: 排序用到的结构和冒泡排序、简单选择排序
 * @Author: Ialboon
 * @Date: 2020-09-21 08:58:18
 * @LastEditTime: 2020-09-22 16:20:01
 * @LastEditors: Ialboon
 */
#include<iostream>
using namespace std;
template <class T>
//r[0]作哨兵元素
class SqList{
public:
    T *r;
    int length;
};

template<class T>
void swap(SqList<T> *L, int x, int y){
    T temp;
    temp=L->r[x];
    L->r[x]=L->r[y];
    L->r[y]=temp;
}
