#include<iostream>

//别名就是数据类型 &别名 = 原名，就可以了
//别名本质自带解析的指针，函数传参时，传指针和别名都有可在函数中修改全局值的功能
//返回局部变量，比如函数里面的变量，栈区内存被释放后就和野指针一样了，都只是编译器保留了一次输出//除非数据不是在栈区
//但是并不是不可以用，它可以是函数的左值：aaa（）=100；//就是给别名的变量继续赋值
//别名返还的数据类型是int&

int aaa(int &a){
    a = 30;
    return a;
}

int main(void){
    int a = 10;
    int &b = a;//引用必须初始化，int &b;不行
    //初始化后的别名不能更改，比如又来一个&b = c;不行，b = c是赋值

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    b = 100;

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    aaa(b);

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    return 0;
}