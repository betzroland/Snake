#include "Fruit.h"

using namespace std;
using namespace sf;

    Fruit::Fruit(Field& field){
        x=rand()%field.N;
        y=rand()%field.M;
    }

    void Fruit::fruit_generator(Snake& snake, Field& field){
    int j=1;
    while(j<snake.db){
        if(x==snake.snk[j].x && y==snake.snk[j].y){
            x=rand()%field.N;
            y=rand()%field.M;
            j=1;
        }
        j++;
    }
    if(x==snake.snk[0].x && y==snake.snk[0].y){
        snake.db++;
        x=rand()%field.N;
        y=rand()%field.M;
    }
}

void Fruit::draw_fruit(RenderWindow& window, SpritesAndTextures& sprites_and_textures){
    sprites_and_textures.sprite2.setPosition(x*sprites_and_textures.pixel, y*sprites_and_textures.pixel);
    window.draw(sprites_and_textures.sprite2);
}
