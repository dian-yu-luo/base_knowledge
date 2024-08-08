#include <iostream>
using namespace std;
class copy_construct_func
{
private:
    /* data */
public:
    copy_construct_func(/* args */);
    copy_construct_func(const copy_construct_func &c);
    ~copy_construct_func();
};

copy_construct_func::copy_construct_func(/* args */)
{
}

copy_construct_func::copy_construct_func(const copy_construct_func &c)
{
    printf("在这里调用了拷贝构造函数");
}

copy_construct_func::~copy_construct_func()
{
}

int main(int argc, char const *argv[])
{
    copy_construct_func ccf;
    /* 这种情况是默认调用拷贝构造函数的 */
    copy_construct_func cc2 = ccf;

    return 0;
}
