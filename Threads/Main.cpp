#include <iostream>
#include <thread>

static bool s_Finished = false;

void DisplayWorking()
{
    using namespace std::literals::chrono_literals;

    std::cout << "Started thread with id=" << std::this_thread::get_id() << std::endl;

    while (!s_Finished)
    {
        std::cout << "Working..." << std::endl;
        std::this_thread::sleep_for(1s);
    }
}

int main(int argc, char* argv[])
{
    std::thread threadTwo(DisplayWorking);

    std::cin.get();
    s_Finished = true;
    threadTwo.join();

    std::cout << "Finished job." << std::endl;
    std::cin.get();
    return 0;
}