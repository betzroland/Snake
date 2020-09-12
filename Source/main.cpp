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
    Opening_and_gameover_window openAndGameover;
    Snake snake;
    SpritesAndTextures sprites_and_textures;
    Field field;
    Fruit fruit(field);

    RenderWindow window(VideoMode(field.N*sprites_and_textures.pixel,field.M*sprites_and_textures.pixel), "Snake");

    openAndGameover.draw_openingwindow(window);

    while(window.isOpen() && snake.IsOver(field)==false){

        while(window.pollEvent(event)){
            if(event.type==Event::Closed){
                window.close();
            }
        }

        field.draw_field(window, sprites_and_textures);

        fruit.draw_fruit(window, sprites_and_textures);

        snake.draw_snake(window, sprites_and_textures);

        snake.move_control();

        fruit.fruit_generator(snake, field);

        window.display();
        sleep(milliseconds(100));
    }
    openAndGameover.draw_gameover(window, snake);
return 0;
}
