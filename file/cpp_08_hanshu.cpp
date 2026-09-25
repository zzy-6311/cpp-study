#include<iostream>

int add(int a = 1, int b = 10, int c = 100);//声明有参数的话函数就不能有参数
int aaa(int, int);

int bbb(int a){
    return 0;
}

int bbb(double a){//函数重载，就是除了返回值以外得函数名字的不一样的地方就可以调用不一样的函数，这就是函数重载，const的常数不一样要传常数
    return 1;//总之就是避免二义性，能让编译器找到调用的函数就行了
}

int main(void){
    int a = add();
    printf("%d\n", a);

    int b = bbb(10);
    int c = bbb(1.1);//cpp里面传入1.1默认double，需要float的话需要浮点转浮点
    printf("%d\n", b);
    printf("%d\n", c);//占位参数也需要传入值
}

int add(int a, int b, int c){//默认参数都要后置，也就是都要放在右边不能穿插，和python不同
    return a + b + c;
}

int aaa(int, int){
    return 0;
}