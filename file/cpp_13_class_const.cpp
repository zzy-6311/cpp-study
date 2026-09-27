#include<iostream>

//const修饰常函数常对象

class aaa{
public:
    int a = 10;
    mutable int b = 10;

    void test() const//这个const修饰的是this对应的值，也就是这个函数里面不能修改this指向的值，也就是当前class
    {
//        a = 100;//报错
//        this->a = 100;//报错
//        this = NULL;//这个更是报错但是这个就算没有const修饰也要报错，因为this本来就是常量指针，不能改变指针的指向
        b = 100;//使用mutable修饰的变量就是特殊变量可以在const中修改
    }

    void test2(){
        std::cout << 2 << std::endl;
    }
};

int main(void){
    const aaa zzy;//const修饰class，要求里面的变量必须要有初始值，否则报错

//    zzy.a = 20;//报错因为是常对象，内容也不能修改
    zzy.b = 20;//因为b是特殊值，所以可以修改
    zzy.test();//常对象只能调用常函数
//    zzy.test2();//常对象不能调用非常函数，因为非常函数带有值修改
}