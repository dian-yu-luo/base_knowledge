#include <iostream>
class Animal
{
private:
    /* data */
public:
    Animal(/* args */);
    ~Animal();
    virtual void eat()
    {
        printf("动物要吃东西\n");
    }
};

Animal::Animal(/* args */)
{
}

Animal::~Animal()
{
}

class Cat : public Animal
{
private:
    /* data */
public:
    Cat(/* args */);
    ~Cat();
    void eat()
    {
        printf("mao 要吃东西\n");
    }
};

Cat::Cat(/* args */)
{
}

Cat::~Cat()
{
}

int main(int argc, char const *argv[])
{
    Animal *a = new Cat;
    a->eat();
    Cat c;
    c.eat();
    return 0;
}
