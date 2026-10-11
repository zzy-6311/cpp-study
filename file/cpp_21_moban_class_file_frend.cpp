#include<iostream>
#include<string>

#include"cpp_21_moban_class_file_frend.hpp"//这个文件夹就是把类模板给文件夹储存
//但是这里使用的是hpp文件是有含义的，一般情况的函数或者类，我们都把类的结构也就是变量和成员函数声明写在头文件.h里面
//然后函数的实现就会写在对应的.cpp源码文件里面，但是这时候你引用头文件可以编译但是不能调用成员函数，因为类模板里面的成员函数在没有使用的
//时候是不会生成的，所以编译的时候更不就不会调用生成.cpp的那个实现文件，这个时候就会出现函数的无法定位的问题，这个时候解决办法就是不改代码
//直接把.h调用改成.cpp调用，因为有作用域就会自己去调用包含的头文件同时也会加载函数的实现。但是这样并不是很规范，所以约定俗成
//类模板的定义和实现就放到一个.hpp文件里面，定义和实现一起，直接调用.hpp就没有问题了

//但是类外实现这个需要让编译器提前知道这个函数的存在，所以这个函数只能写在前面，而且因为又调用了现在这个类模板，所以还要申明这个类模板
template<class T1, class T2>
class people;
//所以类外实现非常的复杂，所以非常不推荐
template<class T1, class T2>//类外实现也需要写成模板，但是因为是模板所以声明的时候需要声明是模板所以要加空模板<>
void printpeople2(people<T1, T2> a){
    std::cout << a.name << std::endl;
    std::cout << a.age << std::endl;
}

//类模板的友元
template<class T1, class T2>
class people{
    //全局函数类内实现
    friend void printpeople(people<T1, T2> a){//注意这里是因为有friend这个关键词命名友元，才能把本来的成员函数变成全局函数
        //因为变成了全局函数所以可以被全局调用，并且就没有了this这个功能，就必须使用a.
        //全局函数的类内实现是最推荐的写法，最简单
        std::cout << a.name << std::endl;
        std::cout << a.age << std::endl;
    }

    friend void printpeople2<>(people<T1, T2> a);//类外实现的声明，但是因为是模板所以声明的时候需要声明是模板所以要加空模板<>
    //但是类外实现这个需要让编译器提前知道这个函数的存在，所以这个函数只能写在前面，而且因为又调用了现在这个类模板，所以还要申明这个类模板

public:
    people(T1 na, T2 ag){
        this->name = na;
        this->age = ag;
    }

private:
    T1 name;
    T2 age;
};

void test1(){
    person<std::string, int> a("AA", 14);
    a.show();
}

void test2(){
    people<std::string, int> a("BB", 15);
    printpeople(a);
    printpeople2(a);
}

int main(){
    test1();
    test2();
}