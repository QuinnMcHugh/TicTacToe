#ifndef BOARD_H
#define BOARD_H

#include <string>

using namespace std;

class Board {
public:
    static const char X = 'X';
    static const char O = 'O';
    static const char BLANK = ' ';

    Board();
    void clear();
    char getWinner();
    bool isBlank(int x, int y);
    void setSymbol(char sym, int x, int y);
    bool gameIsOver();
    string toString();
private:
    static const int ROWS = 3;
    static const int COLS = 3;

    char matrix[3][3];
};

#endif
