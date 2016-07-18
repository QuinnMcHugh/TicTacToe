#include "Game.h"
#include "Board.h"
#include "AI.h"
#include <iostream>

Game::Game(Game::GameType type){
    board = Board();
    Game::type = type;
}

void Game::play(){
    board.clear();

    enum PlayerType {
        HUMAN,
        COMPUTER
    };

    PlayerType xType, oType;
    if (Game::type == Game::HUMAN_VS_HUMAN){
        xType = oType = HUMAN;
    }
    else {
        // For randomizing which symbol the user is, add in a randomized if test here
        xType = HUMAN;
        oType = COMPUTER;
    }

    // X always goes first...because I say so
    char turn = Board::X;
    while (!board.gameIsOver()){
        cout << board.toString() << endl;
        move m;
        if (turn == Board::X){
            if (xType == HUMAN){
                m = getUserMove(turn, board);
            }
            else {
                m = AI::getMove(board, turn);
            }
        }
        else {
            if (oType == HUMAN){
                m = getUserMove(turn, board);
            }
            else {
                m = AI::getMove(board, turn);
            }
        }
        executeMove(m);
        turn = (turn == Board::X) ? Board::O : Board::X;
    }

    cout << board.toString() << endl;
    if (board.getWinner() == Board::BLANK){
    	cout << "Cat's game." << endl;
    }
    else {
    	cout << ((board.getWinner() == Board::X) ? "X" : "O") << " Wins." << endl;
    }
    cout << "Game over." << endl;
}

void Game::executeMove(move m){
    board.setSymbol(m.symbol, m.x, m.y);
}
