#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED
#include <SFML/Graphics.hpp>

struct Snake{
    int x, y;
};

class Engine{
public:
    Snake snake[100];
    int direction;
    int db;

    Engine();   // Initializing class variables.

    bool IsOver(int& M, int& N);  // Checks if the head of the snake has hit the walls, or its tail.

    void set_startposition(int& M);  // Setting the snake's starting position.

    void move_control();   // Function to control the snake.

};

#endif // ENGINE_H_INCLUDED
