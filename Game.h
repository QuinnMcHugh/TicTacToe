#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "View.h"

class Game {
public:
    enum GameType {
        HUMAN_VS_HUMAN,
        HUMAN_VS_AI
    };

    Game(Game::GameType type);
    void play();

private:
    Board board;
    Game::GameType type;

    void executeMove(move m);
};

#endif
