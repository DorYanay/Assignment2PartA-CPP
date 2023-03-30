#include <string>
#include <iostream>
#include "card.hpp"
#pragma once

class Player
{
private:
    std ::string name;

public:
    Player(std ::string name);
    int stacksize();
    int cardesTaken();
};
