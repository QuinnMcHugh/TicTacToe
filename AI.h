#ifndef AI_H
#define AI_H

#include "View.h"
#include "Board.h"

#include <vector>

typedef struct move_score_tuple {
		move m;
		int score;
} move_score_tuple;

class AI {
public:
	static move getMove(Board board, char turn);

private:

	static int evaluate(Board board, char turn);
	static vector<move> getPossibleMoves(Board board, char turn);
	static move_score_tuple miniMax(Board board, char turn, bool maximizingPlayer);
};

#endif
