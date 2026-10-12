//STL就是一些写好的可以直接调用的模板，直接调用就不用写那么多，只做基础使用了解
#include<iostream>
using namespace std;
#include<vector>//容器的引用头文件
#include<algorithm>//标准算法头文件

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

int main(){
    test1();
}