#pragma once

#include <set>
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

namespace pandemic
{
    class Player
    {
    protected:
        Board &currBoard;
        City currCity;
        std::set<City> cards;

    public:
        Player(Board &, City);

        virtual Player &drive(City);
        virtual Player &fly_direct(City);
        virtual Player &fly_charter(City);
        virtual Player &fly_shuttle(City);
        virtual Player &build();
        virtual Player &discover_cure(Color);
        virtual Player &treat(City);
        virtual Player &take_card(City);
        virtual std::string role();
        void remove_cards();
    };
}