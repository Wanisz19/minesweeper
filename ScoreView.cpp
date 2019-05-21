#include "ScoreView.h"

ScoreView::ScoreView(MinesweeperBoard &board):b(board) {
    rect.setSize(sf::Vector2f(200, 100));
    rect.setPosition(100, 200);

    if (!texturelose.loadFromFile("wasted.png")){}
    if (!texturewin.loadFromFile("win.png")){}
}




void ScoreView::draw(sf::RenderWindow &win)
{

if(b.getGameState()==1)
{
 sf::Sprite winsprite(texturewin);
  winsprite.setPosition(0,150);
      win.draw(winsprite);

}

 if(b.getGameState()==2)
{
 sf::Sprite lossprite(texturelose);
  lossprite.setPosition(0,0);
      win.draw(lossprite);

}







}
