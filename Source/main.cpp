#include <SFML/Graphics.hpp>
#include <time.h>
#include "Draw.h"
#include "Snake.h"

using namespace std;
using namespace sf;

int main()
{
    srand(time(NULL));

    Event event;   Draw draw;   Snake snake;   Fruit fruit;

    RenderWindow window(VideoMode(draw.N*draw.pixel,draw.M*draw.pixel), "Snake");

    draw.draw_openingwindow(window);
    snake.set_startposition(draw.M);
    fruit.set_startposition(draw.M, draw.N);

    while(window.isOpen() && snake.IsOver(draw.M, draw.N)==false){

        while(window.pollEvent(event)){
            if(event.type==Event::Closed){
                window.close();
            }
        }

        draw.draw_field(window);

        draw.draw_fruit(window, fruit);

        draw.draw_snake(window, snake.db, snake.snk);

        snake.move_control();

        fruit.fruit_generator(draw.M, draw.N, snake.snk, snake.db);

        window.display();
        sleep(milliseconds(100));
    }
    draw.draw_gameover(window, snake.db);
return 0;
}
