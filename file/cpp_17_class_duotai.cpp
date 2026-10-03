#include<iostream>

//首先多态分成静态和动态的多态，静态多态就是前面已经学过的函数重载和运算符重载等，总之就是复用重复的名字的东西就是多种形态--多态
//上面说的是静态多态，他和动态多态的区别就是静态多态的东西在代码编译的时候就已经他确定函数的指针位置，但是动态多态的一些指针位置都是运行中产生的

class animal{
public:
    //虚函数
    virtual void speak(){//如果没有virtual，就是常规函数，那么在下面的speak函数中，animal别名就会直接调用父类
        //但是增加virtual后就会后定位，就可以直接通过子类输入定位
        //注意动态多态的使用是需要有函数重写的，注意不是重载重载是函数的一些数据不一样导致导向的函数不一样，重写是完全同名同参数
        std::cout << "动物说话" << std::endl;
    }
};

class cat: public animal{
public:
    void speak(){
        std::cout << "小猫说话" << std::endl;
    }
};

class dog: public animal{
public:
    void speak(){
        std::cout << "小狗说话" << std::endl;
    }
};

void speak(animal &animal){
    animal.speak();
}

int main(){
    cat cat;
    speak(cat);//之所以可以使用直接传子类调用子类就是因为在父类中使用的是虚函数，虚函数就是动态多态，不会在代码开始的时候就指定指针位置

    dog dog;
    speak(dog);
}