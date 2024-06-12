// 静态成员的变量和对应的值

#include <iostream>
#include <string>
using namespace std;
int func()
{
    static int ret = 10;
    ret++;
    return ret;
}


// -----------------------------华丽的分割线---------------------------------

// 信息可以被共享的位置

int main(int argc, char const *argv[])
{
    for (size_t i = 0; i < 100; i++)
    {
        cout << func() << endl;
    }

    return 0;
}
