#include "MinesweeperController.h"

MinesweeperController::MinesweeperController(MSSFMLVIEW &v, MinesweeperBoard &board) :view(v), board(board)
{}

void MinesweeperController::handleEvent(sf::Event &event) {

    if (board.getGameState()==2)
     {
    board.przegranaa();


    if(board.getGameState()==2  && event.type == sf::Event::MouseButtonPressed)
    {
    if (event.mouseButton.button == sf::Mouse::Left)
    {
    finished = true;

    }

    }


    }

    if (board.getGameState()==1)

    {

    finished = true;
    }










if (event.type == sf::Event::MouseButtonPressed)
{

    int kolumna;
    int wiersz;


    if((event.mouseButton.x>=view.getx0() && event.mouseButton.x<=view.getboardsize()*board.getBoardWidth()+view.getx0())&&(event.mouseButton.y>=view.gety0() && event.mouseButton.y<=view.getboardsize()*board.getBoardHeight()+view.gety0()))
{
    kolumna=((event.mouseButton.x)-view.getx0())/view.getboardsize();
    wiersz=((event.mouseButton.y)-view.gety0())/view.getboardsize();

    if(kolumna==board.getBoardHeight() || wiersz==board.getBoardWidth())
    {
    kolumna=board.getBoardHeight()-1;
    wiersz=board.getBoardWidth()-1;
    }
    if (event.mouseButton.button == sf::Mouse::Left)
    {
        system("clear");
        cout<<board.getGameState();
        board.revealField(kolumna,wiersz);
        board.debug_display();
        if(board.getGameState()==2)       //dodatkowe pole
        {
        cout<<endl<<"PRZEEEEEEGRAAAAANAAAA"<<endl;
        }
    }

    if (event.mouseButton.button == sf::Mouse::Right)
    {
       board.toggleFlag(kolumna,wiersz);

    }

    }

}





}
