#include <iostream>
#include <algorithm>
#include <vector>

// Lambdas are an extremely powerful tool for when we want to use an "anyonymous function"
// They allow us to call a function without declaring it if for example we only want to use
// it once or not have it in our global symbols

// They are defined by [](){} (captures, parameters, body)

int main(int argc, char* argv[])
{
    std::vector<int> nums {1, 5, 10, 15, 20};
    auto it = std::find_if(nums.begin(), nums.end(), [](int value){ return value > 10; });
    std::cout << "Element: " << *it << std::endl;
    return 0;
}