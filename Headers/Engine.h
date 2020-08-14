#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED

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

    void set_startposition(sf::Sprite& sprite2, int& pixel, sf::RenderWindow& window);  // Setting the snake's starting position.

    void move_control(sf::Sprite& sprite2, int& pixel, sf::RenderWindow& window);   // Function to control the snake.

    void fruit_generator(sf::Sprite& sprite2, int& pixel, sf::RenderWindow& window);    // Generating fruits randomly on the field.

};

#endif // ENGINE_H_INCLUDED
