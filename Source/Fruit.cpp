#include "Fruit.h"

using namespace std;
using namespace sf;

    Fruit::Fruit(const Field& field){
        x=rand()%field.N;
        y=rand()%field.M;
    }

    void Fruit::fruit_generator(const Snake& snake, const Field& field){
    int j=1;
    while(j<snake.snake_bodyparts){
        if(x==snake.snk[j].x && y==snake.snk[j].y){
            x=rand()%field.N;
            y=rand()%field.M;
            j=1;
            }
        j++;
        }
    }
