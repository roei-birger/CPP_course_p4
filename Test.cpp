#include "doctest.h"

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

#include <iostream>
#include <stdexcept>

using namespace pandemic;
using namespace std;

Board board; // Initialize an empty board (with 0 disease cubes in any city).

TEST_CASE("Initialize a board ")
{
    CHECK(board.is_clean() == true);
    board[City::Kinshasa] = 3;      // put 3 yellow disease cubes in Kinshasa.
    board[City::Kinshasa] = 2;      // change number of disease cubes in Kinshasa to 2.
    board[City::HongKong] = 3;      // put 3 yellow disease cubes in MexicoCity
    board[City::HoChiMinhCity] = 1; // put 1 red disease cube in HoChiMinhCity
    board[City::Chicago] = 1;       // put 1 blue disease cube in Chicago
    board[City::Bogota] = 1;        // put 1 blue disease cube in Bogota
    board[City::Delhi] = 2;         // put 1 blue disease cube in Bogota
}

TEST_CASE("OperationsExpert test")
{
    OperationsExpert player{board, City::Atlanta};
    player.take_card(City::Johannesburg)
        .take_card(City::Khartoum)
        .take_card(City::SaoPaulo)
        .take_card(City::BuenosAires)
        .take_card(City::HoChiMinhCity);

    CHECK_NOTHROW(player.build(););
    CHECK_NOTHROW(player.drive(City::Chicago););
    CHECK_NOTHROW(player.fly_direct(City::HoChiMinhCity));
    CHECK_THROWS(player.fly_direct(City::HoChiMinhCity));
}

TEST_CASE("Dispatcher test")
{
    Dispatcher player{board, City::SanFrancisco};
    player.take_card(City::Atlanta)
        .take_card(City::Mumbai)
        .take_card(City::Algiers)
        .take_card(City::Taipei)
        .take_card(City::Cairo);

    CHECK_NOTHROW(player.fly_direct(City::Atlanta););
    CHECK_NOTHROW(player.fly_direct(City::LosAngeles));
    CHECK_NOTHROW(player.drive(City::Sydney));
    CHECK_THROWS(player.build();); //without Sydney card
    CHECK_EQ(player.role(), string("Dispatcher"));
}

TEST_CASE("Scientist test")
{
    Scientist player{board, City::Bogota, 2};
    player.take_card(City::Bogota)
        .take_card(City::Seoul)
        .take_card(City::Mumbai)
        .take_card(City::Cairo)
        .take_card(City::Delhi);

    CHECK_NOTHROW(player.build(););
    CHECK_THROWS(player.discover_cure(Color::Yellow););
    player.take_card(City::Santiago);
    CHECK_NOTHROW(player.discover_cure(Color::Yellow););
    CHECK_EQ(player.role(), string("Scientist"));

    CHECK_FALSE(board.is_clean());
}

TEST_CASE("Researcher test")
{
    Researcher player{board, City::Delhi};
    player.take_card(City::Bogota) //Yellow
        .take_card(City::Santiago) //Yellow
        .take_card(City::SaoPaulo) //Yellow
        .take_card(City::Miami)    //Yellow
        .take_card(City::Delhi);   //Yellow

    CHECK_NOTHROW(player.discover_cure(Color::Yellow););

    player.take_card(City::Bogota) //Yellow
        .take_card(City::Santiago) //Yellow
        .take_card(City::SaoPaulo) //Yellow
        .take_card(City::Miami)    //Yellow
        .take_card(City::Delhi);   //Yellow

    CHECK_NOTHROW(player.discover_cure(Color::Yellow););
    CHECK_NOTHROW(player.treat(City::Delhi););
    CHECK_THROWS(player.treat(City::Delhi););
    CHECK_EQ(player.role(), string("Researcher"));
}

TEST_CASE("Medic test")
{
    Medic player{board, City::HongKong};
    player.take_card(City::Bogota)
        .take_card(City::Seoul)
        .take_card(City::HongKong)
        .take_card(City::Cairo)
        .take_card(City::Delhi);

    CHECK_NOTHROW(player.fly_direct(City::Bogota););
    CHECK(board[City::Bogota] == 0);
    CHECK_THROWS(player.fly_shuttle(City::HongKong););
    CHECK_NOTHROW(player.fly_charter(City::HongKong););
    CHECK_NOTHROW(player.treat(City::HongKong););
    CHECK(board[City::Bogota] == 0);
    CHECK_THROWS(player.treat(City::HongKong););
    CHECK_NOTHROW(player.build(););
    CHECK_NOTHROW(player.fly_shuttle(City::Bogota););
    CHECK_EQ(player.role(), string("Medic"));
}

TEST_CASE("Virologist test")
{

    board[City::Cairo] = 3;

    Virologist player{board, City::HongKong};
    player.take_card(City::Bogota)
        .take_card(City::Seoul)
        .take_card(City::HongKong)
        .take_card(City::Cairo)
        .take_card(City::Delhi);

    CHECK_NOTHROW(player.treat(City::Cairo););
    CHECK(board[City::Cairo] == 2);
    CHECK_THROWS(player.treat(City::Cairo););

    CHECK_EQ(player.role(), string("Virologist"));
}

TEST_CASE("GeneSplicer test")
{

    board[City::Kinshasa] = 3;

    GeneSplicer player{board, City::Kinshasa};
    player.take_card(City::SanFrancisco)
        .take_card(City::Kinshasa)
        .take_card(City::Essen)
        .take_card(City::Lima)
        .take_card(City::LosAngeles)
        .take_card(City::London);

    CHECK_NOTHROW(player.build(););
    CHECK_NOTHROW(player.discover_cure(Color::Yellow););
    CHECK_THROWS(player.discover_cure(Color::Yellow););
    CHECK_THROWS(player.treat(City::Kinshasa););
    CHECK(board[City::Kinshasa] == 0);

    CHECK_EQ(player.role(), string("GeneSplicer"));
}

TEST_CASE("FieldDoctor test")
{

    board[City::Johannesburg] = 3;
    board[City::Lagos] = 3;
    board[City::Kinshasa] = 3;

    Virologist player{board, City::Khartoum};
    player.take_card(City::Johannesburg)
        .take_card(City::Seoul)
        .take_card(City::HongKong)
        .take_card(City::Cairo)
        .take_card(City::Delhi);

    CHECK_NOTHROW(player.treat(City::Johannesburg););
    CHECK(board[City::Johannesburg] == 2);
    CHECK_THROWS(player.treat(City::Johannesburg););

    CHECK_NOTHROW(player.treat(City::Lagos););
    CHECK(board[City::Lagos] == 2);
    CHECK_THROWS(player.treat(City::Lagos););

    CHECK_NOTHROW(player.treat(City::Kinshasa););
    CHECK(board[City::Kinshasa] == 2);
    CHECK_THROWS(player.treat(City::Kinshasa););

    CHECK_EQ(player.role(), string("FieldDoctor"));
}