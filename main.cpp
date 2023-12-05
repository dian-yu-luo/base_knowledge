#include <iostream>

// 需要引入智能指针的库
#include <memory>
// 本次我将要学习智能指针

// 首先设置一个类,来进行原始的手动进行内存管理,发现原始的不足

void tesManualManageMemery()
{
    int *ptr = new int; // 动态分配一个int类型的内存
    *ptr = 10;
}
// gpt 生成的方案,尝试使用
class MemoryRAII
{
public:
    // 构造函数,数据初始化表,
    // data 是一个指针,所以也能视作是一个数组开头指向的内容
    MemoryRAII(size_t size) : data(new int[size])
    {
        std::cout << "Allocated memory of size: " << size << std::endl;
    }
    // 析构函数就是把指针指向的内容删除掉
    ~MemoryRAII()
    {
        delete[] data;
        std::cout << "Freed memory" << std::endl;
    }
    // 基本的修改函数方法
    void writeData(size_t index, int value)
    {
        data[index] = value;
    }

private:
    int *data;
};

int main(int argc, char const *argv[])
{

    try
    {
        MemoryRAII memory(10);
        memory.writeData(1, 42);
        memory;
        // 在此处离开作用域时，memory对象的析构函数会自动释放内存
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // 先不要用类来进行完成,写直接写
    // 首先,作为cpp 就不用c语言的方案{malloc 和 free 做了,虽然我不知道这俩的缺点是啥,但是
    // 我好事鉴定的选择cpp的方案 new delete }
    {

        // 以下的两组分别是对指针和数组的处理
        int *ptr = new int; // 动态分配一个int类型的内存
        *ptr = 10;          // 在分配的内存中存储值
        delete ptr;         // 释放内存

        /* ------------------朴素的分割线-------------------------------------------------------- */
        int *arr = new int[5]; // 动态分配一个包含5个int类型元素的数组
        arr[0] = 10;           // 在数组中存储值
        delete[] arr;          // 释放数组内存
        /* ------------------朴素的分割线-------------------------------------------------------- */
    };

    printf("hello");
    return 0;
}
