#ifndef FRUIT_H_INCLUDED
#define FRUIT_H_INCLUDED
#include "Snake.h"

class Fruit{
public:
    int x, y;

    void set_startposition(const int M, const int N);   // Setting the position of the first fruit.

    void fruit_generator(const int M, const int N, Snk* snk, int& db);  // Generates new fruits.

};

#endif // FRUIT_H_INCLUDED
