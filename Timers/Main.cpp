#include <iostream>
#include <chrono>
#include <thread>

struct Timer
{
    std::chrono::time_point<std::chrono::steady_clock> start, end;
    std::chrono::duration<float> duration;
    const char* m_Name;

    explicit Timer(const char* name)
        : m_Name(name), duration(0.0f)
    {
        start = std::chrono::high_resolution_clock::now();
    }

    ~Timer()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        float ms = duration.count() * 1000.f;
        std::cout << "Timer " << m_Name << " took " << ms << " ms." << std::endl;
    }
};

void Func()
{
    Timer timer("Func");
    for (int i = 0; i < 1000; ++i)
    {
        std::cout << "Working...\n";
    }
}

int main()
{
    Func();
    return 0;
}