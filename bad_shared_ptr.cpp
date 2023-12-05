#include <memory>
#include <iostream>
struct A;
struct B;
struct A
{
    // A有一个B类型的成员变量
    std::shared_ptr<B> pointer;
    ~A()
    {
        std::cout << "A 被销毁" << std::endl;
    }
};
struct B
{
    std::shared_ptr<A> pointer;
    ~B()
    {
        std::cout << "B 被销毁" << std::endl;
    }
};
int main()
{
    // 自动生成一个A的实力,这个时候指向B的指针空悬着
    auto a = std::make_shared<A>();

    auto b = std::make_shared<B>();
    a->pointer = b;
    b->pointer = a;
    // 结束前开始析构,先析构b

    // 著名难点,交叉引用
}