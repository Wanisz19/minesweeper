#include <SFML/Graphics.hpp>
#include "MinesweeperBoard.h"
#ifndef MSSFMLVIEW_H
#define MSSFMLVIEW_H


class MSSFMLVIEW
{


    MinesweeperBoard & board;
    int x0, y0;
    int size_of_field;

public:
    MSSFMLVIEW(int x0, int y0, int size_of_field, MinesweeperBoard &b);

    void draw(sf::RenderWindow &win);
    int getboardsize() const;
    int getx0() const;
    int gety0() const;
    void ButtonPressed (sf::Event &event);

};

#endif
