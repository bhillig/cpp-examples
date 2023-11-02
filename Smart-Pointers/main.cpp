#include <iostream>
#include <memory>

class Player
{
public:
    const char* m_Name;
    Player()
        : m_Name("Default")
    {
        std::cout << "Instantiated " << m_Name << "!" << std::endl;
    }

    explicit Player(const char* name)
        : m_Name(name)
    {
        std::cout << "Instantiated " << m_Name << "!" << std::endl;
    }

    ~Player()
    {
        std::cout << "Destroyed " << m_Name << "!" << std::endl;
    }
};

// This function takes a shared_ptr<Player> as a parameter and creates one in the body
// Since the copy constructor is used here, it's internal ref count goes up one allowing 
// the pointer to remain alive outside of this function, despite being created here
void MakePlayer(std::shared_ptr<Player>& coolPlayer)
{
    std::cout << "START OF MAKE PLAYER" << std::endl;
    std::shared_ptr<Player> newPlayer = std::make_shared<Player>("New player");
    coolPlayer = newPlayer;
    std::cout << "END OF MAKE PLAYER" << std::endl;
}

int main(int argc, char* argv[])
{
    std::cout << "START OF MAIN" << std::endl;
    std::weak_ptr<Player> weakPlayer;
    std::unique_ptr<Player> player = std::make_unique<Player>("main ptr");
    {
        std::shared_ptr<Player> coolPlayer;
        MakePlayer(coolPlayer);

        // Since this is a weak pointer, this will not increase its reference count and will still die
        // when this scope ends 
        weakPlayer = coolPlayer; 

        std::unique_ptr<Player> player = std::make_unique<Player>();
    }

    std::cout << "END OF MAIN" << std::endl;
    return 0;
}