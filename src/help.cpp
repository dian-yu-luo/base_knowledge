#include "help.h"
#include <iostream>
help::help()
{
}

help::~help()
{
}

void help::foo()
{
    printf("foo\n");
}

void help::red_print(string str)
{
}

void red_print(string str)
{
    std::cout << "\033[31m"
              << str
              << "\033[0m" << std::endl;
}