//STL就是一些写好的可以直接调用的模板，直接调用就不用写那么多，只做基础使用了解
#include<iostream>
using namespace std;
#include<vector>//容器的引用头文件
#include<algorithm>//标准算法头文件

class person{
public:
    person(string na, int ag){
        name = na;
        age = ag;
    }

    string name;
    int age;
};

void mtprint(int a){//自制标准打印
    cout << a << endl;
}

//vector存放内置数据类型
void test1(){
    vector<int> v;//创建一个vector容器，数据类型是int数组

    v.push_back(10);//插入一个数据
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    //第一种遍历方式
    vector<int>::iterator itbegin = v.begin();//起始迭代器，指向容器第一个元素
    vector<int>::iterator itend = v.end();//结束迭代器，指向容器最后一个元素的下一个位置
    while (itbegin != itend)
    {
        cout << *itbegin << endl;
        itbegin++;
    }

    cout << "\n" << endl;

    //第二种遍历方式
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it <<endl;
    }

    cout << "\n" << endl;

    //第三种遍历方式,STL自己提供的遍历算法
    //需要包含标准算法头文件
    for_each(v.begin(), v.end(), mtprint);
}
//vector存放自定义数据类型
void test2(){
    person a("AAA", 10);
    person b("BBB", 11);
    person c("CCC", 12);
    person d("DDD", 13);
    person e("EEE", 14);

    vector<person> v;

    v.push_back(a);//参数的存储输入方式
    v.push_back(b);//还有指针的存储输入形式，也就是vector的类型是<person *>，输入的时候就是v.push_back(&a);
    v.push_back(c);
    v.push_back(d);
    v.push_back(e);

    for (vector<person>::iterator it = v.begin(); it != v.end(); it++){
        cout << "name:" << (*it).name << " age:" << (*it).age << endl;
    }
}

//vector容器嵌套容器
void test3(){
    vector<vector<int>> v;

    vector <int> v1;//容器嵌套容器就像是二维数组一样，数组嵌套数组
    vector <int> v2;
    vector <int> v3;
    vector <int> v4;
    vector <int> v5;

    //小容器添加数据
    for (int i = 0; i < 5; i++){
        v1.push_back(i + 1);
        v2.push_back(i + 1);
        v3.push_back(i + 1);
        v4.push_back(i + 1);
        v5.push_back(i + 1);
    }

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    v.push_back(v5);

    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++){//注意这里的容器的指针嵌套
        for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++){
            cout << *vit << " ";
        }
        cout << endl;
    }
}

int main(){
    test1();
    test2();
    test3();
}