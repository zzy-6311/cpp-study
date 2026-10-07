#include<iostream>
//模板就是可以快速类型复制使用的快捷工具

void swint(int &a, int &b){//原始函数交换两个int
    int temp = a;
    a = b;
    b = temp;
}

void swdouble(double &a, double &b){//原始函数交换两个double
    double temp = a;
    a = b;
    b = temp;
}

//上面是最原始的函数来转换，但是他们只是数据类型上的不一样，这个时候就可以使用模板自己推导数据类型
template<typename A>//声明模板，这个地方的A就是告诉编译器不要报错，这个A是一类数据类型，这个A甚至可以是class
void sw(A &a, A &b){
    A temp = a;//正常使用这个A的类型别名
    a = b;
    b = temp;
}

int main(){
    int a = 10;
    int b = 20;

    swint(a, b);//使用传统函数

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    sw(a, b);//使用模板，会自己推导传参的类型，替代暂时命名

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    sw<int>(a, b);//显式模板，就是自己传参

    std::cout << a << std::endl;
    std::cout << b << std::endl;
}