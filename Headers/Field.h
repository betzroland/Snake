#ifndef FIELD_H_INCLUDED
#define FIELD_H_INCLUDED
#include "Sprites&Textures.h"

class Field{
public:
    int M, N;   // The game field has made of M x N pieces of tiles.

    Field();

    void draw_field(sf::RenderWindow& window, SpritesAndTextures& sprites_and_textures) const;
};

#endif // FIELD_H_INCLUDED
