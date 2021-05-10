#include "Dispatcher.hpp"

using namespace std;

namespace pandemic
{

    Dispatcher::Dispatcher(Board &b, City c) : Player(b, c) {}
    string Dispatcher::role()
    {
        return "Dispatcher";
    }

    Dispatcher &Dispatcher::fly_direct(City c)
    {
        if (!currBoard.getResearchStation(currCity))
        {
            Player::fly_direct(c);
            return *this;
        }
        if (currCity == c)
        {
            throw invalid_argument("Cannot travel to inserted city");
        }
        currCity = c;
        return *this;
    }

};