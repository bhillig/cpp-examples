#include <iostream>

namespace engine {

    void init()
    {
        std::cout << "Initializing Engine!" << std::endl;
    }
}

namespace application {

    void init()
    {
        std::cout << "Initializing Application" << std::endl;
    }
}

int main()
{
    {
        using namespace engine;
        init();
    }

    application::init();

    namespace app = application;
    app::init();
    
    return 0;
}