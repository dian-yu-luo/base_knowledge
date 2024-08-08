// 只在当前文件中使用
static int fff()
{
}
int func()
{
    // 静态存储区上面
    static int a;
}

class static_
{
private:
    // 只保存一个变量
    static int a;

public:
    static_(/* args */);
    ~static_();
    // 可以直接使用,但是只能访问 static 的成员变量
    static void func()
    {
    }
};

static_::static_(/* args */)
{
}

static_::~static_()
{
}

int main(int argc, char const *argv[])
{

    return 0;
}
