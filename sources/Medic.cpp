#include "Medic.hpp"

using namespace std;

namespace pandemic
{

    Medic::Medic(Board &b, City c) : Player(b, c)
    {
        if (currBoard.getIsDiscoverCure(Board::colors.at(currCity)))
        {
            currBoard[c] = 0;
        }
    }
    string Medic::role()
    {
        return "Medic";
    }
    Medic &Medic::treat(City c)
    {
        if (currBoard[c] == 0)
        {
            throw invalid_argument("Cannot treat inserted city");
        }

        currBoard[c] = 0;

        return *this;
    }

    Medic &Medic::drive(City c)
    {
        Player::drive(c);
        if (currBoard.getIsDiscoverCure(Board::colors.at(currCity)))
        {
            currBoard[c] = 0;
        }

        return *this;
    }
    Medic &Medic::fly_direct(City c)
    {
        Player::fly_direct(c);
        if (currBoard.getIsDiscoverCure(Board::colors.at(c)))
        {
            currBoard[c] = 0;
        }

        return *this;
    }
    Medic &Medic::fly_charter(City c)
    {
        Player::fly_charter(c);
        if (currBoard.getIsDiscoverCure(Board::colors.at(c)))
        {
            currBoard[c] = 0;
        }

        return *this;
    }
    Medic &Medic::fly_shuttle(City c)
    {
        Player::fly_shuttle(c);
        if (currBoard.getIsDiscoverCure(Board::colors.at(c)))
        {
            currBoard[c] = 0;
        }

        return *this;
    }
};