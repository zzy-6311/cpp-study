#include<iostream>
using namespace std;

template<class T1, class T2>
class person{
public:
    person(T1 na, T2 ag);

    T1 name;
    T2 age;

    void show();
};

template<class T1, class T2>
person<T1, T2>::person(T1 na, T2 ag){
    this->name = na;
    this->age = ag;
}

template<class T1, class T2>
void person<T1, T2>::show(){
    cout << name << endl;
    cout << age << endl;
}
