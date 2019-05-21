#include "IntroView.h"
#include <cstdlib> // abort()


IntroView::IntroView() {
    rect.setSize(sf::Vector2f(990, 990));
    rect.setPosition(5, 5);
    rect.setFillColor(sf::Color(129,121,121));

    if (!font.loadFromFile("/usr/share/fonts/truetype/ubuntu/Ubuntu-B.ttf")) {
        abort();
    }
    txt.setFont(font);
    txt.setString("SAPER");
    txt.setPosition(300, 40);
    txt.setFillColor(sf::Color::Black);
    txt.setCharacterSize(100);

    imie.setFont(font);
    imie.setString("Szymon Oltuszyk");
    imie.setPosition(200, 240);
    imie.setFillColor(sf::Color::Black);
    imie.setCharacterSize(25);

      indeks.setFont(font);
    indeks.setString("nr 249258");
    indeks.setPosition(200, 280);
    indeks.setFillColor(sf::Color::Black);
    indeks.setCharacterSize(25);

      grupa.setFont(font);
    grupa.setString("Grupa wtorek 15:15");
    grupa.setPosition(200, 320);
    grupa.setFillColor(sf::Color::Black);
    grupa.setCharacterSize(25);





    if (!texture.loadFromFile("10x10.png")){}
    if (!texture2.loadFromFile("20x15.png")){}
    if (!texture3.loadFromFile("30x15.png")){}
     if (!texture4.loadFromFile("easy.png")){}
      if (!texture5.loadFromFile("normal.png")){}
       if (!texture6.loadFromFile("hard.png")){}
       if (!texture7.loadFromFile("start.png")){}











}

void IntroView::draw(sf::RenderWindow &win) {
    win.draw(rect);
    win.draw(txt);
    win.draw(imie);
     win.draw(indeks);
      win.draw(grupa);



 sf::Sprite sprite(texture);
  sprite.setPosition(100,600);
      win.draw(sprite);


      sf::Sprite sprite2(texture2);
  sprite2.setPosition(250,600);
      win.draw(sprite2);

      sf::Sprite sprite3(texture3);
  sprite3.setPosition(400,600);
      win.draw(sprite3);

       sf::Sprite sprite4(texture4);
  sprite4.setPosition(100,750);
      win.draw(sprite4);

       sf::Sprite sprite5(texture5);
  sprite5.setPosition(250,750);
      win.draw(sprite5);

       sf::Sprite sprite6(texture6);
  sprite6.setPosition(400,750);
      win.draw(sprite6);

       sf::Sprite sprite7(texture7);
  sprite7.setPosition(700,700);
      win.draw(sprite7);


}
