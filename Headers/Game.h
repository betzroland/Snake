#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Fruit.h"
#include "Snake.h"
#include "Sprites.h"
#include "Field.h"
#include "OpenAndGameoverWindow.h"

class Game{
private:
    OpenAndGameoverWindow open_and_gameover_window;
    Sprites sprites;
    Field field;
    Snake snake;
    Fruit fruit;

public:
    void play_game(sf::RenderWindow& window);

    void control_gamewindow(sf::RenderWindow& window);

    void click_to_close_gamewindow(sf::RenderWindow& window);

};

#endif // GAME_H_INCLUDED
