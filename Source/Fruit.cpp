#include "Fruit.h"

using namespace std;
using namespace sf;

    Fruit::Fruit(){
        x=rand()%Field::width;
        y=rand()%Field::height;
    }

    void Fruit::fruit_generator(const Snake& snake){
    int j=1;
    while(j<snake.snake_bodyparts){
        if(x==snake.snk[j].x && y==snake.snk[j].y){
            x=rand()%Field::width;
            y=rand()%Field::height;
            j=1;
            }
        j++;
        }
    }
