#include<iostream>
#include<string>

class aaa{
public:
    void funa(){
        std::cout << "aaa" << std::endl;
    }
};

class bbb{
public:
    void funb(){
        std::cout << "bbb" << std::endl;
    }
};

template<class nametype, class agetype = int>//类模板可以使用默认参数，就可以避免推导
class person{
public:
    person(nametype inname, agetype inage);//外部实现需要声明
    void show();

    nametype name;
    agetype age;
};

template<class T1, class T2>//类模板的构造函数的类外实现必须要使用模板的方式传模板参数才行
person<T1, T2>::person(T1 inname, T2 inage){//使用::表示作用域，作用域需要表明是模板
    this->name = inname;//构造函数或者说使用了参数的就需要模板传参，前面的作用域是一个这样的固定写法
    this->age = inage;
}

template<class T1, class T2>//类模板的成员函数的类外实现必须要使用模板的方式传模板参数才行
void person<T1, T2>::show(){
    std::cout << name << age << std::endl;
}

template<class ffun>
class fun_test{
public:
    fun_test(ffun a){
        A = a;
    }
    ffun A;

    void fun1(){//类模板中成员函数在调用时才去创建
        A.funa();
    }

    void fun2(){//所以这里的两个在没有调用的时候是不会报错的，现在不可能有一个类同时包含这两个功能，但是不报错，但是使用函数编译就会报错
        //但是你只要保证调用不会冲突这样使用是没有问题的，属于保留功能
        A.funb();
    }
};

class zi1: public person<std::string, int>{//子类继承父类模板就需要使用指定类型，否则不能分配内存
};

template<class T>
class zi2: public person<T>{//子类想自由继承父类模板，就只有把子类也写成模板
};

void test1(){
    person a1("AA", 13);//类模板和函数模板的区别就是不能使用这种自动推导变量类型，这里可以是因为在cpp 17的版本后
    //加入了这个功能，但是尽量不要使用，因为是CTAD推导成的指针，这里的“AA”推到的是一个char[2]，而不是string，要小心使用
    a1.show();
    person<std::string, int> a2("BB", 14);
    a2.show();
    person<std::string> a3("CC", 15);//类模板可以使用这个默认参数，这样在参数列表中就不用指定参数也不会发生推导
    a3.show();
}

//模板创建的类的模板参数化，就是把模板当作参数传入
void test2(person<std::string, int> &a){}

//参数模板化，就是把参数变成模板也能自己传入参数，自己推导参数
template<class T1, class T2>
void test22(person<T1, T2> &a){
    std::cout << typeid(T1).name() << std::endl;
    std::cout << typeid(T2).name() << std::endl;
}

//整个类模板化，编译器自己推导类的种类
template<class T>
void test222(T &a){
    std::cout << typeid(T).name() << std::endl;
}

void test3(){
    person<std::string, int>a4("DD", 16);
    test2(a4);
    test22(a4);
    test222(a4);
}

int main(){
    test1();
    test3();
}