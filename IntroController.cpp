#include "IntroController.h"
#include "MinesweeperBoard.h"
#include "IntroView.h"
using namespace std;
#include <iostream>


IntroController::IntroController(IntroView & iv, MinesweeperBoard &board): view(iv), b(board)

{
stat=Status::izi;

}

int IntroController::GetWidthControler() const
{
return width;
}

int IntroController::GetHeighControler() const
{
return heigh;
}

int IntroController::blokada1()
{
this->blok1+=1;

}

int IntroController::blokada2()
{
this->blok2+=1;
}



void IntroController::handleEvent(sf::Event &event)
 {


 if (event.type == sf::Event::MouseButtonPressed)
{

    if (event.mouseButton.button == sf::Mouse::Left)
    {


    if (event.mouseButton.x>100 && event.mouseButton.x<=200 && event.mouseButton.y>600 && event.mouseButton.y<=700)
    {
            blokada1();
            width=10;
            heigh=10;
            b.SetBoard(width,heigh);



    }

        if (event.mouseButton.x>250 && event.mouseButton.x<=350 && event.mouseButton.y>600 && event.mouseButton.y<=700)
    {
            blokada1();
            width=20;
            heigh=15;
            b.SetBoard(width,heigh);


    }
      if (event.mouseButton.x>400 && event.mouseButton.x<=500 && event.mouseButton.y>600 && event.mouseButton.y<=700)
    {
            blokada1();
            width=30;
            heigh=20;
            b.SetBoard(width,heigh);


    }


     if (event.mouseButton.x>100 && event.mouseButton.x<=200 && event.mouseButton.y>750 && event.mouseButton.y<=850)
    {

            blokada2();
            b.SetEasy();


    }

    if (event.mouseButton.x>250 && event.mouseButton.x<=350 && event.mouseButton.y>750 && event.mouseButton.y<=850)
    {
            blokada2();
            b.SetNormal();


    }

    if (event.mouseButton.x>400 && event.mouseButton.x<=500 && event.mouseButton.y>750 && event.mouseButton.y<=850)
    {
            blokada2();
            b.SetHard();


    }






            if(event.mouseButton.x>700 && event.mouseButton.x<=800 && event.mouseButton.y>700 && event.mouseButton.y<=800 )
            {

                if(blok1>0 && blok2>0)
                {
                b.ResetBoard(GetHeighControler(),GetHeighControler(),b.GetGameMode());
                 finished = true;
                }


            }




}

}
}












