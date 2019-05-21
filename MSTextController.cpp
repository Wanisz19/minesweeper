 #include "MSTextController.h"


    MSTextController::MSTextController(MinesweeperBoard &b, MSBoardTextView &v)
    :board(b), view(v)
    {}


void MSTextController::play() const
    {

int decyzja, x, y;
    do
    {





    std::system("clear");
    view.display();
    cout<<endl;
    cout<<board.getGameState();
    cout<<endl;
    cout<<"Wybież opcję:"<<endl;
    cout<<"Odkryj Pole:1"<<endl;
    cout<<"Postaw Flage:2"<<endl;
    cin>>decyzja;
    if(decyzja==1)
    {
    cout<<"Podaj Pole ktore chcesz odkryc:"<<endl;
    cout<<"X:";
    cin>>x;
    cout<<"Y:";
    cin>>y;
    board.revealField(x,y);

    }
    else if(decyzja==2)
    {
    cout<<"Podaj Pole na którym chcesz postawic flage:"<<endl;
    cout<<"X:";
    cin>>x;
    cout<<"Y:";
    cin>>y;
    board.toggleFlag(x,y);
    }

    } while(board.getGameState()==0);

    }
