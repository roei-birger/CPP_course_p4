#include "FieldDoctor.hpp"

using namespace std;

namespace pandemic
{

    FieldDoctor::FieldDoctor(Board &b, City c) : Player(b, c) {}
    string FieldDoctor::role()
    {
        return "FieldDoctor";
    }
    FieldDoctor &FieldDoctor::treat(City c)
    {
        if (c == currCity)
        {
            Player::treat(c);
            return *this;
        }
        
        if (currBoard[c] == 0 || Board::neighborsCity.at(currCity).count(c) == 0)
        {
            throw invalid_argument("Cannot treat inserted city");
        }
        if (currBoard.getIsDiscoverCure(Board::colors.at(c)))
        {
            currBoard[c] = 0;
        }
        else
        {
            currBoard[c]--;
        }
        return *this;
    }

};