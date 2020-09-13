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
    int snake_bodyparts;
    int snake_bodyparts_at_start;

    Snake();

    void move_control();

    void matching_keys_to_directions();

    void move_upward();
    void move_downward();
    void move_leftward();
    void move_rightward();

    void draw_snake(sf::RenderWindow& window, SpritesAndTextures& sprites_and_textures) const;

    bool IsGameOver(Field& field) const;

    bool IsWallHit(Field& field) const;
    bool IsBodyHit() const;
};

#endif // Snake_H_INCLUDED
