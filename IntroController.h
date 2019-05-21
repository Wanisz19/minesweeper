#ifndef INTROCONTROLLER_H
#define INTROCONTROLLER_H

#include "IntroView.h"
#include "MinesweeperBoard.h"





enum  class Status { izi,normmal, beng, bengg };

class IntroController {

    int blok1;
    int blok2;
    int width;
    int heigh;
    GameMode mode;
    bool finished = false;
    IntroView & view;
    MinesweeperBoard & b;
    Status stat;

    // IntroModel & model;
public:





    int GetHeighControler() const;
    int GetWidthControler() const;
    explicit IntroController(IntroView & iv, MinesweeperBoard &board);
    void handleEvent(sf::Event &event);

    // no need to change this
    void draw (sf::RenderWindow & win) { view.draw(win); }
    bool isFinished() const { return finished;}
    int blokada1();
    int blokada2();






};


#endif // INTROCONTROLLER_H
