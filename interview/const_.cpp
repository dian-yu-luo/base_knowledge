int main(int argc, char const *argv[])
{
    const int var = 1;
    // var = 2;
    // 有两种,指针指向的内容和指向常量的指针
    /// 常量指针
    int a;
    const int *p1 = &a; 
    a = 300;
    //*p1 = 56;    // 错误，*p1是const int的，不可修改，即常量指针不可修改其指向的内容
    int b = 200;
    p1 = &b; // 指针可以修改

    /// 指针常量
    int *const p2 = &a; // 这样之后指针只能指向这一个位置了,指针不能瞎改
    a = 500;   // 可以通过原来的声明修改值
    *p2 = 400; // 指针是常量，指向的地址不可以变化，但是指向的地址所对应的内容是可以变化的
    // p2 = &b;   // 错误，因为p2是const指针，因此不能改变p2指向的地址

    /// 指向常量的常量指针
    const int *const p3 = &a;
    //*p3=1;   // 错误
    // p3=&b;   // 错误
    a = 600; // 可以通过原来的声明修改值

    return 0;
}
