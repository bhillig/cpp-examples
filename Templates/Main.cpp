#include <iostream>
#include <string>

// Example of using C++ Templates

// This file creates a class Array that acts similar to std::array in that it can create a stack allocated array of type T and size N

// This class supports reading and writing to the contetns of this array, the << operator is also overriden to support printing
// which is used in a templated print function

template<typename T, int N>
class Array
{
private:
    T contents[N];

public:

    Array()
    {
        for(int i = 0; i < N; ++i)
            contents[i] = (T)0;
    }

    T& operator[](unsigned int index)
    {
        return contents[index];
    }

    const T& operator[](unsigned int index) const
    {
        return contents[index];
    }

    template<typename C, int X>
    friend std::ostream& operator<<(std::ostream& stream, Array<C, X>& array);
};

template<typename T, int N>
std::ostream& operator<<(std::ostream& stream, Array<T, N>& array)
{
    for(int i = 0; i < N; ++i)
    {
        stream << array.contents[i] << std::endl;
    }
    return stream;
}

template<typename T>
void Print(T value)
{
    std::cout << value << std::endl;
}

int main(int argc, char* argv[])
{
    Array<const char*, 2> arrayOne;
    arrayOne[0] = "Default";
    arrayOne[1] = "Test";
    Print(arrayOne);

    Array<int, 3> arrayTwo;
    arrayTwo[0] = 11;
    arrayTwo[1] = 4;
    arrayTwo[2] = 67;
    Print(arrayTwo);

    return 0;
}