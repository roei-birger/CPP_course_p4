#include "Board.hpp"
#include "City.hpp"
#include <iostream>

using namespace std;

namespace pandemic
{
    Board::Board(){};
    bool Board::is_clean() {}

    int &Board::operator[](City c)
    {
        int x;
        x=3;
        return x;
    }

    ostream &operator<<(ostream &os, const Board &b)
    {
        return os;
    }

};