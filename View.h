#ifndef VIEW_H
#define VIEW_H

#include "Board.h"

typedef struct move {
    int x, y;
    char symbol;
} move;

move getUserMove(char symbol, Board& board);

#endif
