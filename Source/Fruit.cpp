#include "Fruit.h"

using namespace std;
using namespace sf;

    Fruit::Fruit(){
        x=rand()%Field::N;
        y=rand()%Field::M;
    }

    void Fruit::fruit_generator(const Snake& snake){
    int j=1;
    while(j<snake.snake_bodyparts){
        if(x==snake.snk[j].x && y==snake.snk[j].y){
            x=rand()%Field::N;
            y=rand()%Field::M;
            j=1;
            }
        j++;
        }
    }
