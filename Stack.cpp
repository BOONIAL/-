/*
 * @Description: 
 * @Author: Ialboon
 * @Date: 2020-08-15 19:20:31
 * @LastEditTime: 2020-08-15 20:23:22
 * @LastEditors: Ialboon
 */
#include<iostream>
#include<vector>
using namespace std;

template <class T>
class Stack{
private:
    vector<T> elems;
public:
    void push(T const&);//入栈
    void pop();//出栈
    T top() const;//返回栈顶元素
    bool empty() const{//如果为空返回真
        return elems.empty();
    }
};

template <class T>
void Stack<T>::push(T const& elem){
    elems.push_back(elem);
}

template <class T>
void Stack<T>::pop(){
    if(elems.empty()){
        return;
    }
    elems.pop_back();
}

template <class T>
T Stack<T>::top() const{
    if(elems.empty()){
        exit(0);
    }
    return elems.back();
}

int main(){
    Stack<int> intStack;
    for(int i=1;i<=100;i++){
        intStack.push(i);
    }
    cout<<intStack.top()<<" "<<intStack.empty()<<endl;

}