static int fff()
{
}

int func()
{
    static int a;
}

class static_
{
private:
    static int a;

public:
    static_(/* args */);
    ~static_();
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
