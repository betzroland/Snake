#include "Opening&Gameover_window.h"

using namespace std;
using namespace sf;

Opening_and_gameover_window::Opening_and_gameover_window(){

    font.loadFromFile("arial.ttf");

    text1.setFont(font);
    text1.setCharacterSize(24);
    text1.setFillColor(Color::Green);
    text1.setStyle(Text::Bold);

    text3=text2=text1;
    }

void Opening_and_gameover_window::draw_openingwindow(RenderWindow& window){

    text1.setPosition(145, 100);
    text2.setPosition(225, 140);
    text3.setPosition(180, 180);

    for(int seconds=3; seconds>=0; seconds--){
    text1.setString("Game starts in");
    text2.setString(to_string(seconds));
    text3.setString("seconds!");

    window.draw(text1);
    window.draw(text2);
    window.draw(text3);

    window.display();
    sleep(milliseconds(950));
    window.clear();
    }
}

void Opening_and_gameover_window::draw_gameover(RenderWindow& window, Snake& snake){

    sleep(milliseconds(1000));
    window.clear();

    text1.setString("Game over!");
    text2.setString("Score: "+to_string(snake.db-snake.db_at_beginning));

    text1.setPosition(145, 100);
    text2.setPosition(165, 140);

    window.draw(text1);
    window.draw(text2);

    window.display();
    sleep(milliseconds(2000));
}
