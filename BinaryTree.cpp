/*
 * @Description: 二叉树遍历
 * @Author: Ialboon
 * @Date: 2020-08-21 20:44:54
 * @LastEditTime: 2020-08-21 21:23:39
 * @LastEditors: Ialboon
 */
#include<iostream>
using namespace std;

template <class T>
class BitNode{
public:
    T data;
    BitNode *lchild;
    BitNode *rchild;
    BitNode(T ddata):data(ddata),lchild(NULL),rchild(NULL){};
    BitNode():data(0),lchild(NULL),rchild(NULL){};
};

//先序遍历
template <class T>
void PreOrderTraverse(BitNode <T> *t){
    if(t==NULL)
        return;
    cout<<t->data<<endl;
    PreOrderTraverse(t->lchild);
    PreOrderTraverse(t->rchild);
}

//中序遍历
template <class T>
void InOrderTraverse(BitNode <T> *t){
    if(t==NULL)
        return;
    InOrderTraverse(t->lchild);
    cout<<t->data<<endl;
    InOrderTraverse(t->rchild);
}

//后序遍历
template <class T>
void PostOrderTraverse(BitNode <T> *t){
    if(t==NULL)
        return;
    PostOrderTraverse(t->lchild);
    PostOrderTraverse(t->rchild);
    cout<<t->data<<endl;
}
