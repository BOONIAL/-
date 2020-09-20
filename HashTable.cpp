/*
 * @Description: hash表的查找实现
 * @Author: Ialboon
 * @Date: 2020-09-20 08:25:48
 * @LastEditTime: 2020-09-20 09:29:47
 * @LastEditors: Ialboon
 */
#include<iostream>
using namespace std;

const int SUCCESS=1;
const int UNSUCCESS=0;
const int HASHSIZE=12;
const int NULLKEY=-32768;

template <class T>
class HashTable{
public:
    int *elem;//数据元素存储基址，动态分配数组
    int cnt;//当前数据元素个数  
};

int m=0;//散列表表长，全局变量

//初始化散列表
template <class T>
bool InitHashTable(HashTable<T> *H){
    int i;
    m=HASHSIZE;
    H->cnt=m;
    H->elem=new T[m];
    for(i=0;i<m;i++)
        H->elem[i]=NULLKEY;
    return true;
}

//散列函数
int Hash(int key){
    return key%m;//除留余数法
}

//插入关键字进散列表
template<class T>
void InsertHash(HashTable<T> *H,int key){
    int addr=Hash(key);//求散列地址
    while(H->elem[addr]!=NULLKEY)//如果不为空，则冲突
        addr=(addr+1)%m;//开放地址法的线性原则
    H->elem[addr]=key;//直到有空位后插入关键字
}

//散列表查找关键字
template<class T>
bool SearchHash(HashTable<T> *H,int key,int addr){
    addr=Hash(key);//求散列地址
    while(H->elem[addr]!=key){//如果不为空则冲突
        addr=(addr+1)%m;//开放定址法的线性探测
        if(H->elem[addr]==NULLKEY||addr==Hash(key))
            //如果循环回原点
            return UNSUCCESS;//关键字不存在
    }
    cout<<"H.elem["<<addr<<"]="<<H->elem[addr]<<endl;
    return SUCCESS;
}

int main(){
    HashTable<int> *ht;
    InitHashTable(ht);
    for(int i=0;i<HASHSIZE;i++)
        InsertHash(ht,i*i);
    SearchHash(ht,100,0);
}