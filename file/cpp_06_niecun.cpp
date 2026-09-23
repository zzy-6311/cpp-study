#include<iostream>

int g_a = 10;
int g_b = 10;//全局的变量都在全局区，还包括全局变量，静态变量，常量

int main(void){
    int a = 10;
    int b = 10;//局部的变量都在局部区

    std::cout << &a << std::endl;
    std::cout << &b << std::endl;
    std::cout << &g_a << std::endl;
    std::cout << &g_b << std::endl;
}