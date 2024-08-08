#include <iostream>
#include <string.h>
using namespace std;
class move_construct_func
{
private:
    /* data */
public:
    move_construct_func(/* args */);
    ~move_construct_func();
};

move_construct_func::move_construct_func(/* args */)
{
}

move_construct_func::~move_construct_func()
{
}
int main(int argc, char const *argv[])
{
    move_construct_func mcf;

    return 0;
}
