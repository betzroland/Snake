#ifndef OPENANDGAMEOVERWINDOW_H_INCLUDED
#define OPENANDGAMEOVERWINDOW_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Snake.h"

class OpenAndGameoverWindow{
public:
    sf::Text line1, line2, line3;
    sf::Font font;

OpenAndGameoverWindow();

void draw_openingwindow(sf::RenderWindow& window);

void draw_gameoverwindow(sf::RenderWindow& window, const Snake& snake);

};


#endif // OPENANDGAMEOVERWINDOW_H_INCLUDED
