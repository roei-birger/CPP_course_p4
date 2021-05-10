#include "Virologist.hpp"

using namespace std;

namespace pandemic
{

    Virologist::Virologist(Board &b, City c) : Player(b, c) {}
    string Virologist::role()
    {
        return "Virologist";
    }
    Virologist &Virologist::treat(City c)
    {
        if (currBoard[c] == 0 || cards.count(c) == 0)
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
        cards.erase(c);
        return *this;
    }

};