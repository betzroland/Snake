#include <SFML/Graphics.hpp>
#include "Engine.h"

using namespace std;
using namespace sf;

Engine::Engine(){
    direction=4;
    db=4;
}

bool Engine::IsOver(int& M, int& N){
    if(snake[0].x==-1 || snake[0].x==N || snake[0].y==-1 || snake[0].y==M){
        return true;
    }
    for(int i=1; i<db; i++){
        if(snake[0].x==snake[i].x && snake[0].y==snake[i].y){
            return true;
        }
    }
    return false;
}

void Engine::set_startposition(int& M){
    for(int i=0; i<db; i++){
        snake[i].x=db-1-i;
        snake[i].y=M/2-1;
        }
}

void Engine::move_control(){

    if(Keyboard::isKeyPressed(Keyboard::Up))        direction=1;
    if(Keyboard::isKeyPressed(Keyboard::Down))      direction=2;
    if(Keyboard::isKeyPressed(Keyboard::Left))      direction=3;
    if(Keyboard::isKeyPressed(Keyboard::Right))     direction=4;

    if(direction==1){
        for(int i=db-1; i>0; i--){
            snake[i].x=snake[i-1].x;
            snake[i].y=snake[i-1].y;
        }
        snake[0].y=snake[0].y-1;
    }

    if(direction==2){
        for(int i=db-1; i>0; i--){
            snake[i].x=snake[i-1].x;
            snake[i].y=snake[i-1].y;
        }
        snake[0].y=snake[0].y+1;
    }

    if(direction==3){
        for(int i=db-1; i>0; i--){
            snake[i].x=snake[i-1].x;
            snake[i].y=snake[i-1].y;
        }
        snake[0].x=snake[0].x-1;
    }

    if(direction==4){
        for(int i=db-1; i>0; i--){
            snake[i].x=snake[i-1].x;
            snake[i].y=snake[i-1].y;
            }
            snake[0].x=snake[0].x+1;
    }
}
