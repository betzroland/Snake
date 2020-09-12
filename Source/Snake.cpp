#include "Snake.h"

using namespace std;
using namespace sf;

Snake::Snake(){
    direction=4;
    db_at_beginning=3;
    db=db_at_beginning;
    for(int i=0; i<db; i++){
        snk[i].x=db-1-i;
        snk[i].y=0;
        }
}

bool Snake::IsOver(Field& field){
    if(snk[0].x==-1 || snk[0].x==field.N || snk[0].y==-1 || snk[0].y==field.M){
        return true;
    }
    for(int i=1; i<db; i++){
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

    if(direction==1){
        for(int i=db-1; i>0; i--){
            snk[i].x=snk[i-1].x;
            snk[i].y=snk[i-1].y;
        }
        snk[0].y=snk[0].y-1;
    }

    if(direction==2){
        for(int i=db-1; i>0; i--){
            snk[i].x=snk[i-1].x;
            snk[i].y=snk[i-1].y;
        }
        snk[0].y=snk[0].y+1;
    }

    if(direction==3){
        for(int i=db-1; i>0; i--){
            snk[i].x=snk[i-1].x;
            snk[i].y=snk[i-1].y;
        }
        snk[0].x=snk[0].x-1;
    }

    if(direction==4){
        for(int i=db-1; i>0; i--){
            snk[i].x=snk[i-1].x;
            snk[i].y=snk[i-1].y;
            }
            snk[0].x=snk[0].x+1;
    }
}

void Snake::draw_snake(sf::RenderWindow& window, SpritesAndTextures& sprites_and_textures){
    for(int i=0; i<db; i++){
        sprites_and_textures.sprite2.setPosition(snk[i].x*sprites_and_textures.pixel, snk[i].y*sprites_and_textures.pixel);
        window.draw(sprites_and_textures.sprite2);
    }
}
