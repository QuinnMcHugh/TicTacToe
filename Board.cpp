#include "Board.h"
#include <sstream>

using namespace std;

Board::Board() {
    clear();
}

void Board::clear() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = Board::BLANK;
        }
    }
}

char Board::getWinner() {
    // Check for horizontal win
    for (int i = 0; i < ROWS; i++){
        if (matrix[i][0] == matrix[i][1] &&
            matrix[i][1] == matrix[i][2] &&
            matrix[i][1] != BLANK){
            return matrix[i][1];
        }
    }

    // Check for vertical win
    for (int i = 0; i < COLS; i++){
        if (matrix[0][i] == matrix[1][i] &&
            matrix[1][i] == matrix[2][i] &&
            matrix[1][i] != BLANK){
            return matrix[1][i];
        }
    }

    // Check for diagonal win
    if (matrix[0][0] == matrix[1][1] &&
        matrix[1][1] == matrix[2][2] &&
        matrix[1][1] != BLANK){
        return matrix[1][1];
    }
    else if (matrix[2][0] == matrix[1][1] &&
             matrix[1][1] == matrix[0][2] &&
             matrix[1][1] != BLANK){
        return matrix[1][1];
    }

    return BLANK;
}

bool Board::isBlank(int x, int y){
    return matrix[y][x] == Board::BLANK;
}

void Board::setSymbol(char sym, int x, int y){
    matrix[y][x] = sym;
}

bool Board::gameIsOver(){
	if (getWinner() != BLANK){
		return true;
	}
	else {
		int filledSpots = 0;
		for (int i = 0; i < ROWS; i++){
			for (int j = 0; j < COLS; j++){
				if (!isBlank(j, i)){
					filledSpots++;
				}
			}
		}
		if (filledSpots == ROWS * COLS){
			return true;
		}
	}
	return false;
}

std::string Board::toString() {
    ostringstream oss;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            oss << " " << matrix[i][j] << " ";
            if (j < COLS - 1) {
                oss << "|";
            }
        }
        if (i < ROWS - 1) {
            oss << "\n---|---|---";
        }
        oss << "\n";
    }

    return oss.str();
}
