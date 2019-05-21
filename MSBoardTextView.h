#ifndef MSBOARDTEXTVIEW_H
#define MSBOARDTEXTVIEW_H


#include "MinesweeperBoard.h"


class MSBoardTextView{

    MinesweeperBoard &board;

public:

    MSBoardTextView (MinesweeperBoard &b);
    void display() const;

};
#endif
