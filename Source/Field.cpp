#include "Field.h"

using namespace std;
using namespace sf;

Field::Field(){
    M=18;
    N=24;
}

void Field::draw_field(RenderWindow& window, SpritesAndTextures& sprites_and_textures){
    for (int i=0; i<N; i++){
      for (int j=0; j<M; j++){
        sprites_and_textures.sprite1.setPosition(i*sprites_and_textures.pixel, j*sprites_and_textures.pixel);
        window.draw(sprites_and_textures.sprite1);
        }
        }
}
