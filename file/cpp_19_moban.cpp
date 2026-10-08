#include<iostream>
#include<string>
//模板就是可以快速类型复制使用的快捷工具
//注意基础的模板不是万能的，在比如比大小你传入一个class，或者赋值传入数组就不能运算产生报错，这个时候使用运算符重载或者特定模板重载

class aaa{
public:
    aaa(int a, int b){
        this->A = a;
        this->B = b;
    }
    int A;
    int B;
};

void mobantest1(int a, int b){
    std::cout  << a + b << std::endl;
    std::cout  << "调用函数" << std::endl;
}

template<typename A>//如下，模板和函数名字一样，并且参数一样的时候，不会发生冲突只是会默认调用基础函数，也就是基础函数可以使用的时候优先调用基础函数
//就算你把基础函数的实现给注释了都不会调用模板而是直接调用，这个默认优先级很高，要使用这个模板就需要使用其他的数据类型，或者传入空模板
void mobantest1(A a, A b){
    std::cout  << a + b << std::endl;
    std::cout  << "调用模板" << std::endl;
}

template<> void mobantest1(aaa a, aaa b){//特定模板函数重载，就是在前面加上template<>，这个时候的模板参数直接使用需要重载的参数
    std::cout  << a.A + b.B << std::endl;
    std::cout  << "特定模板函数重载" << std::endl;
}

template<typename A>//模板也可以发生函数重载
void mobantest1(A a, A b, A c){
    std::cout  << a + b + c << std::endl;
    std::cout  << "调用重载模板" << std::endl;
}

template<typename A>
void mobantest2(A a, A b){
    std::cout  << a + b << std::endl;
}

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

//A就叫模板参数
//上面是最原始的函数来转换，但是他们只是数据类型上的不一样，这个时候就可以使用模板自己推导数据类型
template<typename A>//声明模板，这个地方的A就是告诉编译器不要报错，这个A是一类数据类型，这个A甚至可以是class
//然后这里的typename也可以使用class，使用起来和typename完全一样也就是templata<typename A>//但是其实初心是有不一样，class主要是想给类模板用的
void sw(A &a, A &b){
    A temp = a;//正常使用这个A的类型别名
    a = b;
    b = temp;
}
//模板的使用需要注意的就是这个A（模板参数），必须要在输入的时候的推导出来的名字必须要是都符合这个类型的，比如这个函数就需要传入两个int
//如果是一个函数没有使用你的模板参数这个类型，也就是你这个模板这和这个参数没有关系，在语法上这个模板就不能直接使用
//因为编译器就不能直接推算出这个变量是什么类型，如果要使用就只能使用显式模板的方式，自己指定参数类型

//模板函数和普通函数的区别还有一个就是在明确了参数类型的时候就会发生隐式类型转换，但是自动推导就不能发生
void test1(){
    int a = 1;
    int b = 2;
    char c = 'a';//注意cpp里面的''和""是不一样的，前者是字符，后者会转换成字符串是因为在""的后面默认带上一个\0提行，就会是两个字符
    mobantest1(a, b);//传入两个int可以使用，并且打印int
    mobantest1(a, c);//传入传入一个int和一个char也可以使用，并且打印int,这个时候就是发生了char的隐式转换到int，但是模板就不可以
    mobantest2(a, b);//模板自己推算数据类型就不能使用隐式转换，下面这个就会报错
//    mobantest2(a, c);
    mobantest2<int>(a, c);//使用显式模板就可以使用了，因为确定了数据类型就可以使用隐式转换
    mobantest1<>(a, b);//使用一个空模板参数列表就可以调用模板了
    mobantest1<>(a, b, 3);//模板也可以发生函数重载
    mobantest1(c, c);//如果模板比基础函数有更好的匹配就会调用模板，因为现在这char使用模板不发生隐式转换

    aaa a1(1, 2);
    aaa a2(2, 3);
//    mobantest1(a1, a2);//直接传参就会报错，因为class不能直接加，这个时候就需要使用特定模板函数重载
    mobantest1(a1, a2);
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

    test1();
}