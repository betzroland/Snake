#include "Fruit.h"
#include "Engine.h"

using namespace std;
using namespace sf;

    void Fruit::set_startposition(int& M, int& N){
        x=rand()%N;
        y=rand()%M;
    }

    void Fruit::fruit_generator(int& M, int& N, Snake* snake, int& db){
    int j=1;
    while(j<db){
        if(x==snake[j].x && y==snake[j].y){
            x=rand()%N;
            y=rand()%M;
            j=1;
        }
        j++;
    }
    if(x==snake[0].x && y==snake[0].y){
        db=db+1;
        x=rand()%N;
        y=rand()%M;
    }
}
