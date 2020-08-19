#ifndef Snake_H_INCLUDED
#define Snake_H_INCLUDED
#include <SFML/Graphics.hpp>

struct Snk{
    int x, y;
};

class Snake{
public:
    Snk snk[100];
    int direction;
    int db;

    Snake();   // Initializing class variables.

    bool IsOver(const int M, const int N);  // Checks if the head of the snake has hit the walls, or its tail.

    void set_startposition(const int M);  // Setting the snake's starting position.

    void move_control();   // Function to control the snake.

};

#endif // Snake_H_INCLUDED
