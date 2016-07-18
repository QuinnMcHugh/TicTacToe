#include <iostream>
#include "Game.h"

using namespace std;

int main()
{
    Game game(Game::HUMAN_VS_AI);

    game.play();

    return 0;
}
