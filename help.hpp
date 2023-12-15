#include <iostream>
using namespace std;
void red_print(string str)
{
    std::cout << "\033[31m"
              << str
              << "\033[0m" << std::endl;
}