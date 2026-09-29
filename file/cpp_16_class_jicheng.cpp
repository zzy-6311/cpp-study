#include<iostream>

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
    void t(){
        std::cout << "060601" << std::endl;
    }
};

int main(){
    aaa a1;
    bbb b1;

    a1.t1();
    a1.t();

    b1.t1();
    b1.t();
}