#include "Snake.h"

using namespace std;
using namespace sf;

Snake::Snake(){
    direction=4;    // Means the rightward direction.
    snake_bodyparts_at_start=3;
    snake_bodyparts=snake_bodyparts_at_start;
    for(int i=0; i<snake_bodyparts; i++){
        snk[i].x=snake_bodyparts-1-i;
        snk[i].y=0;
    }
}

void Snake::move_control(){

    Snake::matching_keys_to_directions();

    Snake::move_tail();

    switch(direction){
    case 1 :
        Snake::move_head_upward();
        break;

    case 2 :
        Snake::move_head_downward();
        break;

    case 3 :
        Snake::move_head_leftward();
        break;

    case 4 :
        Snake::move_head_rightward();
    }
}

void Snake::matching_keys_to_directions(){
    if(Keyboard::isKeyPressed(Keyboard::Up) && direction!=2)        direction=1;
    if(Keyboard::isKeyPressed(Keyboard::Down) && direction!=1)      direction=2;
    if(Keyboard::isKeyPressed(Keyboard::Left) && direction!=4)      direction=3;
    if(Keyboard::isKeyPressed(Keyboard::Right) && direction!=3)     direction=4;
}

void Snake::move_head_upward(){
    snk[0].y=snk[0].y-1;
}

void Snake::move_head_downward(){
    snk[0].y=snk[0].y+1;
}

void Snake::move_head_leftward(){
    snk[0].x=snk[0].x-1;
}

void Snake::move_head_rightward(){
    snk[0].x=snk[0].x+1;
}

void Snake::move_tail(){
    for(int i=snake_bodyparts-1; i>0; i--){
        snk[i].x=snk[i-1].x;
        snk[i].y=snk[i-1].y;
    }
}

void Snake::draw_snake(sf::RenderWindow& window, Sprites& sprites) const{
    for(int i=0; i<snake_bodyparts; i++){
        sprites.sprite_of_snake.setPosition(snk[i].x*sprites.pixel, snk[i].y*sprites.pixel);
        window.draw(sprites.sprite_of_snake);
    }
}

bool Snake::IsGameOver() const{
    if(Snake::IsWallHit() || Snake::IsBodyHit())  return true;
    else return false;
}

bool Snake::IsWallHit() const{
    if(snk[0].x==-1 || snk[0].x==Field::width || snk[0].y==-1 || snk[0].y==Field::height){
        return true;
    }
    else return false;
}

bool Snake::IsBodyHit() const{
    for(int i=1; i<snake_bodyparts; i++){
        if(snk[0].x==snk[i].x && snk[0].y==snk[i].y){
            return true;
        }
    }
    return false;
}
