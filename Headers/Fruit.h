#ifndef FRUIT_H_INCLUDED
#define FRUIT_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Field.h"
#include "Sprites&Textures.h"
#include "Snake.h"

class Fruit{
public:
    int x, y;

    Fruit();

    void fruit_generator(const Snake& snake);

    void eat_fruit(Snake& snake);

    void draw_fruit(sf::RenderWindow& window, SpritesAndTextures& sprites_and_textures) const;

};

    inline void Fruit::eat_fruit(Snake& snake){
        if(x==snake.snk[0].x && y==snake.snk[0].y){
            snake.snake_bodyparts++;
            x=rand()%Field::N;
            y=rand()%Field::M;
        }
    }

    inline void Fruit::draw_fruit(sf::RenderWindow& window, SpritesAndTextures& sprites_and_textures) const{
        sprites_and_textures.sprite_of_fruit.setPosition(x*sprites_and_textures.pixel, y*sprites_and_textures.pixel);
        window.draw(sprites_and_textures.sprite_of_fruit);
    }

#endif // FRUIT_H_INCLUDED
