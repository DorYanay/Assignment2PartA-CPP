#include <string>
using namespace std;
#include <iostream>
#include "card.hpp"
using namespace ariel;

class Player
{
private:
    std ::string name;

public:
    Player(std ::string name);
    int stacksize();
    int cardesTaken();
};
