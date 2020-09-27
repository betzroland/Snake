#include <SFML/Graphics.hpp>
#include <time.h>
#include "Game.h"

using namespace std;
using namespace sf;

int main()
{
    Game game;

    srand(time(NULL));

    RenderWindow window(VideoMode(480, 360), "Snake");

    game.play_game(window);

return 0;
}
