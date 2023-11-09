#include <iostream>

class Base
{
public:
    Base() = default;

    virtual void print()
    {
        std::cout << "Print!\n";
    }
};

class Derived : public Base
{
public:
    Derived() = default;

    void print()
    {
        std::cout << "DPrint!\n";
    }
};

// Derived2 class
class Derived2 : public Base {
    void print()
    {
        std::cout << "Derived2" << std::endl;
    }
};

int main()
{
    Derived d;
    Base* bp = dynamic_cast<Base*>(&d);
 
    // Type casting
    Derived* d2 = dynamic_cast<Derived*>(bp);
    if (d2 == nullptr)
        std::cout << "null" << std::endl;
    else
        std::cout << "not null" << std::endl;
    return 0;
}