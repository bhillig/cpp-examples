#include <iostream>

// Macros are often useful when you want the preprocessor to include or remove 
// certain bits of code depending on your build configuration or other states you or your team desires

#define DEBUG_BUILD 1

#if DEBUG_BUILD == 1
#define DEBUG_LOG(x) std::cout << x << std::endl
#else
#define DEBUG_LOG(x)
#endif

int main()
{
    DEBUG_LOG("Hello World!");
    return 0;
}
