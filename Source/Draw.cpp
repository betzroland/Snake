#include <SFML/Graphics.hpp>
#include <sstream>
#include "Draw.h"
#include "Snake.h"

using namespace std;
using namespace sf;

    Draw::Draw(){
    M=18;
    N=24;
    texture.loadFromFile("grid.png");
    sprite1.setTexture(texture);
    sprite2.setTexture(texture);
    sprite2.setColor(Color(0, 255, 0));
    pixel=20;
    }

    void Draw::draw_openingwindow(RenderWindow& window){
    int seconds;
    Text text1;
    Text text2;
    Text text3;

    Font font;
    font.loadFromFile("arial.ttf");

    text1.setFont(font);
    text2.setFont(font);
    text3.setFont(font);

    text1.setCharacterSize(24);
    text2.setCharacterSize(24);
    text3.setCharacterSize(24);

    text1.setFillColor(Color::Green);
    text2.setFillColor(Color::Green);
    text3.setFillColor(Color::Green);

    text1.setStyle(Text::Bold);
    text2.setStyle(Text::Bold);
    text3.setStyle(Text::Bold);

    text1.setPosition(145, 100);
    text2.setPosition(225, 140);
    text3.setPosition(180, 180);

    for(int i=3; i>=0; i--){
    seconds=i;
    text1.setString("Game starts in");
    text2.setString(to_string(seconds));
    text3.setString("seconds!");

    window.draw(text1);
    window.draw(text2);
    window.draw(text3);

    window.display();
    sleep(milliseconds(1000));
    window.clear();
    }

    window.clear();
}

void Draw::draw_field(RenderWindow& window){
    for (int i=0; i<N; i++){
      for (int j=0; j<M; j++){
        sprite1.setPosition(i*pixel, j*pixel);
        window.draw(sprite1);
        }
        }
}

void Draw::draw_gameover(RenderWindow& window, const int db){

    sleep(milliseconds(1000));
    window.clear();

    Text text1;
    Text text2;
    Font font;
    font.loadFromFile("arial.ttf");
    text1.setFont(font);
    text2.setFont(font);
    text1.setString("Game over!");
    text2.setString("Score: "+to_string(db-4));
    text1.setCharacterSize(24);
    text2.setCharacterSize(24);
    text1.setFillColor(Color::Green);
    text2.setFillColor(Color::Green);
    text1.setStyle(Text::Bold);
    text2.setStyle(Text::Bold);
    text1.setPosition((N/2)*pixel-70, (M/3.5)*pixel);
    text2.setPosition((N/2)*pixel-50, (M/2.5)*pixel);

    window.draw(text1);
    window.draw(text2);
    window.display();
    sleep(milliseconds(2500));
}

void Draw::draw_snake(sf::RenderWindow& window, const int db, Snk* snk){
    for(int i=0; i<db; i++){
        sprite2.setPosition(snk[i].x*pixel, snk[i].y*pixel);
        window.draw(sprite2);
    }
}

void Draw::draw_fruit(sf::RenderWindow& window, const Fruit fruit){
    sprite2.setPosition(fruit.x*pixel, fruit.y*pixel);
    window.draw(sprite2);
}
