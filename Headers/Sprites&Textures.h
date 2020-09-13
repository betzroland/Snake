#ifndef SPRITES&TEXTURES_H_INCLUDED
#define SPRITES&TEXTURES_H_INCLUDED
#include <SFML/Graphics.hpp>

class SpritesAndTextures{
public:
    int pixel;
    sf::Texture tile;
    sf::Sprite sprite_of_field, sprite_of_snake, sprite_of_fruit;

    SpritesAndTextures();
};

#endif // SPRITES&TEXTURES_H_INCLUDED
