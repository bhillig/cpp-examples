#include <iostream>
#include <vector>

// This program's goal is to demonstrate some examples of how function pointers can be used as programmers in C++

void PrintHelloWorld()
{
    std::cout << "Message received" << std::endl;
}

template<typename T>
void Print(T value)
{
    std::cout << value << std::endl;
}

void ForEach(const std::vector<int>& nums, void(*func)(int))
{
    for(int num : nums)
    {
        func(num);
    }
}

int main()
{   
    // Example 1
    auto function = &PrintHelloWorld;
    function();

    // Example 2
    typedef void(*PrintMessageWithCharFunc)(const char*);
    PrintMessageWithCharFunc print = Print;
    print("Hi!");

    // Example 3
    std::vector<int> nums{1, 2, 3, 4, 5};
    ForEach(nums, Print);


    return 0;
}