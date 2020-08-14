#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED

std::string intToString(int t);  // Auxiliary function: converts an int type to string.

class Draw{
public:
    sf::Texture texture;
    sf::Sprite sprite1, sprite2;
    int pixel;

    Draw(); // Initializing class variables.

    void draw_openingwindow(sf::RenderWindow& window);  // Draws the opening window (when the game starts).

    void draw_field(int& M, int& N, sf::RenderWindow& window);  // Drawing the game field.

    void draw_gameover(sf::RenderWindow& window, int& db, int& M, int& N); // Drawing game over window with the score.

};

#endif // DRAW_H_INCLUDED
