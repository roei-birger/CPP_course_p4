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
        std::map<Color, bool> isDiscoverCure;

    public:
        static std::map<City, std::set<City>> neighborsCity;
        static std::map<City, Color> colors;

        Board();
        bool is_clean();
        int operator[](City) const;
        int &operator[](City);
        void remove_cures();
        void remove_stations();
        bool getIsDiscoverCure(Color);
        void setIsDiscoverCure(Color);
        bool getResearchStation(City);
        void setResearchStation(City);

        friend std::ostream &operator<<(std::ostream &os, const Board &b);
    };

}