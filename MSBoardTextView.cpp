#include "MSBoardTextView.h"

MSBoardTextView::MSBoardTextView(MinesweeperBoard &b)
            :board(b)
            {
            }

void MSBoardTextView::display() const
{

for(int iy=0; iy<(board.getBoardHeight()); iy++ )
    {
        cout<<endl;
        for(int ix=0; ix<(board.getBoardWidth()); ix++  )
        {
         cout<<"{"<<board.getFieldInfo(ix,iy)<<"}";
        }

    }

}
