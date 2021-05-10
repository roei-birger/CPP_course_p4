#include "Player.hpp"
using namespace std;

const int fiveCards = 5;

namespace pandemic
{

    Player::Player(Board &b, City c) : currBoard(b), currCity(c) {}

    Player &Player::drive(City c)
    {

        if (currCity == c || Board::neighborsCity.at(currCity).count(c) == 0)
        {
            throw invalid_argument("Cannot travel to inserted city");
        }
        currCity = c;
        return *this;
    }

    Player &Player::fly_direct(City c)
    {
        if (currCity == c || cards.count(c) == 0)
        {
            throw invalid_argument("Cannot travel to inserted city");
        }
        cards.erase(c);
        currCity = c;
        return *this;
    }

    Player &Player::fly_charter(City c)
    {
        if (currCity == c || cards.count(currCity) == 0)
        {
            throw invalid_argument("Cannot travel to inserted city");
        }
        cards.erase(currCity);
        currCity = c;
        return *this;
    }

    Player &Player::fly_shuttle(City c)
    {
        if (currCity == c || currBoard.getResearchStation(c) == 0 || currBoard.getResearchStation(currCity))
        {
            throw invalid_argument("Cannot travel to inserted city");
        }
        currCity = c;
        return *this;
    }

    Player &Player::build()
    {
        if (cards.count(currCity) == 0)
        {
            throw invalid_argument("Cannot build in inserted city");
        }
        if (currBoard.getResearchStation(currCity) == 0)
        {
            currBoard.setResearchStation(currCity);
            cards.erase(currCity);
        }

        return *this;
    }

    Player &Player::discover_cure(Color c)
    {
        int count = 0;
        for (auto const &i : cards)
        {
            if (Board::colors.at(i) == Board::colors.at(currCity))
            {
                count++;
            }
        }

        if (count < fiveCards || !currBoard.getResearchStation(currCity))
        {
            throw invalid_argument("Cannot discover_cure in inserted city");
        }

        if (currBoard.getResearchStation(currCity) && count >= fiveCards && !currBoard.getIsDiscoverCure(Board::colors.at(currCity)))
        {
            count = fiveCards;
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

    Player &Player::treat(City c)
    {
        if (currBoard[c] == 0)
        {
            throw invalid_argument("Cannot treat inserted city");
        }
        if (currBoard.getIsDiscoverCure(Board::colors.at(currCity)))
        {
            currBoard[c]=0;
        }
        else
        {
            currBoard[c]--;
        }
        return *this;
    }

    string Player::role() { return "Player"; }

    Player &Player::take_card(City c)
    {
        cards.insert(c);
        return *this;
    }

    void Player::remove_cards()
    {
        cards.clear();
    }
};