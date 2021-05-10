#include "Scientist.hpp"

using namespace std;

namespace pandemic
{

    Scientist::Scientist(Board &b, City c, int n) : Player(b, c), num(n) {}
    string Scientist::role()
    {
        return "Scientist";
    }

    Scientist &Scientist::discover_cure(Color c)
    {
        int count = 0;
        for (auto const &i : cards)
        {
            if (Board::colors.at(i) == Board::colors.at(currCity))
            {
                count++;
            }
        }

        if (count < num || !currBoard.getResearchStation(currCity))
        {
            throw invalid_argument("Cannot discover_cure in inserted city");
        }

        if (currBoard.getResearchStation(currCity) && count >= num && !currBoard.getIsDiscoverCure(Board::colors.at(currCity)))
        {
            count = num;
            currBoard.setIsDiscoverCure(c);
            auto it = cards.begin();
            while (it != cards.end() && count > 0)
            {
                if (Board::colors.at(*it) == c)
                {
                    cards.erase(it++);
                    count--;
                }
                else
                {
                    ++it;
                }
            }
        }

        return *this;
    }

};