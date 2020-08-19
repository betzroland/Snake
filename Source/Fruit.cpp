#include "Fruit.h"
#include "Snake.h"

using namespace std;
using namespace sf;

    void Fruit::set_startposition(const int M, const int N){
        x=rand()%N;
        y=rand()%M;
    }

    void Fruit::fruit_generator(const int M, const int N, Snk* snk, int& db){
    int j=1;
    while(j<db){
        if(x==snk[j].x && y==snk[j].y){
            x=rand()%N;
            y=rand()%M;
            j=1;
        }
        j++;
    }
    if(x==snk[0].x && y==snk[0].y){
        db=db+1;
        x=rand()%N;
        y=rand()%M;
    }
}
