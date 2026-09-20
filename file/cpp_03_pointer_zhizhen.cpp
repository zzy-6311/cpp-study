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
}