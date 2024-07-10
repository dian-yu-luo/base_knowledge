
#include <memory>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <utility>
using namespace std;


//实现深拷贝：
class HasPtr
{
public:
    //默认构造函数
    HasPtr(const std::string& s = std::string()) : ps(new std::string(s)), i(0)
    {
        cout << "HasPtr() Address: " << this << "\n";
    }

    //拷贝构造函数
    HasPtr(const HasPtr& data) : ps(new string(*(data.ps))), i(data.i)
    {
        cout << "HasPtr(const HasPtr& data) Address: " << this << "\n";
    }

    //移动构造函数
    HasPtr(HasPtr&& rhs) noexcept : ps(rhs.ps), i(rhs.i)
    {
        rhs.ps = nullptr;
        rhs.i = 0;
        cout << "HasPtr(HasPtr&& rhs) Address: " << this << "\n";
    }

    // 析构函数
    ~HasPtr()
    {
        cout <<"freeing address: "<< ps << "\n";
        delete ps;
        cout << "~HasPtr() Address: " << this << " \n";
    }

    //释放HasPtr类对象占用的资源。
    //ps指向的对象在堆上分配，而数据成员又是原始指针，必须手动管理内存。
    //i是一个int类型对象，它的内存在栈上分配，而不是在堆上。
    //当HasPtr类对象被销毁时，内置类型内存自动释放，无需（也不能）手动去delete它。

private:
    std::string* ps;
    int i;
};

HasPtr foo()
{
    return HasPtr();
}

int main()
{
    HasPtr S = foo();
}