#ifndef OPENING&GAMEOVER_WINDOW_H_INCLUDED
#define OPENING&GAMEOVER_WINDOW_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Snake.h"

class OpeningAndGameoverWindow{
public:
    sf::Text line1, line2, line3;
    sf::Font font;

OpeningAndGameoverWindow();

void draw_openingwindow(sf::RenderWindow& window);

void draw_gameoverwindow(sf::RenderWindow& window, const Snake& snake);

};

#endif // OPENING&GAMEOVER_WINDOW_H_INCLUDED
