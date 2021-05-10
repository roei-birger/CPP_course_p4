#include "Researcher.hpp"

using namespace std;

const int fiveCards = 5;

namespace pandemic
{

    Researcher::Researcher(Board &b, City c) : Player(b, c) {}
    string Researcher::role()
    {
        return "Researcher";
    }

    Researcher &Researcher::discover_cure(Color c)
    {
        int count = 0;
        for (auto const &i : cards)
        {
            if (Board::colors.at(i) == Board::colors.at(currCity))
            {
                count++;
            }
        }

        if (count < fiveCards)
        {
            throw invalid_argument("Cannot discover_cure in inserted city");
        }

        if (count >= fiveCards && !currBoard.getIsDiscoverCure(Board::colors.at(currCity)))
        {
            count = fiveCards;
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
