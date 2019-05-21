#include "ScoreController.h"

ScoreController::ScoreController(ScoreView &v, MinesweeperBoard&board) : view(v), b(board)
{}

void ScoreController::handleEvent(sf::Event &event) {

    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Space) {
            finished = true;
        }
    }
}
