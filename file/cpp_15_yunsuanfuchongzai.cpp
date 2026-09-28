#include<iostream>

//运算符重载就是让自己创建的对象，进行原本没有的运算，告诉编译器怎么运算
//主要就是重载函数：operator

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
}

int main(void){
    plus();
}