#ifndef FRUIT_H_INCLUDED
#define FRUIT_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Field.h"
#include "Sprites.h"
#include "Snake.h"

class Fruit{
private:
    int x, y;

public:
    Fruit();

    void fruit_generator(const Snake& snake);

    void eat_fruit(Snake& snake);

    void draw_fruit(sf::RenderWindow& window, Sprites& sprites) const;

};

    inline void Fruit::eat_fruit(Snake& snake){
        if(x==snake.snk[0].x && y==snake.snk[0].y){
            snake.snake_bodyparts++;
            x=rand()%Field::width;
            y=rand()%Field::height;
        }
    }

    inline void Fruit::draw_fruit(sf::RenderWindow& window, Sprites& sprites) const{
        sprites.sprite_of_fruit.setPosition(x*sprites.pixel, y*sprites.pixel);
        window.draw(sprites.sprite_of_fruit);
    }

#endif // FRUIT_H_INCLUDED
