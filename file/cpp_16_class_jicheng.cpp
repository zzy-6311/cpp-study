#include<iostream>

//继承的内存的大小是继承的父类的内存加上子类的新建，注意即使是父类中的私有权限的数据也会被继承的子类计算内存，但是编译器会隐藏私有
//所以继承的子类看不到父类中的私有，但是其中的私有的内存大小会计算到子类中
//所以继承是全部继承，只是隐藏了

//继承会先创建一个父类然后使用他的数据，再创建子类，读取父类，结束时先析构子类，再析构父类结束引用，总之就是先创建父类，最后析构父类

//菱形继承，比如动物类被狗和狼继承，现在一个狼狗有同时继承狗和狼两个类，就会出现同名的冲突
//可以加上一个关键字virtual变成虚继承，这个时候我们命名动物这个类叫虚基类，这个时候继承的就不会出现两个父类的不同类名的继承是重复的
//这样继承的都会是同一个，所以你无论使用什么类名访问出来都是同一个变量无论使用什么办法，就可以避免浪费资源

class aaa{
public:
    void t1() {
        std::cout << 1 << std::endl;
    }

    void t2() {
        std::cout << 2 << std::endl;
    }

    void t3() {
        std::cout << 3 << std::endl;
    }

    void t(){
        std::cout << 114514 << std::endl;
    }
};

class bbb: public aaa{//这个地方的继承权限protected和provate是不同的继承程度
    //public，protected和private都是一样的public和protected没有private，因为private是私有不能继承
    //但是有继承权限变化，public权限继承public的还是public，protected还是protected
    //protected继承的protected和public都会变成protected没有public了
    //private继承的就是protected和public都变成private没有protected和public了
public:
    void t4(){
        std::cout << 4 << std::endl;
    }

    void t5(){
        std::cout << 5 << std::endl;
    }

    void t6(){
        std::cout << 6 << std::endl;
    }

    void t(){
        std::cout << "060601" << std::endl;
    }
};

class ccc: public aaa,  public bbb{//cpp可以支持多继承，可以继承多个父类，但是不建议使用因为回会带来同名不好
    //但是出现了同名函数还是增加作用域就可以解决了
    //尽量少写，但是需要知道
public:

};

int main(){
    aaa a1;
    bbb b1;

    a1.t1();
    a1.t();

    b1.t1();
    b1.t();
    b1.aaa::t();//增加一个作用域的前缀就可以控制使用的函数来自父类还是子类，没有就是默认子类//函数和变量的调用都是一样的
    //注意这个访问不是单纯的函数重构，也就是说就算是变量不一样等不同的地方，但是还是访问的子类，因为继承是直接覆盖父类的全部函数
    //所以访问父类同名唯一的办法就是使用作用域访问
    //当然访问的如果是同名的静态变量或者函数也是一样的，只是静态多一个功能就是可以不通过对象访问，可以通过类型访问也就是类名字
    //所以可以出现aaa::bbb::xxx，这个就是通过aaa类型访问aaa类型中的bbb类型的xxx变量，这个路径和a1.bbb::xxx不一样，后者使用对象访问
}