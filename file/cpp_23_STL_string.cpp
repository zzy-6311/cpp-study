#include<iostream>
using namespace std;
#include <string>

//string在c语言里面就是个数组，本质是一个char *，但是在cpp里面并不是，string是一个类
//既然是一个类就有很多不一样的构造方法

void test1(){
    string s1 = "hello world";//最常见的初始化构造方式
    cout << s1 << endl;

    const char * str = "hello world";
    string s2(str);//c语言的形式的类构造，传入字符的数组
    cout << s2 << endl;

    string s3(s2);//类的拷贝构造，传入s2让s3深拷贝构造
    cout << s3 << endl;

    string s4(10, 'a');//注意这里不是“”因为双引号在cpp里面是当成末尾加\0的，会变成字符串
    cout << s4 << endl;
}

int main(){
    test1();
}