#include "GeneSplicer.hpp"

using namespace std;

const int fiveCards = 5;

namespace pandemic
{

    GeneSplicer::GeneSplicer(Board &b, City c) : Player(b, c) {}
    string GeneSplicer::role()
    {
        return "GeneSplicer";
    }
    GeneSplicer &GeneSplicer::discover_cure(Color c) { 
        int count = cards.size();
                if (count < fiveCards || !currBoard.getResearchStation(currCity))
        {
            throw invalid_argument("Cannot discover_cure in inserted city");
        }

        if (currBoard.getResearchStation(currCity) && count >= fiveCards && !currBoard.getIsDiscoverCure(Board::colors.at(currCity)))
        {
            count = fiveCards;
            currBoard.setIsDiscoverCure(c);
            auto it = cards.begin();
            while (it != cards.end() && count > 0)
            { 
                    cards.erase(it++);
                    count--;

            }
        }
        return *this; }

};    