#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED

class Draw{
public:
    int M, N;
    sf::Texture texture;
    sf::Sprite sprite1, sprite2;
    int pixel;

    Draw(); // Initializing class variables.

    void draw_openingwindow(sf::RenderWindow& window);  // Draws the opening window (when the game starts).

    void draw_field(sf::RenderWindow& window);  // Drawing the game field.

    void draw_gameover(sf::RenderWindow& window, int& db); // Drawing game over window with the score.

};

#endif // DRAW_H_INCLUDED
