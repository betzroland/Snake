#ifndef SPRITES_H_INCLUDED
#define SPRITES_H_INCLUDED
#include <SFML/Graphics.hpp>

class Sprites{
public:
    int pixel;
    sf::Texture tile;
    sf::Sprite sprite_of_field, sprite_of_snake, sprite_of_fruit;

    Sprites();
};


#endif // SPRITES_H_INCLUDED
