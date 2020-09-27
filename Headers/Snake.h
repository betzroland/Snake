#ifndef Snake_H_INCLUDED
#define Snake_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Field.h"
#include "Sprites.h"

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

    void move_tail();
    void move_head_upward();
    void move_head_downward();
    void move_head_leftward();
    void move_head_rightward();

    void draw_snake(sf::RenderWindow& window, Sprites& sprites) const;

    bool IsGameOver() const;

    bool IsWallHit() const;
    bool IsBodyHit() const;
};

#endif // Snake_H_INCLUDED
