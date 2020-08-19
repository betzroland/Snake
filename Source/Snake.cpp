#include <SFML/Graphics.hpp>
#include "Snake.h"

using namespace std;
using namespace sf;

Snake::Snake(){
    direction=4;
    db=4;
}

bool Snake::IsOver(const int M, const int N){
    if(snk[0].x==-1 || snk[0].x==N || snk[0].y==-1 || snk[0].y==M){
        return true;
    }
    for(int i=1; i<db; i++){
        if(snk[0].x==snk[i].x && snk[0].y==snk[i].y){
            return true;
        }
    }
    return false;
}

void Snake::set_startposition(const int M){
    for(int i=0; i<db; i++){
        snk[i].x=db-1-i;
        snk[i].y=M/2-1;
        }
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
