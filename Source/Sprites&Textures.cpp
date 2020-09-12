#include "Sprites&Textures.h"

using namespace std;
using namespace sf;

SpritesAndTextures::SpritesAndTextures(){
    pixel=20;
    tile.loadFromFile("tile.png");
    sprite_of_field.setTexture(tile);

    sprite_of_fruit=sprite_of_snake=sprite_of_field;

    sprite_of_snake.setColor(Color(0, 255, 0));
    sprite_of_fruit.setColor(Color(255,80,0));
}
