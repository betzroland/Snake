#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Fruit.h"
#include "Snake.h"
#include "Sprites&Textures.h"
#include "Field.h"
#include "Opening&Gameover_window.h"

class Game{
public:
    OpeningAndGameoverWindow opening_and_gameover_window;
    SpritesAndTextures sprites_and_textures;
    Field field;
    Snake snake;
    Fruit fruit;

    void play_game(sf::RenderWindow& window);

    void control_gamewindow(sf::RenderWindow& window);

    void click_to_close_gamewindow(sf::RenderWindow& window);

};

#endif // GAME_H_INCLUDED
