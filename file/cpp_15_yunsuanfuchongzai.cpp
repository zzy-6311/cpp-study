#include<iostream>

//运算符重载就是让自己创建的对象，进行原本没有的运算，告诉编译器怎么运算
//主要就是重载函数：operator
//这些重载运算符也可以使用友元访问私有函数的

//同时还有赋值符号“=”的重载，用来做深拷贝防止堆区报错，写法都是一样的，注意一下返回值的使用就好了
//还有关系运算符“==，=>，=<”这种，也都是一样的写法
//函数调用的重载，仿函数，其实就是重载了“（）”让看起来像一个括号

//加号运算符重载
class test{
public:
//    test operator+(test &a){//成员函数做重载
//        test a1;
//        a1.ma = this->ma + a.ma;
//        a1.mb = this->mb + a.mb;
//        return a1;
//    }

    int ma;
    int mb;
};

test operator+(test &p1, test &p2){//全局函数做重载
    test a1;
    a1.ma = p1.ma + p2.ma;
    a1.mb = p1.mb + p2.mb;
    return a1;
}

test operator+(test &p1, int p2){//重载函数也可以使用函数重载，防止没有定义过的变量相加
    test a1;
    a1.ma = p1.ma + p2;
    a1.mb = p1.mb + p2;
    return a1;
}

//左移运算符的重载//const是为了后面的使用需要修饰临时对象
std::ostream& operator<<(std::ostream &cout, const test &p){//cout也是有自己的变量类型的
    cout << p.ma << p.mb;
    return cout;
}

//前置++的重置
test& operator++(test & p){
    ++p.ma;
    return p;
}

//后置++的重置
test operator++(test & p, int){
    test temp = p;
    p.mb++;
    return temp;
}

void plus(){
    test p1;
    p1.ma = 10;
    p1.mb = 10;
    test p2;
    p2.ma = 20;
    p2.mb = 20;
//    test p3 = p1 + p2;
    test p3 = p1 + 10;//使用函数重载

    std::cout << p3.ma << std::endl;
    std::cout << p3.mb << std::endl;

    std::cout << p1 << std::endl;

    std::cout << ++(++p1) << std::endl;

    std::cout << p1 << std::endl;

    std::cout << p1++ << std::endl;

    std::cout << p1 << std::endl;
}

int main(void){
    plus();
}