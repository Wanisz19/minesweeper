#include "MinesweeperBoard.h"


using namespace std;



MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode)
{

ResetBoard(width,height,mode);  //POMYSŁ NA TĘ METODĘ W KONSTRUKTORZE NIE MÓJ

}



void MinesweeperBoard::ResetBoard(int width, int height, GameMode mode)
{
    this->width=width;
    this->height=height;
    this->mode=EASY;


    for(int idx=0;idx<(height);idx++)
    {
        for(int idy=0;idy<(width);idy++)
        {
            board[idx][idy].hasMine = 0;
            board[idx][idy].hasFlag = 0;
            board[idx][idy].isRevealed =0;
        }
    }

if(mode==EASY)
    {
        int mines;
        mines=0.1*width*height;
        int counter=0;
       while(mines>counter)
        {
            int x=rand()%width;
            int y=rand()%height;

            if(board[x][y].hasMine==0)
            {
                board[x][y].hasMine=1;
                counter++;
            }
        }
    }

if(mode==NORMAL)
    {
        int mines;
        mines=0.2*width*height;
        int counter=0;
       while(mines>counter)
        {
            int x=rand()%width;
            int y=rand()%height;

            if(board[x][y].hasMine==0)
            {
                board[x][y].hasMine=1;
                counter++;
            }
        }
    }

     if(mode==HARD)
     {


        int mines;
        mines=0.3*height*width+1;
        int counter=0;
        while(mines>counter)
        {
            int x=rand()%width;
            int y=rand()%height;
            if(board[x][y].hasMine==0)
            {
                board[x][y].hasMine=1;
                counter++;
            }
        }
     }




       if(mode==DEBUG)
    {


            for(int idy=0; idy<width; idy++)
            {
                board[width-1][idy].hasMine=1;
            }

            for(int idy=width; idy>=0; idy--)
            {
                for(int idx=height; idx>=0; idx--)
                    if(idx==idy)
                {
                    board[idx][idy].hasMine=1;
                }
            }

            for(int idx=0; idx<width; idx++)
            {
                board[idx][5].hasMine=1;
            }



    }


}







void MinesweeperBoard::debug_display() const
{
    for(int idy=0;idy<height;idy++)
    {
        for(int idx=0;idx<width;idx++)
        {
            //Czy na polu znajduje siê mina

            cout<<"(";
            if(board[idx][idy].hasMine==0)
            {
                cout<<'.';
            }
            else
            {
                cout<<'M';
            }

            //Czy na polu znajduje siê flaga


            if(board[idx][idy].isRevealed==0)
            {
                cout<<'.';
            }
            else
            {
                cout<<'o';
            }

            //Czy pole zosta³o ods³oniête


            if(board[idx][idy].hasFlag==0)
            {
                cout<<'.';
            }
            else
            {
                cout<<'f';
            }
            cout<<')';
        }
        cout<<endl;
    }
}

bool MinesweeperBoard::isRightField(int x, int y) const
{
	if (x < 0 || y < 0 || x > width || y > height)
	{
		return false;
	}
	else
	{
	return true;
	}
}






int MinesweeperBoard::getBoardHeight() const
{
    return MinesweeperBoard::height;
}

int MinesweeperBoard::getBoardWidth() const
{
    return MinesweeperBoard::width;
}

