#include <SFML/Graphics.hpp>
#include "Engine.h"

using namespace std;
using namespace sf;

Engine::Engine(){
    M=18;
    N=24;
    direction=4;
    db=4;
    fruit.x=rand()%N;
    fruit.y=rand()%M;
}

bool Engine::IsOver(){
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

void Engine::set_startposition(Sprite& sprite2, int& pixel, RenderWindow& window){
    for(int i=0; i<db; i++){
        snake[i].x=db-1-i;
        snake[i].y=M/2-1;
        sprite2.setPosition(snake[i].x*pixel,snake[i].y*pixel);
        window.draw(sprite2);
        }
}

void Engine::move_control(Sprite& sprite2, int& pixel, RenderWindow& window){

    if(Keyboard::isKeyPressed(Keyboard::Up))        direction=1;
    if(Keyboard::isKeyPressed(Keyboard::Down))      direction=2;
    if(Keyboard::isKeyPressed(Keyboard::Left))      direction=3;
    if(Keyboard::isKeyPressed(Keyboard::Right))     direction=4;

    if(direction==1){
        for(int i=db-1; i>0; i--){
            snake[i].x=snake[i-1].x;
            snake[i].y=snake[i-1].y;
            sprite2.setPosition(snake[i].x*pixel,snake[i].y*pixel);
            window.draw(sprite2);
        }
        snake[0].y=snake[0].y-1;
        sprite2.setPosition(snake[0].x*pixel,snake[0].y*pixel);
        window.draw(sprite2);
    }

    if(direction==2){
        for(int i=db-1; i>0; i--){
            snake[i].x=snake[i-1].x;
            snake[i].y=snake[i-1].y;
            sprite2.setPosition(snake[i].x*pixel,snake[i].y*pixel);
            window.draw(sprite2);
        }
        snake[0].y=snake[0].y+1;
        sprite2.setPosition(snake[0].x*pixel,snake[0].y*pixel);
        window.draw(sprite2);
    }

    if(direction==3){
        for(int i=db-1; i>0; i--){
            snake[i].x=snake[i-1].x;
            snake[i].y=snake[i-1].y;
            sprite2.setPosition(snake[i].x*pixel,snake[i].y*pixel);
            window.draw(sprite2);
        }
        snake[0].x=snake[0].x-1;
        sprite2.setPosition(snake[0].x*pixel,snake[0].y*pixel);
        window.draw(sprite2);
    }

    if(direction==4){
        for(int i=db-1; i>0; i--){
            snake[i].x=snake[i-1].x;
            snake[i].y=snake[i-1].y;
            sprite2.setPosition(snake[i].x*pixel, snake[i].y*pixel);
            window.draw(sprite2);
            }
            snake[0].x=snake[0].x+1;
            sprite2.setPosition(snake[0].x*pixel, snake[0].y*pixel);
            window.draw(sprite2);
    }
}

void Engine::fruit_generator(Sprite& sprite2, int& pixel, RenderWindow& window){

    sprite2.setPosition(fruit.x*pixel, fruit.y*pixel);
    window.draw(sprite2);

    int j=1;
    while(j<db){                                //Ha a kígyó testébe "spawn"-ol a gyümölcs, újra sorsol.
        if(fruit.x==snake[j].x && fruit.y==snake[j].y){
            fruit.x=rand()%N;
            fruit.y=rand()%M;
            sprite2.setPosition(fruit.x*pixel, fruit.y*pixel);
            window.draw(sprite2);
            j=1;
        }
        j++;
    }

    if(fruit.x==snake[0].x && fruit.y==snake[0].y){     //Ha a kígyó feje eléri a gyümölcsöt, eggyel nõ a hossza.
        db=db+1;
        fruit.x=rand()%N;       // Új gyümölcs generálás.
        fruit.y=rand()%M;
    }
}
