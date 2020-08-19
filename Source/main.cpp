#include <SFML/Graphics.hpp>
#include <time.h>
#include "Draw.h"
#include "Engine.h"

using namespace std;
using namespace sf;

int main()
{
    srand(time(NULL));

    Event event;   Draw draw;   Engine engine;   Fruit fruit;

    RenderWindow window(VideoMode(draw.N*draw.pixel,draw.M*draw.pixel), "Snake");

    draw.draw_openingwindow(window);
    engine.set_startposition(draw.M);
    fruit.set_startposition(draw.M, draw.N);

    while(window.isOpen() && engine.IsOver(draw.M, draw.N)==false){

        while(window.pollEvent(event)){
            if(event.type==Event::Closed){
                window.close();
            }
        }

        draw.draw_field(window);

        draw.draw_fruit(window, fruit);

        draw.draw_snake(window, engine.db, engine.snake);

        engine.move_control();

        fruit.fruit_generator(draw.M, draw.N, engine.snake, engine.db);

        window.display();
        sleep(milliseconds(100));
    }
    draw.draw_gameover(window, engine.db);
return 0;
}
