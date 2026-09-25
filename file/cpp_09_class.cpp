#include<iostream>
#include<string>

const double pi = 3.14159;//圆周率

//其实用起来strct和class是一样的，但是唯一的区别就是class默认私有权限，strct默认是公共权限

//权限：
//public-公共权限    成员 类内可以访问 类外可访问
//protected-保护权限 成员 类内可以访问 类外不可访问 子类可以访问父类
//private-私有权限   成员 类内可以访问 类外不可访问 子类不可访问父类
class circle{//类中的属性和变量，都称为成员//成员里面的函数叫成员方法，其他的成员属性，成员变量
    //访问权限
public:
    //属性
    int r;//半径

    //行为
    double calculate(){//计算周长
        return 2 * pi * r;
    }

    void set_r(int a){//使用函数自己赋值自己
        r = a;
        d = 2 * r;
    }

    void print_l(){//使用函数自己打印自己
        std:: cout << calculate() << std::endl;
    }

    void print_d(){//使用函数自己打印自己
        std:: cout << d << std::endl;
    }

protected:
    int d;
};

//特点展示权限控制
class people{
public:
    void set_name(std::string a){
        name = a;
    }

    void get_name(){
        std::cout << name << std::endl;
    };

    void get_age(){
        std::cout << age << std::endl;

    }
private:
    std::string name;//可写可读
    int age = 20;//只读取
};

int main(void){
    //通过类创建具体对象
    circle c1;
    c1.r = 10;
//    c1.d = 20;//报错，这个权限不允许
    c1.print_l();
    c1.set_r(5);
    c1.print_l();
    c1.print_d();//类内函数可以访问类内参数

    people r1;
    r1.set_name("zzy");
    r1.get_name();
    r1.get_age();
}