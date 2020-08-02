#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <time.h>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
using namespace sf;

string intToString(int t){
            string s;
            ostringstream out;
            out << t;
            s = out.str();
            return s;
        }

int M=20, N=30;
int pixel=20;

class Snake{
    public:
    int x, y;
};

bool IsOver(Snake* s, int& db){
    if(s[0].x==-1 || s[0].x==N || s[0].y==-1 || s[0].y==M){
        return true;
    }
    for(int i=1; i<db; i++){
        if(s[0].x==s[i].x && s[0].y==s[i].y){
            return true;
        }
    }
    return false;
}

Snake s[100];

class Fruit{
    public:
    int x, y;
    Fruit(){
        x=rand()%N;
        y=rand()%M;
        }
};

int direction;
int db=4;

int main()
{
    srand(time(NULL));
    RenderWindow window(VideoMode(N*pixel,M*pixel), "Snake");     //30x20 db négyzetbõl épül a pálya
    Texture texture;
    texture.loadFromFile("grid.png");
    Sprite sprite1(texture);
    Sprite sprite2(texture);
    sprite2.setColor(Color(0, 255, 0));     //Zöld színû négyzet a kígyó "testéhez".
    Fruit fruit;
    Event event;

    for(int i=0; i<db; i++){
            s[i].x=db-1-i;
            s[i].y=M/2-1;
            sprite2.setPosition(s[i].x*pixel,s[i].y*pixel);
            window.draw(sprite2);
        }

    while(window.isOpen() && IsOver(s, db)==false){

    while(window.pollEvent(event)){     //Megvizsgálja, van-e függőben esemény.
            if(event.type==Event::Closed){  //Ha az esemény: ablak bezárása utasítás -->
                window.close();             //--> Bezárja az ablakot.
            }
        }

    for (int i=0; i<N; i++){
      for (int j=0; j<M; j++){
        sprite1.setPosition(i*pixel, j*pixel);    //Pixelben adjuk meg az adott pozíciót (egy négyzet 20x20-as)
        window.draw(sprite1);                     //Kirajzolja a sprite-ot a megadott pozícióba.
        }
        }

    if(Keyboard::isKeyPressed(Keyboard::Up))        direction=1;
    if(Keyboard::isKeyPressed(Keyboard::Down))      direction=2;
    if(Keyboard::isKeyPressed(Keyboard::Left))      direction=3;
    if(Keyboard::isKeyPressed(Keyboard::Right))     direction=4;

    if(direction==0){
    for(int i=0; i<db; i++){
            sprite2.setPosition(s[i].x*pixel,s[i].y*pixel);
            window.draw(sprite2);
        }
        }

    sprite2.setPosition(fruit.x*pixel, fruit.y*pixel);
    window.draw(sprite2);

    int j=1;
    while(j<db){                                //Ha a kígyó testébe "spawn"-ol a gyümölcs, újra sorsol.
        if(fruit.x==s[j].x && fruit.y==s[j].y){
            fruit.x=rand()%N;
            fruit.y=rand()%M;
            sprite2.setPosition(fruit.x*pixel, fruit.y*pixel);
            window.draw(sprite2);
            j=1;
        }
        j++;
    }

    if(fruit.x==s[0].x && fruit.y==s[0].y){     //Ha a kígyó feje eléri a gyümölcsöt, eggyel nő a hossza.
        db=db+1;
        fruit.x=rand()%N;
        fruit.y=rand()%M;
    }

    if(direction==4){
        for(int i=db-1; i>0; i--){
            s[i].x=s[i-1].x;
            s[i].y=s[i-1].y;
            sprite2.setPosition(s[i].x*pixel,s[i].y*pixel);
            window.draw(sprite2);
            }
            s[0].x=s[0].x+1;
            sprite2.setPosition(s[0].x*pixel,s[0].y*pixel);
            window.draw(sprite2);
    }

    if(direction==2){
        for(int i=db-1; i>0; i--){
            s[i].x=s[i-1].x;
            s[i].y=s[i-1].y;
            sprite2.setPosition(s[i].x*pixel,s[i].y*pixel);
            window.draw(sprite2);
        }
        s[0].y=s[0].y+1;
        sprite2.setPosition(s[0].x*pixel,s[0].y*pixel);
        window.draw(sprite2);
    }

    if(direction==3){
        for(int i=db-1; i>0; i--){
            s[i].x=s[i-1].x;
            s[i].y=s[i-1].y;
            sprite2.setPosition(s[i].x*pixel,s[i].y*pixel);
            window.draw(sprite2);
        }
        s[0].x=s[0].x-1;
        sprite2.setPosition(s[0].x*pixel,s[0].y*pixel);
        window.draw(sprite2);
    }

    if(direction==1){
        for(int i=db-1; i>0; i--){
            s[i].x=s[i-1].x;
            s[i].y=s[i-1].y;
            sprite2.setPosition(s[i].x*pixel,s[i].y*pixel);
            window.draw(sprite2);
        }
        s[0].y=s[0].y-1;
        sprite2.setPosition(s[0].x*pixel,s[0].y*pixel);
        window.draw(sprite2);
    }
    window.display();
    sleep(sf::milliseconds(80));
    //-------------------

    if(IsOver(s, db)){
    sleep(sf::milliseconds(1000));
    window.clear();
    Text text1;
    Text text2;
    Font font;
    font.loadFromFile("arial.ttf");
    text1.setFont(font);
    text2.setFont(font);
    text1.setString("Game over!");
    text2.setString("Score: "+intToString(db-4));
    text1.setCharacterSize(24);
    text2.setCharacterSize(24);
    text1.setFillColor(Color::Green);
    text2.setFillColor(Color::Green);
    text1.setStyle(Text::Bold);
    text2.setStyle(Text::Bold);
    text1.setPosition((N/2)*pixel-70, (M/3)*pixel);
    text2.setPosition((N/2)*pixel-70, (M/2.5)*pixel);

    window.draw(text1);
    window.draw(text2);
    window.display();
    sleep(milliseconds(2500));
    }
    }
    return 0;
}

