#include "doctest.h"
#include "./sources/game.hpp"
#include "./sources/player.hpp"
#include "./sources/card.hpp"

TEST_CASE("1 player in more than 1 game")
{
    Player player1("Alice");
    Player player2("Bob");
    Game game(player1, player2);
    Player player3("Joe");
    CHECK_THROWS(Game(player2, player3));
}
TEST_CASE("1 player against himself")
{
    Player player1("Bob");
    CHECK_THROWS(Game(player1, player1));
}
TEST_CASE("Player Initiation")
{
    Player player1("Bob");
    CHECK_THROWS(Player(NULL));
    CHECK(player1.cardesTaken() == 0);
    CHECK(player1.stacksize() == 0);
}
TEST_CASE("Game test")
{
    Player player1("Alice");
    Player player2("Bob");
    Game game(player1, player2);
    CHECK_NOTHROW(game.playAll());
    CHECK_THROWS(game.playTurn());
    bool EmptyStack = (player1.stacksize() == 0) && (player2.stacksize() == 0);
    CHECK(EmptyStack);
    game.playTurn();
    CHECK(player1.cardesTaken());
    CHECK(player2.cardesTaken());
    bool cardtaken = (player1.cardesTaken() > 1) || (player2.cardesTaken() > 1);
    CHECK(cardtaken);
    CHECK_THROWS(game.printLastTurn());
    CHECK_THROWS(game.printLog());
    CHECK_THROWS(game.printStats());
    CHECK_THROWS(game.printWiner());
    CHECK(player1.cardesTaken() + player2.cardesTaken() == 52);
    game.playAll();
    SUBCASE("DRAW") // 17
    {
        CHECK(player2.stacksize() == 26);
        CHECK(player1.stacksize() == 26);
    }
    // Player finished playing.
    CHECK_NOTHROW(Game(Player("Jack"), player1));
    CHECK_NOTHROW(Game(Player("John"), player2));
    CHECK_NOTHROW(Game(Player("George"), Player("Mike")));
}
