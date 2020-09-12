#include "Sprites&Textures.h"

using namespace std;
using namespace sf;

SpritesAndTextures::SpritesAndTextures(){
    pixel=20;
    texture.loadFromFile("tile.png");
    sprite1.setTexture(texture);
    sprite2.setTexture(texture);
    sprite2.setColor(Color(0, 255, 0));
}
