#include "Board.hpp"
#include <iostream>

using namespace std;

namespace pandemic
{
    Board::Board(){}
    bool Board::is_clean() {return false;}

    int &Board::operator[](City c)
    {

        return sickCube.at(c);
    }

    const int Board::operator[](City c) const
    {

        return sickCube.at(c);
    }

    ostream &operator<<(ostream &os, const Board &b)
    {
        return os;
    }

};