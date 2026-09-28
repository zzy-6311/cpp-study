#include<iostream>
#include<string>

//主要就是让一些特殊的函数来访问class中的private权限

class test;
class bbb;

class ccc{//类友元
public:
    void ttt(test * aa);//因为成员需要访问的参数在下面，所以只能写在参数下面，所以这里就只能写成声明
};

class test{
    friend void goodfriend(test *aaa);//使用一个友元申明到class的头部，外面的函数就视作类内，就可以访问私有权限
    friend class bbb;//使用类做友元
    friend void ccc::ttt(test * aa);//使用成员函数做友元

public:
    void building(){
        keting = "客厅";
        woshi = "卧室";
    }

public:
    std::string keting;

private:
    std::string woshi;
};

class bbb{//类友元
public:
    void ttt(test * aa){
        std::cout << aa->keting << std::endl;
        std::cout << aa->woshi << std::endl;
    }
};

void ccc::ttt(test * aa){
    std::cout << aa->keting << std::endl;
    std::cout << aa->woshi << std::endl;
}

void goodfriend(test *aaa){
    std::cout << aaa->keting << std::endl;
    std::cout << aaa->woshi << std::endl;
}

int main(){
    test aaa;
    aaa.building();
    goodfriend(&aaa);
}