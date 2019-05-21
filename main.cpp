#include "MinesweeperBoard.h"
#include "MSTextController.h"
#include "MSBoardTextView.h"
#include "MSSFMLVIEW.h"


#include "IntroController.h"
#include "IntroView.h"
#include "MinesweeperController.h"
#include "ScoreController.h"
#include "ScoreView.h"
#include "GameManager.h"


int main()
{



srand( time( NULL ) );
sf::RenderWindow window(sf::VideoMode(1000, 1000), "SAPEREK");



MinesweeperBoard board(0,0,EASY);
IntroView iv;
IntroController ic(iv,board);



MSBoardTextView textview(board);
MSTextController controller(board, textview);



MSSFMLVIEW view(5,5,30,board);
MinesweeperController mc(view, board);


ScoreView sv(board);
ScoreController sc(sv,board);


    GameManager gm(ic, mc, sc);





    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();




             gm.handleEvent(event);

        }



        window.clear();

        gm.draw(window);

        // Update the window
        window.display();
    }




//MSBoardTextView view( board);
//view.display();
//MSTextController ctrl ( board, view );
//ctrl.play();
//cout<<endl;

//board.debug_display();




    return EXIT_SUCCESS;   //return exit_success a return 0;
}
