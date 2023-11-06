#include <iostream>

class Entity
{
public:
    Entity()
    {
        std::cout << "Constructed Entity" << std::endl;
    }

    virtual ~Entity()
    {
        std::cout << "Destructed Entity" << std::endl;
    }
};

class Player : public Entity
{
public:
    Player()
    {
        std::cout << "Constructed Player" << std::endl;
    }

    ~Player()
    {
        std::cout << "Destructed Player" << std::endl;
    }
};

int main()
{
    Entity* p = new Player();
    delete p;
    return 0;
}