#include <sstream>
#include <stdexcept>
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
#include "doctest.h"
#include <stdexcept>
using namespace ariel;
using namespace std;

TEST_CASE("1 player in more than 1 game")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    Player p3("Joe");
    CHECK_THROWS(Game(p2, p3)); // 1
}
TEST_CASE("1 player against himself")
{
    Player p1("Bob");
    CHECK_THROWS(Game(p1, p1)); // 2
}
TEST_CASE("Player Initiation")
{
    Player p1("Bob");
    CHECK_THROWS(Player(NULL));  // 3
    CHECK(p1.cardesTaken() = 0); // 4
    CHECK(p1.stacksize() = 0);   // 5
}
TEST_CASE("Game test")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    CHECK_NOTHROW(game.playAll()); // 6
    CHECK_THROWS(game.playTurn()); // 7
    game.playTurn();
    CHECK(p1.cardesTaken()); // 8
    CHECK(p2.cardesTaken()); // 9
    bool cardtaken = (p1.cardesTaken() > 1) || (p2.cardesTaken() > 1);
    CHECK(cardtaken);                   // 10
    CHECK_THROWS(game.printLastTurn()); // 11
    CHECK_THROWS(game.printLog());      // 12
    CHECK_THROWS(game.printStats());    // 13
    CHECK_THROWS(game.printWiner());    // 14
    bool EmptyStack = (p1.stacksize() == 0) && (p2.stacksize() == 0);
    CHECK(EmptyStack); // 15
    bool DRAW = (p1.stacksize() == 26) && (p2.stacksize() == 26);
    CHECK(DRAW);                                      // 16
    CHECK(p1.cardesTaken() + p2.cardesTaken() == 52); // 17
    game.playAll();
    // Player finished playing.
    CHECK_NOTHROW(Game(Player("Jack"), p1));              // 18
    CHECK_NOTHROW(Game(Player("John"), p2));              // 19
    CHECK_NOTHROW(Game(Player("George"), Player("Mike"))) // 20
}
