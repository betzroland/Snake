#include "Field.h"

using namespace std;
using namespace sf;

void Field::draw_field(RenderWindow& window, SpritesAndTextures& sprites_and_textures) const{
    for (int i=0; i<N; i++){
      for (int j=0; j<M; j++){
        sprites_and_textures.sprite_of_field.setPosition(i*sprites_and_textures.pixel, j*sprites_and_textures.pixel);
        window.draw(sprites_and_textures.sprite_of_field);
        }
        }
}
