#include <string>
#include <iostream>
#include "player.hpp"
#pragma once

class Game
{
private:
public:
    Game(Player player1, Player player2);
    void playTurn();
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();
};
namespace ariel
{
};