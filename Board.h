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
    string toString();
private:
    const int ROWS = 3;
    const int COLS = 3;

    char matrix[3][3];
};

#endif
