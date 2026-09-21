#include<iostream>

int main(void){
    int a = 10;
    int *p;
    int *q = NULL;

    int *h = (int *)0x1100;//这种就是野指针，指向未申请的地址，就会直接报错

    std::cout<< q <<std::endl;//空指针内容是0
    //std::cout<< *q <<std::endl;//空指针不可访问

    p = &a;

    std::cout<< *p <<std::endl;//*p就是解析p的内容
    std::cout<< p <<std::endl;
    std::cout<< &a <<std::endl;//p == &a
    std::cout<< &p <<std::endl;//&p就是p的地址

    std::cout<<sizeof(int *)<<std::endl;//64位上都是8字节，但是32位都是4字节
    std::cout<<sizeof(float *)<<std::endl;//但是他们的步进长度并不一样
    std::cout<<sizeof(double *)<<std::endl;
    std::cout<<sizeof(char *)<<std::endl;

    const int * x = &a;//常量指针，后续指针的指向可以修改，但是值不可修改，*p=20不可以，p=&b可以
    int * const y = &a;//指针常量，后续指针的值可修改，但是指向不可以修改，*p=20不可以，p=&b可以
    const int * const z = &a;//两个一起修饰

    int b[10] = {1,2,3,4,5,6,7,8,9,10};
    int *d = b;
    std::cout<< d <<std::endl;
    std::cout<< b <<std::endl;
    std::cout<< *d <<std::endl;
    std::cout<< b[0] <<std::endl;
    d++;
    std::cout<< *d <<std::endl;
}