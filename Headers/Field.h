#ifndef FIELD_H_INCLUDED
#define FIELD_H_INCLUDED
#include "Sprites&Textures.h"

class Field{
public:
    static const int M=18;   // The game field has made of M x N pieces of tiles.
    static const int N=24;

    void draw_field(sf::RenderWindow& window, SpritesAndTextures& sprites_and_textures) const;
};

#endif // FIELD_H_INCLUDED
