#ifndef INTROVIEW_H
#define INTROVIEW_H

#include <SFML/Graphics.hpp>

class IntroView {
    sf::RectangleShape rect;
    sf::Font font;
    sf::Text txt;
    sf::Text imie;
    sf::Text indeks;
    sf::Text grupa;
    sf::Texture texture;
    sf::Sprite sprite;
     sf::Texture texture2;
    sf::Sprite sprite2;
     sf::Texture texture3;
    sf::Sprite sprite3;
     sf::Texture texture4;
    sf::Sprite sprite4;
     sf::Texture texture5;
    sf::Sprite sprite5;
     sf::Texture texture6;
    sf::Sprite sprite6;
    sf::Texture texture7;
    sf::Sprite sprite7;





public:
    IntroView();

    void draw(sf::RenderWindow &win);
};


#endif // INTROVIEW_H
