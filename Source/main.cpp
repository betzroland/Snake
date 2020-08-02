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

    RenderWindow window(VideoMode(engine.N*draw.pixel,engine.M*draw.pixel), "Snake");

    draw.draw_openingwindow(window);

    engine.set_startposition(draw.sprite2, draw.pixel, window);

    while(window.isOpen() && engine.IsOver()==false){

        while(window.pollEvent(event)){
            if(event.type==Event::Closed){
                window.close();
            }
        }

        draw.draw_field(engine.M, engine.N, window);

        engine.move_control(draw.sprite2, draw.pixel, window);

        engine.fruit_generator(draw.sprite2, draw.pixel, window);

        window.display();

        if(engine.IsOver()){
            draw.draw_gameover(window, engine.db, engine.M, engine.N);
        }
        sleep(milliseconds(90));
    }
return 0;
}
