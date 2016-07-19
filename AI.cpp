#include "AI.h"

#include <iostream>
#include <climits>

move AI::getMove(Board board, char turn){
	move_score_tuple bestTuple;

	vector<move> moves = AI::getPossibleMoves(board, turn);
	bestTuple = miniMax(board, turn, true);
	// cout << "X: " << bestTuple.m.x << " Y: " << bestTuple.m.y << " Score: " << bestTuple.score << endl;

	return bestTuple.m;
}

int AI::evaluate(Board board, char perspective){
	char winner = board.getWinner();
	if (winner == perspective){
		return 100;
	}
	else if (winner == Board::BLANK){
		return 0;
	}
	else {
		return -100;
	}
}

vector<move> AI::getPossibleMoves(Board board, char turn){
	vector<move> moves;

	for (int i = 0; i < Board::ROWS; i++){
		for (int j = 0; j < Board::COLS; j++){
			if (board.isBlank(j, i)){
				move m;
				m.x = j;
				m.y = i;
				m.symbol = turn;

				moves.push_back(m);
			}
		}
	}

	return moves;
}

move_score_tuple AI::miniMax(Board board, char turn, bool maximizingPlayer){
	if (board.gameIsOver()){
		move_score_tuple ret;

		// denotes that the move is impossible and a terminal state has been reached
		ret.m.x = -1;
		ret.m.y = -1;

		ret.score = evaluate(board, (maximizingPlayer) ? turn : ((turn == Board::X) ? Board::O : Board::X));

		return ret;
	}

	int bestVal;
	move bestMove;

	vector<move> possibleMoves = AI::getPossibleMoves(board, turn);
	if (maximizingPlayer){
		bestVal = INT_MIN;
		for (int i = 0; i < possibleMoves.size(); i++){
			board.setSymbol(turn, possibleMoves.at(i).x, possibleMoves.at(i).y);

			move_score_tuple curTuple = miniMax(board, (turn == Board::X) ? Board::O : Board::X, false);
			if (curTuple.score > bestVal){
				bestVal = curTuple.score;
				bestMove = possibleMoves.at(i);
			}
			
			board.setSymbol(Board::BLANK, possibleMoves.at(i).x, possibleMoves.at(i).y);
		}
	}
	else {
		bestVal = INT_MAX;
		for (int i = 0; i < possibleMoves.size(); i++){
			board.setSymbol(turn, possibleMoves.at(i).x, possibleMoves.at(i).y);

			move_score_tuple curTuple = miniMax(board, (turn == Board::X) ? Board::O : Board::X, true);
			if (curTuple.score < bestVal){
				bestVal = curTuple.score;
				bestMove = possibleMoves.at(i);
			}
			
			board.setSymbol(Board::BLANK, possibleMoves.at(i).x, possibleMoves.at(i).y);
		}
	}

	move_score_tuple bestTuple;
	bestTuple.score = bestVal;
	bestTuple.m = bestMove;

	return bestTuple;
}

