#include <memory>
#include <iostream>
using namespace std;

// 这里的一个函数,参数是 shared_ptr<int> i   //咱也看不懂,这叫个啥,但是
// 这个智能指针指向的是一个int 类型的值
void foo(std::shared_ptr<int> i)
{
    (*i)++; // 指向的值+1
}
int main(int argc, char const *argv[])
{
    // 功能是在动态内存中分配一个对象并初始化它，返回指向此对象的shared_ptr
    auto pointer = std::make_shared<int>(10);
    foo(pointer);
    // 我可以想用指针一样的用它
    std::cout << *pointer << std::endl; // 11

    
    return 0;
}
