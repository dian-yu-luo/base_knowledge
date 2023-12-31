#include <memory>
#include <iostream>
using namespace std;
// TODO 这个东西的实现原理是什么?
// 这里的一个函数,参数是 shared_ptr<int> i   //咱也看不懂,这叫个啥,但是
// 这个智能指针指向的是一个int 类型的值

// TODO 要不要和类的构造扯上关系
void foo(std::shared_ptr<int> i)
{
    (*i)++; // 指向的值+1
}
int main(int argc, char const *argv[])
{
    std::cout << "\033[31m"
              << "begining--------------------"
              << "\033[0m" << std::endl;
    auto pointer = std::make_shared<int>(10);
    auto pointer2 = pointer; // 引用计数 +1
    auto pointer3 = pointer; // 引用计数 +1
                             // 这样不会增加引用计数
    {
        // 作用域里面的值都在指着,但是作用域没事了之后,外面还在处理这个东西,
        // 简单的说呢就是虽然作用域完事了,但是外面的作用域依旧能够管理里面的内容
        auto pointer_dian = std::make_shared<int>(99);
        pointer2 = pointer_dian; // 引用计数 +1
        pointer3 = pointer_dian;
    }

    std::cout << "pointer2 value is :" << *pointer2 << std::endl;
    std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl;
    // 3
    std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl; // 3
    std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl; // 3

    // 我不和别人共享了昂,我谁也不指向了
    pointer2.reset();
    // std::cout << *pointer2;
    // 上面的代码存在问题,因为已经经过了reset,指针谁也不指着了,所以就直接是空指针了
    std::cout << "reset pointer2:" << std::endl;
    std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl;
    // 2
    std::cout << "pointer2.use_count() = "
              << pointer2.use_count() << std::endl;
    // pointer2 已 reset; 0
    std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl; // 2
    pointer3.reset();
    std::cout << "reset pointer3:" << std::endl;
    std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl;
    // 1
    std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl; // 0
    std::cout << "pointer3.use_count() = "
              << pointer3.use_count() << std::endl;
    return 0;
}
