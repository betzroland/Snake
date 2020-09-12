#include "Snake.h"

using namespace std;
using namespace sf;

Snake::Snake(){
    direction=4;
    snk_elements_at_start=3;
    number_of_snk_elements=snk_elements_at_start;
    for(int i=0; i<number_of_snk_elements; i++){
        snk[i].x=number_of_snk_elements-1-i;
        snk[i].y=0;
        }
}

bool Snake::IsGameOver(Field& field) const{
    if(snk[0].x==-1 || snk[0].x==field.N || snk[0].y==-1 || snk[0].y==field.M){
        return true;
    }
    for(int i=1; i<number_of_snk_elements; i++){
        if(snk[0].x==snk[i].x && snk[0].y==snk[i].y){
            return true;
        }
    }
    return false;
}

void Snake::move_control(){

    if(Keyboard::isKeyPressed(Keyboard::Up))        direction=1;
    if(Keyboard::isKeyPressed(Keyboard::Down))      direction=2;
    if(Keyboard::isKeyPressed(Keyboard::Left))      direction=3;
    if(Keyboard::isKeyPressed(Keyboard::Right))     direction=4;

    switch(direction){
    case 1 :
        for(int i=number_of_snk_elements-1; i>0; i--){
            snk[i].x=snk[i-1].x;
            snk[i].y=snk[i-1].y;
        }
        snk[0].y=snk[0].y-1;
        break;

    case 2 :
        for(int i=number_of_snk_elements-1; i>0; i--){
            snk[i].x=snk[i-1].x;
            snk[i].y=snk[i-1].y;
        }
        snk[0].y=snk[0].y+1;
        break;

    case 3 :
        for(int i=number_of_snk_elements-1; i>0; i--){
            snk[i].x=snk[i-1].x;
            snk[i].y=snk[i-1].y;
        }
        snk[0].x=snk[0].x-1;
        break;

    case 4 :
        for(int i=number_of_snk_elements-1; i>0; i--){
            snk[i].x=snk[i-1].x;
            snk[i].y=snk[i-1].y;
            }
        snk[0].x=snk[0].x+1;
    }
}

void Snake::draw_snake(sf::RenderWindow& window, SpritesAndTextures& sprites_and_textures) const{
    for(int i=0; i<number_of_snk_elements; i++){
        sprites_and_textures.sprite_of_snake.setPosition(snk[i].x*sprites_and_textures.pixel, snk[i].y*sprites_and_textures.pixel);
        window.draw(sprites_and_textures.sprite_of_snake);
    }
}
