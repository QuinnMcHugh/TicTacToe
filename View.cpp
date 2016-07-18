#include "View.h"
#include <iostream>

using namespace std;

move getUserMove(char symbol, Board& board){
    move userMove;

    bool validInput = false;
    while (!validInput){
        cout << symbol << "'s turn. Enter your move (ex. 'x, y'): ";
        string input;
        getline(cin, input);

        int digitsEncountered = 0;
        for (int i = 0; i < input.length(); i++){
            if (input.at(i) >= '0' && input.at(i) <= '9'){
                digitsEncountered++;
                if (digitsEncountered == 1){
                    userMove.x = (int)(input.at(i) - '0');
                }
                else if (digitsEncountered == 2){
                    userMove.y = (int)(input.at(i) - '0');
                    break;
                }
            }
        }

        if (userMove.x >= 0 && userMove.x < 3){
            if (userMove.y >= 0 && userMove.y < 3){
                if (board.isBlank(userMove.x, userMove.y)){
                    userMove.symbol = symbol;
                    validInput = true;
                }
            }
        }
    }

    return userMove;
}
