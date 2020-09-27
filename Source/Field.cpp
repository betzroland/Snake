#include "Field.h"

using namespace std;
using namespace sf;

void Field::draw_field(RenderWindow& window, Sprites& sprites) const{
    for (int i=0; i<width; i++){
      for (int j=0; j<height; j++){
        sprites.sprite_of_field.setPosition(i*sprites.pixel, j*sprites.pixel);
        window.draw(sprites.sprite_of_field);
        }
        }
}
