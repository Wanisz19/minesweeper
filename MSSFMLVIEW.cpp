#include "MSSFMLVIEW.h"
#include <cstdlib>



MSSFMLVIEW::MSSFMLVIEW(int x0, int y0, int size_of_field, MinesweeperBoard &b):board(b)

{

MSSFMLVIEW::x0=x0;
MSSFMLVIEW::y0=y0;
MSSFMLVIEW::size_of_field=size_of_field;
sf::Event event;



}

    int MSSFMLVIEW::getboardsize() const
    {
    return MSSFMLVIEW::size_of_field;
    }
    int MSSFMLVIEW::getx0() const
    {
    return MSSFMLVIEW::x0;
    }
    int MSSFMLVIEW::gety0() const
    {
    return MSSFMLVIEW::y0;
    }


 void MSSFMLVIEW::draw(sf::RenderWindow &win)
{

sf::Text text;
sf::Font font;
if (font.loadFromFile("arial.ttf"))
text.setFont(font);

for(int y=0; y<board.getBoardHeight(); y++)
{

for(int x=0; x<board.getBoardWidth(); x++)
{


// pole zakryte
sf::RectangleShape rectangle(sf::Vector2f(30.f, 30.f)); // nie można wywołać fukcji getboardsize
rectangle.setOutlineThickness(1.f);
rectangle.setOutlineColor(sf::Color(23, 7, 249));


int wierszy;
int kolumnax;
kolumnax=x*size_of_field+x0;
wierszy=y*size_of_field+y0;

if(board.getFieldInfo(x,y)=='_')
{
rectangle.setFillColor(sf::Color(249, 7, 225));
rectangle.setPosition(kolumnax,wierszy);
win.draw(rectangle);
}

else if(board.getFieldInfo(x,y)=='F')
{
text.setCharacterSize(size_of_field);
text.setFillColor(sf::Color::Yellow);

rectangle.setFillColor(sf::Color(64, 60, 60));
rectangle.setPosition(kolumnax,wierszy);
win.draw(rectangle);
text.setPosition(kolumnax,wierszy);
text.setString("F");
win.draw(text);
}

else if(board.isRevealed(x,y)==1 && board.ifhasMine(x,y)==0) //liczba min wokół pola
{
rectangle.setFillColor(sf::Color(64, 60, 60));
rectangle.setPosition(kolumnax,wierszy);
win.draw(rectangle);


text.setCharacterSize(size_of_field/2);
text.setFillColor(sf::Color::Red);
text.setPosition(kolumnax,wierszy);

int liczba_min;

liczba_min= board.countMines(x,y);

switch(liczba_min)
{
case 1:
text.setString("1");
win.draw(text);
break;

case 2:
text.setString("2");
win.draw(text);
break;

case 3:
text.setString("3");
win.draw(text);
break;

case 4:
text.setString("4");
win.draw(text);
break;

case 5:
text.setString("5");
win.draw(text);
break;

case 6:
text.setString("6");
win.draw(text);
break;

case 7:
text.setString("7");
win.draw(text);
break;

case 8:
text.setString("8");
win.draw(text);
break;
}

}


else if(board.getFieldInfo(x,y)=='x' && board.ifhasMine(x,y)==1)
{
text.setCharacterSize(size_of_field);
text.setFillColor(sf::Color::Blue);

rectangle.setFillColor(sf::Color(64, 60, 60));
rectangle.setPosition(kolumnax,wierszy);
win.draw(rectangle);
text.setPosition(kolumnax,wierszy);
text.setString("M");
win.draw(text);



}










}
}

}















