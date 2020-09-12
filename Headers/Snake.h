#ifndef Snake_H_INCLUDED
#define Snake_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Field.h"
#include "Sprites&Textures.h"

class Snake{
public:
    struct Snk{
    int x, y;
    };
    Snk snk[100];
    int direction;
    int db;
    int db_at_beginning;

    Snake();

    bool IsOver(Field& field);  // Checks if the head of the snake has hit the walls, or its tail.

    void move_control();   // Function to control the snake.

    void draw_snake(sf::RenderWindow& window, SpritesAndTextures& sprites_and_textures);
};

#endif // Snake_H_INCLUDED
