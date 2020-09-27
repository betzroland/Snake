#ifndef FIELD_H_INCLUDED
#define FIELD_H_INCLUDED
#include "Sprites.h"

class Field{
public:
    static const int height=18;
    static const int width=24;

    void draw_field(sf::RenderWindow& window, Sprites& sprites) const;
};

#endif // FIELD_H_INCLUDED
