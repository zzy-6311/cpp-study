#include<iostream>

void abc();

int a = 20;
//extern还可以跨文件引用变量，但是不分配内存只引用

int main(void){
    std::cout << a << std::endl;

    int a = 10;

    std::cout << a << std::endl;

    abc();

    return 0;
}

void abc(){
    std::cout << a << std::endl;
}