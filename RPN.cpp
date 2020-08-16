/*
 * @Description: 利用后缀表达式处理四则运算 转化成后缀->运算
 * @Author: Ialboon
 * @Date: 2020-08-16 15:21:04
 * @LastEditTime: 2020-08-16 21:10:22
 * @LastEditors: Ialboon
 */
#include<iostream>
#include<stack>
#include<sstream>
#include<cstdlib>
using namespace std;

bool isNum(string str)  
{  
	stringstream sin(str);  
	double d;  
	char c;  
	if(!(sin >> d))  
	{
		/*解释： 
            sin>>t表示把sin转换成double的变量（其实对于int和float型的都会接收），
			如果转换成功，则值为非0，如果转换不成功就返回为0 
        */
		return false;
	}
	if (sin >> c) 
	{
		/*解释：
		此部分用于检测错误输入中，数字加字符串的输入形式（例如：34.f），在上面的的部分（sin>>t）
		已经接收并转换了输入的数字部分，在stringstream中相应也会把那一部分给清除，
		此时接收的是.f这部分，所以条件成立，返回false 
          */ 
		return false;
	}  
	return true;  
}

string* translate(string s,int msize);//中缀转化为后缀
int calculate(string s,int msize);//计算结果

string* translate(string s,int msize){
    int cnt=0;//数组计数
    string *str=new string[msize];//分配空间
    stack<char>sta;
    int len=s.length();
    string num="";
    for(int i=0;i<len;i++){
        if(isdigit(s[i])){
            num+=s[i];
        }
        else{
            if(num!=""){
                str[cnt]=num;
                cnt++;
                num="";
            }
            if(s[i]==')'){//清括号内的运算符
                while(sta.top()!='('){
                    str[cnt]=sta.top();
                    cnt++;
                    sta.pop();
                }
                sta.pop();
                continue;
            }
            else if( (s[i]=='+' || s[i]=='-') && !sta.empty() && (sta.top() == '*' || sta.top()=='/') ){//清栈
                while(!sta.empty()){
                    str[cnt]=sta.top();
                    cnt++;
                    sta.pop();
                }
            }
            //普通进栈操作
            sta.push(s[i]);
        }
    }
    if(num!=""){
        str[cnt]=num;
        cnt++;
    }
    while(!sta.empty()){
        str[cnt]=sta.top();
        cnt++;
        sta.pop();
    }
    return str;
}

int calculate(string s,int msize){
    string *str=translate(s,msize);
    stack<int>sta;
    int i=0;
    while(str[i]!=""){
        if(isNum(str[i])){
            sta.push(stoi(str[i]));//string -> int
        }
        else{
            if(str[i]=="+"){
                int a[2],c;
                for(int i=0;i<2;i++){
                    a[i]=sta.top();
                    sta.pop();
                }
                c=a[0]+a[1];
                sta.push(c);
            }
            if(str[i]=="-"){
                int a[2],c;
                for(int i=0;i<2;i++){
                    a[i]=sta.top();
                    sta.pop();
                }
                c=a[1]-a[0];
                sta.push(c);
            }
            if(str[i]=="*"){
                int a[2],c;
                for(int i=0;i<2;i++){
                    a[i]=sta.top();
                    sta.pop();
                }
                c=a[0]*a[1];
                sta.push(c);
            }
            if(str[i]=="/"){
                int a[2],c;
                for(int i=0;i<2;i++){
                    a[i]=sta.top();
                    sta.pop();
                }
                c=a[1]/a[0];
                sta.push(c);
            }
        }
        i++;
    }
    return sta.top();
}
int main(){
    string temp={"9+(3-1)*3+10/2"};
    cout<<calculate(temp,temp.length())<<endl;
}
