#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "IntroController.h"
#include "MinesweeperController.h"
#include "ScoreController.h"

class GameManager {
    IntroController &introController;
    MinesweeperController &minesweeperController;
    ScoreController &scoreController;

    enum GameState {
        INTRO, GAME, SCORE
    } state;

    void updateState();
public:
    GameManager(IntroController &ic, MinesweeperController &mc, ScoreController &sc);

    void draw(sf::RenderWindow &win);

    void handleEvent(sf::Event &event);
};


#endif //UNTITLED2_GAMEMANAGER_H
