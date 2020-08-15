/*
 * @Description: 单向链表的查改增删
 * @Author: Ialboon
 * @Date: 2020-08-09 21:45:09
 * @LastEditTime: 2020-08-10 16:22:53
 * @LastEditors: Ialboon
 */

#include<iostream>
#include<fstream>
using namespace std;

int len;
class Employee{
private:
    int id;
    string name;
public:
    Employee *next;
    Employee():id(999),name("asd"),next(NULL){};
    Employee(int iid,string nname):id(iid),name(nname),next(NULL){};
    int getid(){
        return id;
    }
    string getstring(){
        return name;
    }
};

Employee *GetElem(Employee *emp);//查询
void ListInsert(Employee *emp,int i,Employee &nemp);//在第i个元素后插入
void ListDelete(Employee *emp,int i);//删除第i+1个元素
void CreateListTail(Employee *emp,int n);//尾插法创建n+1个元素
void ClearList(Employee *emp);//删除整个链表


int main(){
    len=1;
    Employee *p=new Employee(1,"zxc");//头节点
    //查
    cout<<GetElem(p)->getstring()<<endl;
    
    //增
    CreateListTail(p,5);
    cout<<p->next->getid()<<endl;

    //插
    Employee *pp=new Employee(2,"dfh");
    ListInsert(p,1,*pp);
    cout<<p->next->getid()<<endl;

    //删
    ListDelete(p,1);
    cout<<p->next->getid()<<endl;

    //以写模式打开文件
    Employee *temp=p;
    ofstream outfile;
    outfile.open("data.txt");
    for(int j=1;j<=len;j++){
        outfile<<temp->getid()<<" "<<temp->getstring()<<endl;//写入文件
        temp=temp->next;
    }
    //清
    ClearList(p);
}

Employee *GetElem(Employee *emp){
    int j;
    Employee *p;
    p=emp;
    j=1;//计数器
    while(p && j<len){
        p=p->next;
        j++;
    }
    if(!p||j>len)
        exit (0);
    return p;
};

void ListInsert(Employee *emp,int i,Employee &nemp){
    int j=1;
    Employee *p;
    p=emp;
    while(p && j<i){
        p=p->next;
        j++;
    }
    if(!p)
        return;
    nemp.next=p->next;
    p->next=&nemp;//指向内存地址
    len+=1;
    return;
}

void ListDelete(Employee *emp,int i){
    int j=1;
    Employee *p,*q;
    p=emp;
    while(p && j<i){
        p=p->next;
        j++;
    }
    if(!p->next)
        return;
    q=p->next;
    p->next=q->next;
    delete q;
    len-=1;
    return;
}

void CreateListTail(Employee *emp,int n){
    Employee *p,*r;
    int i;
    r=emp;
    for(i=0;i<n;i++){//创建新节点
        p=new Employee;
        r->next=p;
        r=p;
    }
    r->next=NULL;
    len+=n;
}

void ClearList(Employee *emp){
    Employee *p,*q;
    p=emp;
    while(p){
        q=p->next;
        delete(p);
        p=q;
    }
    len=0;
    return;
}