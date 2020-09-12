#ifndef OPENING&GAMEOVER_WINDOW_H_INCLUDED
#define OPENING&GAMEOVER_WINDOW_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Snake.h"

class Opening_and_gameover_window{
public:
    sf::Text text1, text2, text3;
    sf::Font font;

Opening_and_gameover_window();

void draw_openingwindow(sf::RenderWindow& window);

void draw_gameover(sf::RenderWindow& window, Snake& snake);

};

#endif // OPENING&GAMEOVER_WINDOW_H_INCLUDED
