#include <iostream>

class Vector2
{
public:
    int x, y;
public:
    Vector2()
        : x(0), y(0)
    {}
    explicit Vector2(int x)
        : x(x), y(x)
    {}
    Vector2(int x, int y)
        : x(x), y(y)
    {}

};

void PrintVector(const Vector2& other)
{
    std::cout << other.x << ", " << other.y << std::endl;
}

int main(int argc, char* argv[])
{
    Vector2 a;
    PrintVector(a);
    Vector2 b(5, 4);
    PrintVector(b);

    // The two lines below do not work because we made our constructor above that takes an int explicit
    // This means that we must explicitly call our constructor for the conversion to take place
    //Vector2 c = 7;
    //PrintVector(3);
    PrintVector((Vector2)3);
    return 0;
}