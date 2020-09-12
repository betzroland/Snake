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
    int number_of_snk_elements;
    int snk_elements_at_start;

    Snake();

    bool IsGameOver(Field& field) const;

    void move_control();

    void draw_snake(sf::RenderWindow& window, SpritesAndTextures& sprites_and_textures) const;
};

#endif // Snake_H_INCLUDED
