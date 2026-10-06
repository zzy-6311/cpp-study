#include<iostream>
#include<fstream>
#include<string>

int main(){
    //写文件
    std::ofstream ofs;//初始化一个文件对象
    //ofstream是写文件；ifstream是读文件；fstream是读写文件
    ofs.open("G:\\C-Cpp\\Cpp-study project\\test.txt", std::ios::out);//打开文件路劲，注意这里的std::ios::out是权限
    //ios::out为写文件而打开文件；ios::in为读文件而打开文件//这里的out是复写不是接着写
    //ios::ate为初始位置：文件尾；ios::app为追加方式写文件
    //ios::trunc为如果文件存在先删除，再创建；ios::binary为二进制方式
    ofs << "abc";//输入内容
    ofs.close();//关闭文件对象

    //读文件的4种方式
    std::ifstream ifs;
    ifs.open("G:\\C-Cpp\\Cpp-study project\\test.txt", std::ios::in);
    if (!ifs.is_open()){//检测文件是否被正常打开
        std::cout << "打开失败" << std::endl;
        return 0;
    }
    char read[1024] = {};
    while (ifs >> read){//这个地方是这个读文件会在读到末尾的时候返还一个特殊值就会退出循环
        std::cout << read << std::endl;
    }

    ifs.clear();//清理上一个读的标志位
    ifs.seekg(0, std::ios::beg);//把文件的读指针返回第一位

    char read2[1024] = {};
    while (ifs.getline(read2, sizeof (read2))){//这个地方是这个读文件会在读到末尾的时候返还一个特殊值就会退出循环
        std::cout << read2 << std::endl;
    }

    ifs.clear();//清理上一个读的标志位
    ifs.seekg(0, std::ios::beg);//把文件的读指针返回第一位

    std::string read3;
    while (getline(ifs, read3)){//这个地方是这个读文件会在读到末尾的时候返还一个特殊值就会退出循环
        std::cout << read3 << std::endl;
    }

    ifs.clear();//清理上一个读的标志位
    ifs.seekg(0, std::ios::beg);//把文件的读指针返回第一位

    char read4;//单字符读法，不推荐
    while ((read4 = ifs.get()) != EOF){//这个地方是这个读文件会在读到末尾的时候返还一个特殊值就会退出循环
        std::cout << read4;
    }
    std::cout << std::endl;

    ifs.close();

    //写二进制文件
    std::ofstream oofs("G:\\C-Cpp\\Cpp-study project\\test.txt", std::ios::out | std::ios::binary);
    //使用两种模式读写文件就是使用一个“|”来调用多个权限
    //这种对象输入的写法等同于oofs.open
    //但是写二进制文件需要用write函数来写
    std::string w = "zzy";
    oofs.write((char *)&w, sizeof(w));//这个地方使用强转的原因就是需要输入的是一个char指针
    oofs.close();

    //读二进制文件
    std::ifstream iifs;
    iifs.open("G:\\C-Cpp\\Cpp-study project\\test.txt", std::ios::in | std::ios::binary);
    if (!iifs.is_open()){//检测文件是否被正常打开
        std::cout << "打开失败" << std::endl;
        return 0;
    }

    std::string r;
    iifs.read((char *)&r, sizeof(r));//也是需要强转指针
    std::cout << r << std::endl;//写入的二进制可能看不懂，但是只要能够完整的读出来就可以，相当于加密了

    iifs.close();
}