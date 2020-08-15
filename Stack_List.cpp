/*
 * @Description: 用链式结构实现栈
 * @Author: Ialboon
 * @Date: 2020-08-15 20:48:22
 * @LastEditTime: 2020-08-15 22:27:30
 * @LastEditors: Ialboon
 */
#include<iostream>
using namespace std;

template <class T>
class Stack_Node{//节点
private:
    T elem;
public:
    Stack_Node *next;
    Stack_Node(T eelem):elem(eelem),next(NULL){};
    T show(){return elem;};
};

template <class T>
class Stack_List{//链式结构
private:
    Stack_Node<T> *top;
public:
    Stack_List(Stack_Node<T> *ttop):top(ttop){};
    void push(T const& temp);
    void pop();
    T Top();
    bool empty(){
        if(top==NULL)
            return true;
        return false;
    };
};

template <class T>
void Stack_List<T>::push(T const& temp){
    Stack_Node<T> *s=new Stack_Node<T>(temp);
    s->next=top;//后来居上
    top=s;
}

template <class T>
void Stack_List<T>::pop(){
    if(empty())
        exit(0);
    Stack_Node<T> *p;
    p=top;
    top=top->next;
    delete(p);
}

template <class T>
T Stack_List<T>::Top(){
    if(empty()){
        exit(0);
    }
    return top->show();
}

int main(){
    Stack_Node<int> p(1);
    Stack_List<int> sl(&p);
    for(int i=2;i<=10;i++){
        sl.push(i);
    }
    cout<<sl.Top()<<endl;
    sl.pop();
    cout<<sl.Top()<<endl;
    cout<<sl.empty()<<endl;
}