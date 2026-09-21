#include<iostream>
#include<string>//输出字符串所需包含

//结构体中也可以嵌套结构体
struct student{
    std::string name;
    int age;
    int score;//成绩
}s3;//就是在创建结构体的同时生成一个实体，使用方法完全一样

int main(void){
    struct student s1;//也可以是是直接：student s1;效果完全相同
    s1.name = "xxx";
    s1.age = 10;
    s1.score = 100;
    std::cout << "name:" << s1.name << "age:" << s1.age << "score:" << s1.score << std::endl;

    struct student s2 = {"yyy", 11, 101};
    std::cout << "name:" << s2.name << "age:" << s2.age << "score:" << s2.score << std::endl;

    //结构体数组
    student s[3] = {{}, {}, {}};//一次性创建多个
    s[0].score = 102;//使用方式

    std::cout << s << std::endl;//也是可以指针访问的

    student *p = s;//结构体的指针也要是结构体类型的
    std::cout << p->score << std::endl;//访问不能使用“.”，只能用“->”
}