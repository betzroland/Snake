#include <SFML/Graphics.hpp>
#include <time.h>
#include "Opening&Gameover_window.h"
#include "Field.h"
#include "Fruit.h"

using namespace std;
using namespace sf;

int main()
{
    srand(time(NULL));

    Event event;
    OpeningAndGameoverWindow opening_and_gameover_window;
    SpritesAndTextures sprites_and_textures;
    Field field;
    Snake snake;
    Fruit fruit(field);
    RenderWindow window(VideoMode(field.N*sprites_and_textures.pixel,
                                    field.M*sprites_and_textures.pixel), "Snake");


    opening_and_gameover_window.draw_openingwindow(window);

    while(window.isOpen()==true && snake.IsGameOver(field)==false){

        while(window.pollEvent(event)){
            if(event.type==Event::Closed){
                window.close();
            }
        }

        field.draw_field(window, sprites_and_textures);

        fruit.draw_fruit(window, sprites_and_textures);

        snake.draw_snake(window, sprites_and_textures);

        snake.move_control();

        fruit.eat_fruit(snake, field);

        fruit.fruit_generator(snake, field);

        window.display();
        sleep(milliseconds(100));
    }

    opening_and_gameover_window.draw_gameoverwindow(window, snake);

return 0;
}
