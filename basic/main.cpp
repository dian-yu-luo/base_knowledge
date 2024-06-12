#include <iostream>
#include <string.h>
using namespace std;
int main(int argc, char const *argv[])
{
    printf("\033[31m--------华丽的分割线--------\n\n\n\033[0m");
    char a[] = {"hello world"};
    char b[] = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};

    cout << sizeof(a) << endl; // 12 占据的长度
    cout << strlen(a) << endl; // 11 实际的长度
    cout << sizeof(b) << endl; // 11 
    cout << strlen(b) << endl; // 10

    printf("\033[31m--------华丽的分割线--------\n\n\n\033[0m");

    return 0;
}
