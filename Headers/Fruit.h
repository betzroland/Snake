#ifndef FRUIT_H_INCLUDED
#define FRUIT_H_INCLUDED
#include "Engine.h"

class Fruit{
public:
    int x, y;

    void set_startposition(int& M, int& N);

    void fruit_generator(int& M, int& N, Snake* snake, int& db);

};

#endif // FRUIT_H_INCLUDED
