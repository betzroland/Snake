#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED
#include "Engine.h"
#include "Fruit.h"

class Draw{
public:
    int M, N;
    sf::Texture texture;
    sf::Sprite sprite1, sprite2;
    int pixel;

    Draw(); // Initializing class variables.

    void draw_openingwindow(sf::RenderWindow& window);  // Draws the opening window (when the game starts).

    void draw_field(sf::RenderWindow& window);  // Drawing the game field.

    void draw_gameover(sf::RenderWindow& window, int& db); // Drawing game over window with the score.

    void draw_snake(sf::RenderWindow& window, int& db, Snake* snake);

    void draw_fruit(sf::RenderWindow& window, Fruit& fruit);

};

#endif // DRAW_H_INCLUDED
