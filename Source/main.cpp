#include <SFML/Graphics.hpp>
#include <time.h>
#include "Draw.h"
#include "Engine.h"

using namespace std;
using namespace sf;

int main()
{
    srand(time(NULL));

    Event event;
    Draw draw;
    Engine engine;

    RenderWindow window(VideoMode(draw.N*draw.pixel,draw.M*draw.pixel), "Snake");

    draw.draw_openingwindow(window);

    engine.set_startposition(draw.sprite2, draw.pixel, window, draw.M, draw.N);

    while(window.isOpen() && engine.IsOver(draw.M, draw.N)==false){

        while(window.pollEvent(event)){
            if(event.type==Event::Closed){
                window.close();
            }
        }

        draw.draw_field(window);

        engine.move_control(draw.sprite2, draw.pixel, window);

        engine.fruit_generator(draw.sprite2, draw.pixel, window, draw.M, draw.N);

        window.display();

        if(engine.IsOver(draw.M, draw.N)){
            draw.draw_gameover(window, engine.db);
        }
        sleep(milliseconds(100));
    }
return 0;
}
