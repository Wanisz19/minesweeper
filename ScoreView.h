#ifndef SCOREVIEW_H
#define SCOREVIEW_H

#include <SFML/Graphics.hpp>
#include "MinesweeperBoard.h"

class ScoreView {
    sf::RectangleShape rect;
     sf::Texture texturelose;
    sf::Sprite spritelose;
    sf::Texture texturewin;
    sf::Sprite spritewin;
    MinesweeperBoard &b;

public:
    ScoreView(MinesweeperBoard &board);

    void draw(sf::RenderWindow &win);
};


#endif //UNTITLED2_SCOREVIEW_H
