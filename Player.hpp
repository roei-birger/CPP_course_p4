#pragma once

#include <set>
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

namespace pandemic
{
    class Player
    {

        Board board;
        City currCity;
        std::set<City> cards;

    public:
        Player(Board &, City);

        Player &drive(City);
        Player &fly_direct(City);
        Player &fly_charter(City);
        Player &fly_shuttle(City);
        Player &build();
        Player &discover_cure(Color);
        Player &treat(City);
        Player &take_card(City);
        std::string role();
    };
}