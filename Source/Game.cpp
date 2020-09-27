#include "Game.h"

using namespace std;
using namespace sf;

void Game::play_game(RenderWindow& window){

    open_and_gameover_window.draw_openingwindow(window);

    control_gamewindow(window);

    open_and_gameover_window.draw_gameoverwindow(window, snake);
}

void Game::control_gamewindow(RenderWindow& window){
    while(window.isOpen()==true && snake.IsGameOver()==false){

        field.draw_field(window, sprites);

        fruit.draw_fruit(window, sprites);

        snake.draw_snake(window, sprites);

        snake.move_control();

        fruit.eat_fruit(snake);

        fruit.fruit_generator(snake);

        click_to_close_gamewindow(window);

        window.display();
        sleep(milliseconds(100));
    }
}

void Game::click_to_close_gamewindow(RenderWindow& window){
    Event event;
    while(window.pollEvent(event)){
        if(event.type==Event::Closed){
            window.close();
        }
    }
}
