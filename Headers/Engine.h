#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED

using namespace std;
using namespace sf;

class Snake{
    public:
    int x, y;
};

class Fruit{
    public:
    int x, y;
};

class Engine{
public:
    int M, N;
    Snake snake[100];
    int direction;
    int db=4;
    Fruit fruit;

    Engine();   // Initializing class variables.

    bool IsOver();  // Checks if the head of the snake has hit the walls, or its tail.

    void set_startposition(Sprite& sprite2, int& pixel, RenderWindow& window);  // Setting the snake's starting position.

    void move_control(Sprite& sprite2, int& pixel, RenderWindow& window);   // Function to control the snake.

    void fruit_generator(Sprite& sprite2, int& pixel, RenderWindow& window);    // Generating fruits randomly on the field.

};

#endif // ENGINE_H_INCLUDED
