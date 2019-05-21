#ifndef MINESWEEPERCONTROLLER_H
#define MINESWEEPERCONTROLLER_H

#include <SFML/Graphics.hpp>
#include "MSSFMLVIEW.h"

class MinesweeperController {
    bool finished = false;

    MSSFMLVIEW & view;
    MinesweeperBoard & board;
    // ... & model;
public:
    explicit MinesweeperController(MSSFMLVIEW & v, MinesweeperBoard & board);
public:
    void handleEvent(sf::Event &event);

    // no need to change this
    void draw (sf::RenderWindow & win) { view.draw(win); }
    bool isFinished() const { return finished;}
};



#endif // MINESWEEPERCONTROLLER_H
