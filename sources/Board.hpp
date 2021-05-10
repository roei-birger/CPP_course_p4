#pragma once

#include <map>
#include <set>
#include "City.hpp"
#include "Color.hpp"
namespace pandemic
{
    class Board
    {
        std::map<City, int> sickCube;
        std::map<City, bool> researchStation;
        std::map<City, bool> isDiscoverCure;

    public:
        static std::map<City, std::set<City>> neighborsCity;
        static std::map<City, Color> colors;

        Board();
        bool is_clean();
        const int operator[](City) const;
        int &operator[](City);
        void remove_cures();
        void remove_stations();

        friend std::ostream &operator<<(std::ostream &os, const Board &b);
    };

}