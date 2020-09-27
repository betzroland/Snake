#include "OpenAndGameoverWindow.h"

using namespace std;
using namespace sf;

OpenAndGameoverWindow::OpenAndGameoverWindow(){

    font.loadFromFile("arial.ttf");

    line1.setFont(font);
    line1.setCharacterSize(24);
    line1.setFillColor(Color::Green);
    line1.setStyle(Text::Bold);

    line3=line2=line1;
    }

void OpenAndGameoverWindow::draw_openingwindow(RenderWindow& window){

    line1.setPosition(145, 100);
    line2.setPosition(225, 140);
    line3.setPosition(180, 180);

    for(int seconds=3; seconds>=0; seconds--){
    line1.setString("Game starts in");
    line2.setString(to_string(seconds));
    line3.setString("seconds!");

    window.draw(line1);
    window.draw(line2);
    window.draw(line3);

    window.display();
    sleep(milliseconds(950));
    window.clear();
    }
}

void OpenAndGameoverWindow::draw_gameoverwindow(RenderWindow& window, const Snake& snake){

    sleep(milliseconds(1000));
    window.clear();

    line1.setString("Game over!");
    line2.setString("Score: " + to_string(snake.snake_bodyparts - snake.snake_bodyparts_at_start));

    line1.setPosition(145, 100);
    line2.setPosition(165, 140);

    window.draw(line1);
    window.draw(line2);

    window.display();
    sleep(milliseconds(2000));
}
