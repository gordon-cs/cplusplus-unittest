// Implements classes for a Tic-tac-toe program to be used in a CPS 222
// lab on Git and GitHub.
//
// Author (starting point): Russ Tuck
// Authors (everything else):

#include "tictactoe.h"

TictactoeXO TictactoeBoard::get(unsigned row, unsigned col) {
    return board_[row][col];
}

void TictactoeBoard::set(unsigned row, unsigned col, TictactoeXO player) {
    board_[row][col] = player;
}

TictactoeXO TictactoeBoard::winner() {
    for (int r = 0; r < 3; r++) {
        if (board_[r][0] == board_[r][1] &&
            board_[r][1] == board_[r][2] &&
            board_[r][0] != TictactoeXO::none) {
            return board_[r][0];
        }
    }
    for (int c = 0; c < 3; c++) {
        if (board_[0][c] == board_[1][c] &&
            board_[1][c] == board_[2][c] &&
            board_[0][c] != TictactoeXO::none) {
            return board_[0][c];
        }
    }
    if (board_[0][0] == board_[1][1] &&
        board_[1][1] == board_[2][2] &&
        board_[0][0] != TictactoeXO::none) {
        return board_[0][0];
    }
    if (board_[0][2] == board_[1][1] &&
        board_[1][1] == board_[2][0] &&
        board_[0][2] != TictactoeXO::none) {
        return board_[0][2];
    }
    return TictactoeXO::none;
}
