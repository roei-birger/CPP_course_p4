#pragma once

#include <map>
#include <set>
#include "City.hpp"
#include "Color.hpp"
namespace pandemic
{
    class Board
    {
        static std::map<City, int> sickCube;
        static std::map<City, std::set<City>> neighborsCity;
        static std::map<City, bool> researchStation;
        static std::map<City, Color> colors;
        static std::map<City, bool> isDiscoverCure;

    public:
        Board();
        bool is_clean();
        const int operator[](City) const;
        int &operator[](City);
         void remove_cures();

        friend std::ostream &operator<<(std::ostream &os, const Board &b);
    };

}