#include<iostream>

//栈区由系统控制系统清理（所以局部变量这种用完就销毁的内存不要返回其中变量的地址，是错误的）
//堆区由程序员控制，只在程序结束的时候清理，使用new创建（new int），使用delete删除（delete x）
//new函数返还的都是指针，int * p = new int(10)//在堆区的一个数字10

int g_a = 10;
int g_b = 10;//全局的变量都在全局区，还包括全局变量，静态变量，常量

int* aaa(void){
    int *p = new int(10);
    return p;
}

int* bbb(void){
    int *q = new int[10];//代表有10个元素的数组
    return q;
}

int main(void){
    int a = 10;
    int b = 10;//局部的变量都在局部区

    std::cout << &a << std::endl;
    std::cout << &b << std::endl;
    std::cout << &g_a << std::endl;
    std::cout << &g_b << std::endl;

    int *p = aaa();

    std::cout << *p << std::endl;
    delete p;

    int *q = bbb();//数组的反常识，记一下
    for (int i = 0; i < 10; i++){
        q[i] = i;
    }
    std::cout << q[5] << std::endl;
    delete[] q;
}