#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED
#include "Snake.h"
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

    void draw_gameover(sf::RenderWindow& window, const int db); // Drawing game over window with the score.

    void draw_snake(sf::RenderWindow& window, const int db, Snk* snk);  // Drawing the snake.

    void draw_fruit(sf::RenderWindow& window, const Fruit fruit);   // Drawing the fruit.

};

#endif // DRAW_H_INCLUDED
