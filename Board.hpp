#pragma once

#include <map>
#include <set>
#include "City.hpp"
#include "Color.hpp"
namespace pandemic
{
    class Board
    {
        std::map<City, std::set<City>> neighborsCity;
        std::map<City, bool> researchStation;
        std::map<City, int> sickCube;
        std::map<City, Color> colors;
        std::map<City, bool> isDiscover;

    public:
        Board();
        bool is_clean();
        const int operator[](City) const;
        int &operator[](City);

        friend std::ostream &operator<<(std::ostream &os, const Board &b);
    };

}