#include<iostream>
#include<string>

#define size 100

struct people{
    int id;
    std::string name;
    int gender;//性别：0/1
    int age;
    std::string contact_number;//联系电话
    std::string home_address;//家庭住址
};

int find(people *find_id, int number);

int number = 0;
int id = 0;

people directory[size] = {};

int main(void){
    int a, b, c;

    std::cout << "1.添加联系人 2.显示联系人 3.删除联系人 4.查找联系人 5.修改联系人 6.清空联系人 7.退出" << std::endl;
    std::cin >> a;
    switch(a){
        case 1:
            if (number < size){
                b = find(directory, number);
                directory[b].id = b+1;
                std::cout << "名字：" << std::endl;
                std::cin >> directory[b].name;
                std::cout << "性别：" << std::endl;
                std::cin >> directory[b].gender;
                std::cout << "年龄：" << std::endl;
                std::cin >> directory[b].age;
                std::cout << "联系电话：" << std::endl;
                std::cin >> directory[b].contact_number;
                std::cout << "家庭住址：" << std::endl;
                std::cin >> directory[b].home_address;
                number++;
            }
            else if (number >= size){
                std::cout << "满" << std::endl;
            }
            else{
                std::cout << "EOF" << std::endl;
            }
            break;
        case 2:
            for (int i = 0; i < size; i++){
                if (directory[i].id != 0){
                    c++;
                    std::cout << "编号：" << c << "  名字：" << directory[b].name <<
                    "  性别：" << directory[b].gender << "  年龄：" << directory[b].age <<
                    "  联系电话：" << directory[b].contact_number << "  家庭住址：" << directory[b].home_address << std::endl;
                }
            }
            c = 0;
            break;
        case 3:
            std::cout << "编号：" << std::endl;
            std::cin >> id;
            
        case 4:;
        case 5:;
        case 6:;
        case 7:return 0;
        default:std::cout << "EOF" << std::endl;
    }
}

int find(people *find_id, int number){
    for (int i = 0; i <= number; i++){
        if (find_id[i].id == 0){
            return i;
        }
    }
}