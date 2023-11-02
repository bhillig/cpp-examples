#include <iostream>
#include <cstring>

// Goal of this file is to demonstrate the need of creating your own copy constructors in C++
// If we simply allowed the compiler to use the default copy constructor, our buffer pointer 
// would be copied over. In return we would have no new chunk of memory being created but simply
// a pointer pointing to that same block of memory. We create our own copy constructor to ensure a deep copy is made

class String
{
private:
    char* m_Buffer;
    unsigned int m_Size;
public:
    String(const char* string)
    {
        m_Size = strlen(string);
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, string, m_Size);
        m_Buffer[m_Size] = 0;
    }

    // Copy constructor
    String(const String& other)
        : m_Size(other.m_Size)
    {
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
    }

    ~String()
    {
        delete[] m_Buffer;
    }

    char& operator[](unsigned int index)
    {
        return m_Buffer[index];
    }

    friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
    stream << string.m_Buffer;
    return stream;
}

int main(int argc, char* argv[])
{
    String test("Default");
    String testTwo = test;
    return 0;
}