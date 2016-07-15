#include <iostream>
#include "Board.h"

using namespace std;

int main()
{
    Board board;

    board.setSymbol(Board::X, 0, 0);

    cout << board.toString() << endl;

    return 0;
}
