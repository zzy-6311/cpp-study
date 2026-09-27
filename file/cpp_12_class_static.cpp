#include<iostream>

//class里面的成员变量和成员函数是分开存储的
//非静态变量属于类，静态单独存储，函数和所有函数一起存在一个实例中
//因为是分开储存的，所以你使用一个类的空指针也就是class = NULL，直接访问内部的函数是没有问题的，因为函数在函数实例，但是访问变量就报错因为没有内存

class aaa{//静态成员在代码创建的时候就直接分配内存，所以也是直接存储在全局区，静态的东西也是有访问权限的
public:
    static int a;//静态成员需要类内声明，类外初始化

    static void aa(){//注意静态的成员函数只能访问静态的变量，不能访问其他的变量，因为函数共享，无法分辨是那个类的变量，所以只能访问静态的
        std::cout << aaa::a <<std::endl;
    }
};

int aaa::a = 100;//类外初始化

int main(void){
    aaa a1;
    std::cout << a1.a <<std::endl;//通过对象访问

    aaa a2;
    a2.a = 200;//静态成员全局共享，所以一个改全部都会改

    std::cout << a1.a <<std::endl;

    std::cout << aaa::a <<std::endl;//可以使用类名直接访问
}