int MinesweeperBoard::getMineCount() const
{
    int MineCount=0;


    if(mode==EASY)
    {
        MineCount=0.1*width*height;
    }
    if(mode==NORMAL)
    {
        MineCount=0.2*width*height;
    }
    if(mode==HARD)
    {
        MineCount=0.3*width*height+1;
    }
   if(mode==DEBUG)
    {

        for(int idy=0; idy<width; idy++)
            {
                MineCount++;
            }

            for(int idy=width; idy>0; idy--)
            {
                for(int idx=height; idx>0; idx--)
                    if(idx==idy)
                {
                    MineCount++;
                }
            }

            for(int idx=0; idx<width; idx++)
            {
                MineCount++;
            }
    }
            return MineCount;
    }


    int MinesweeperBoard::countMines(int x, int y) const             //CountMInes CountMInesCountMInesCountMInesCountMInesCountMInesCountMInes
    {
         int mines_around_field=0;

         if (x<0 || y<0 || x>=width || y>=height)
         {
               return -1;
         }
                 if(board[x][y].isRevealed==0)
         {
                return -1;
         }

         if( board[x][y].isRevealed==1)

         {
             for(int iy=y-1; iy<=y+1; iy++)
             {
                for(int ix=x-1; ix<=x+1; ix++)
                {
                   if(board[ix][iy].hasMine==1 && isRightField(ix, iy))
                   mines_around_field++;
                }

             }

         }
          return mines_around_field;
    }
      bool MinesweeperBoard::hasFlag(int x, int y) const
    {


             if(board[x-1][y-1].hasFlag==1)
             {

                return true;                  // co to znaczy ze funkcja zwraca true
             }


             if( x<0 || y<0 || x> height || x>width || board[x][y].hasFlag==0 || board[x][y].isRevealed==1)
           {
               return false;
           }

    }


 void MinesweeperBoard::toggleFlag(int x, int y)
    {
        int flagi=0;
        int flagi_na_polu_bez_miny=0;

        state=RUNNING;

        if(board[x][y].isRevealed==1 || x<0 || x>width || y<0 || y>height || state==FINISHED_LOSS || state==FINISHED_WIN)
    {}


                else if(board[x][y].hasFlag==1)
                {
                    board[x][y].hasFlag=0;



                }

               else if(board[x][y].hasFlag==0)
                {

                    board[x][y].hasFlag=1;



                        for(int iiy=0; iiy<height; iiy++)
                        {
                            for(int iix=0; iix<width; iix++)
                            {
                                if(board[iix][iiy].hasFlag==1 && board[iix][iiy].hasMine==0)   // sprawdzanie czy na pole bez miny jest odsloniete)
                                {
                                    flagi_na_polu_bez_miny++;

                                }
                                if(board[iix][iiy].hasFlag==1 && board[iix][iiy].hasMine==1 &&flagi_na_polu_bez_miny==0)     //wygrana
                                {
                                    flagi++;
                                    if(flagi==getMineCount())                         // ??????????????????????????????????????????????
                                    {


                                    state=FINISHED_WIN;


                                    }
                                }
                            }
                        }



             }
        }

         void MinesweeperBoard::revealField(int x, int y)
       {

       int sprawdzacz=0;
        int counter_revealed=0;
        int board_size;
        board_size=getBoardHeight()*getBoardWidth();
        int counter_action=0; //first action /sprawdzanie czy wszystkie pola sa zakryte
        state=RUNNING;
        if(board[x][y].isRevealed==1 || x<0 || x>width || y<0
           || y>height ||state==FINISHED_LOSS || state==FINISHED_WIN)
           { }


            if(board[x][y].isRevealed==0 && board[x][y].hasMine==0)
           {
               board[x][y].isRevealed=1;                            // odkrywanie ostatnij miny... wygrana

               for(int iy=0; iy<height; iy++)
               {
                   for(int jx=0; jx<width; jx++)
                   {
                        if(board[jx][iy].isRevealed==0)
                        {
                        sprawdzacz++;
                        }

                        if((sprawdzacz+1)==board_size)
                        {

                        odkrywanie(x,y);

                        }


                       if(board[jx][iy].isRevealed==1)
                       {
                           counter_revealed++;

                           if(counter_revealed==board_size-getMineCount()) // sprawdzanie czy zostały odkryte wszystkie pola bez miny //
                           {
                               state=FINISHED_WIN;
                           }
                       }
                   }
               }
           }

           if(board[x][y].isRevealed==0 && board[x][y].hasMine==1)
           {
               for(int iy=0; iy<width; iy++)
               {
                   for(int jx=0; jx<height; jx++)
                   {
                       if(board[jx][iy].isRevealed==0) //spradzanie first action player, if all filds are not revealed.
                       {
                           counter_action++;
                       }

                   }
                }
           }


             if(counter_action==board_size) //pierwszy ruch //wielkosc tablicy
               {
                   board[x][y].hasMine=0;
                   board[x][y].isRevealed=1;
                   odkrywanie(x,y);
                   int one=0;
                   int X_1;
                   int Y_1;
                   while(one<=0)
                   {

             X_1=rand()%width;
             Y_1=rand()%height;
            if(board[X_1][Y_1].hasMine==0)  //zmiana pola miny
            {
                board[X_1][Y_1].hasMine=1;
                one++;
            }
                   }


               }

               if(counter_action<board_size && board[x][y].hasMine==1)
               {
                   board[x][y].isRevealed=1;
                   if(board[x][y].isRevealed==1&&board[x][y].hasMine==1)
                   state=FINISHED_LOSS;
               }

           }




           bool MinesweeperBoard::isRevealed(int x, int y) const
           {
               if(board[x][y].isRevealed==1)
               {

                   return true;
               }

           }

           GameState MinesweeperBoard::getGameState() const
            {



                return state;
            }


        char MinesweeperBoard::getFieldInfo(int x, int y) const
        {
            if(x<0 || x>width || y<0 || y>height)
            {
                return '#';

            }

            if(board[x][y].isRevealed==0 && board[x][y].hasFlag==1)
            {
                return 'F';
            }

             if(board[x][y].isRevealed==0 && board[x][y].hasFlag==0)
            {
                return '_';
            }

             if(board[x][y].isRevealed==1 && board[x][y].hasMine==1)
            {
                return 'x';
            }

             if(board[x][y].isRevealed==1 && countMines(x,y)==0)
            {
                return ' ';
            }

              if(board[x][y].isRevealed==1 && countMines(x,y)>0)
            {
                return countMines(x,y)+48; //tablica asci
            }



        }

        void MinesweeperBoard::odkrywanie(int x,int y)
            {
           if(board[x][y].isRevealed==1)
                    {
                         for(int iiy=y-2; iiy<=y+3; iiy++ )
                            {
                            for(int iix=x-2; iix<=x+3; iix++)
                                {
                                  if(board[iix][iiy].hasMine==0 && isRightField(iix,iiy))
                                  {
                                    board[iix][iiy].isRevealed=1;


                                  }
                                }
                            }

                    }

            }

              bool MinesweeperBoard::ifhasMine(int x, int y) const
           {
               if(board[x][y].hasMine==1)
               {

                   return true;
               }

           }





           void MinesweeperBoard::SetBoard(int x, int y)
           {
           this->width=x;
           this->height=y;
           }

           void MinesweeperBoard::SetLvL(GameMode mode)
           {
           this->mode=mode;

           }

           void MinesweeperBoard::przegranaa()
    {
                   for(int idy=0;idy<getBoardHeight();idy++)
        {
        for(int idx=0;idx<getBoardWidth();idx++)
        {
        if((board[idx][idy].hasMine==1 && board[idx][idy].isRevealed==0)||(board[idx][idy].hasMine==1 && board[idx][idy].hasFlag==1) )
        {
        board[idx][idy].isRevealed=1;
        }


        }
        }


}

void MinesweeperBoard::SetEasy()
{
this->mode=EASY;
}

void MinesweeperBoard::SetNormal()
{
this-> mode=NORMAL;

}

void MinesweeperBoard::SetHard()
{
this-> mode=HARD;

}

GameMode MinesweeperBoard::GetGameMode() const
{
return mode;
}










