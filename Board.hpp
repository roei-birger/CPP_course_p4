#pragma once
namespace pandemic
{
    class Board
    {
    public:
        Board(){};
        bool is_clean();
        int operator[](City) const;
        int &operator[](City);

        friend std::ostream &operator<<(std::ostream &os, const Board &b);
    };

}