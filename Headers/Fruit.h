#ifndef FRUIT_H_INCLUDED
#define FRUIT_H_INCLUDED
#include "Field.h"
#include "Sprites&Textures.h"
#include "Snake.h"

class Fruit{
public:
    int x, y;

    Fruit(Field& field);

    void fruit_generator(Snake& snake, Field& field);  // Generates new fruits.

    void draw_fruit(sf::RenderWindow& window, SpritesAndTextures& sprites_and_textures);

};

#endif // FRUIT_H_INCLUDED
