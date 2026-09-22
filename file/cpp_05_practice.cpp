#include<iostream>
#include<string>
#include<cstdlib>

#define size 1000

struct people{
    int id;
    std::string name;
    int gender;//性别：0/1(女/男)
    int age;
    std::string contact_number;//联系电话
    std::string home_address;//家庭住址
};

int find(people *find_id, int number);

int number = 0;
std::string name;

people directory[size] = {};

int main(void){
    int a = 0, b = 0, c = 0, d = 0;

    while (1){
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
                break;
            case 2:
                for (int i = 0; i < size; i++){
                    if (directory[i].id != 0){
                        c++;
                        std::cout << "编号：" << c << "  名字：" << directory[i].name <<
                                  "  性别：" << directory[i].gender << "  年龄：" << directory[i].age <<
                                  "  联系电话：" << directory[i].contact_number << "  家庭住址：" << directory[i].home_address << std::endl;
                    }
                }
                c = 0;
                break;
            case 3:
                std::cout << "名字：" << std::endl;
                std::cin >> name;
                for (int i = 0; i < size; i++){
                    if (directory[i].id != 0){
                        if (directory[i].name == name){
                            directory[i] = {};
                            number--;
                        }
                    }
                }
                break;
            case 4:
                std::cout << "名字：" << std::endl;
                std::cin >> name;
                for (int i = 0; i < size; i++){
                    if (directory[i].id != 0){
                        c++;
                        if (directory[i].name == name){
                            std::cout << "编号：" << c << "  名字：" << directory[i].name <<
                                      "  性别：" << directory[i].gender << "  年龄：" << directory[i].age <<
                                      "  联系电话：" << directory[i].contact_number << "  家庭住址：" << directory[i].home_address << std::endl;
                        }
                    }
                }
                c = 0;
                break;
            case 5:
                std::cout << "名字：" << std::endl;
                std::cin >> name;
                for (int i = 0; i < size; i++){
                    if (directory[i].id != 0){
                        if (directory[i].name == name){
                            std::cout << "名字：" << std::endl;
                            std::cin >> directory[i].name;
                            std::cout << "性别：" << std::endl;
                            std::cin >> directory[i].gender;
                            std::cout << "年龄：" << std::endl;
                            std::cin >> directory[i].age;
                            std::cout << "联系电话：" << std::endl;
                            std::cin >> directory[i].contact_number;
                            std::cout << "家庭住址：" << std::endl;
                            std::cin >> directory[i].home_address;
                        }
                    }
                }
                break;
            case 6:
                std::cout << "sure?" << std::endl;
                std::cin >> d;
                if (d == 0){
                    for (int i = 0; i < size; i++){
                        directory[i] = {};
                    }
                    number = 0;
                    std::cout << "成功" << std::endl;
                }
                else{
                    std::cout << "取消" << std::endl;
                }
                break;
            case 7:
                return 0;
            default:
                std::cout << "EOF" << std::endl;
                break;
        }
    }
}

int find(people *find_id, int number){
    for (int i = 0; i <= number; i++){
        if (find_id[i].id == 0){
            return i;
        }
    }
}