#ifndef SCORECONTROLLER_H
#define SCORECONTROLLER_H

#include <SFML/Graphics.hpp>
#include "ScoreView.h"
#include "MinesweeperBoard.h"

class ScoreController {
    bool finished = false;
    ScoreView & view;
    MinesweeperBoard &b;

public:
    explicit ScoreController(ScoreView & vs, MinesweeperBoard &board);
    void handleEvent(sf::Event &event);

    // no need to change this
    void draw (sf::RenderWindow & win) { view.draw(win); }
    bool isFinished() const { return finished;}
};


#endif //UNTITLED2_SCORECONTROLLER_H
