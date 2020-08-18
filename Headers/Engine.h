#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED

struct Snake{
    int x, y;
};

struct Fruit{
    int x, y;
};

class Engine{
public:
    Snake snake[100];
    int direction;
    int db;
    Fruit fruit;

    Engine();   // Initializing class variables.

    bool IsOver(int& M, int& N);  // Checks if the head of the snake has hit the walls, or its tail.

    void set_startposition(sf::Sprite& sprite2, int& pixel, sf::RenderWindow& window, int& M, int& N);  // Setting the snake's starting position.

    void move_control(sf::Sprite& sprite2, int& pixel, sf::RenderWindow& window);   // Function to control the snake.

    void fruit_generator(sf::Sprite& sprite2, int& pixel, sf::RenderWindow& window, int& M, int& N);    // Generating fruits randomly on the field.

};

#endif // ENGINE_H_INCLUDED
