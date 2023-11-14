#include <iostream>

struct Vector2
{
    float x, y;
};

struct Vector4
{

    union 
    {
        struct
        {
            float x, y, z, w;
        };

        struct
        {
            Vector2 a, b;
        };
    };

};

std::ostream& operator <<(std::ostream& stream, const Vector2& vec)
{
    stream << vec.x << ", " << vec.y;
    return stream;
}

int main(int argc, char* argv[])
{
    Vector4 v1 = {5.2f, 6.7f, 2.3f, 0.9f};
    std::cout << v1.a << std::endl;
    std::cout << v1.b << std::endl;
    v1.z = 7.0f;
    std::cout << v1.a << std::endl;
    std::cout << v1.b << std::endl;

    return 0;
}