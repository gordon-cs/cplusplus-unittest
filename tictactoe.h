// Declares classes for a Tic-tac-toe program to be used in a CPS 222
// lab on Git and GitHub.
//
// Author (starting point): Russ Tuck
// Authors (everything else):

// Instructor's note: the #ifndef/define/endif TICTACTOE_H_ statements are
// a "header guard".  Together, they make it safe to #include this file
// anywhere it's needed: extra #includes will be ignored.
#ifndef TICTACTOE_H_
#define TICTACTOE_H_

#include <iostream>
using std::istream;

enum class TictactoeXO {X, O, none};

// Stores and manipulates the board and state of a Tic-tac-toe game.
// Example:
//
class TictactoeBoard {
public:
    TictactoeXO get(unsigned row, unsigned col);
    void set(unsigned row, unsigned col, TictactoeXO player);

    // Checks for a winner and returns result (none if no winner).
    TictactoeXO winner();

private:
    TictactoeXO board_[3][3] = {
        { TictactoeXO::none, TictactoeXO::none, TictactoeXO::none},
        { TictactoeXO::none, TictactoeXO::none, TictactoeXO::none},
        { TictactoeXO::none, TictactoeXO::none, TictactoeXO::none}
    };

};

// Encapsulates one move in Tic-tac-toe.
class TictactoeMove {
public:
    // Constructor.  player indicates whether to place an X or O (circle).
    // (row, col) identifies place on board; (0,0) is bottom left.
    TictactoeMove(TictactoeXO player, unsigned row, unsigned col);

    // Constructor reads coordinates from input stream in format
    //   row col
    // example input for center square:
    //   1 1
    TictactoeMove(TictactoeXO player, istream input);

    // getters
    TictactoeXO player();
    unsigned row();
    unsigned col();

private:
    TictactoeXO player_;

    // location on board: (0,0) is bottom left
    unsigned row_;
    unsigned col_;
};

// Stores and manages a Tic-tac-toe game.
class TictactoeGame {
public:

private:
    TictactoeBoard board_;
    // Instructor's note:
    // http://en.cppreference.com/w/cpp/language/nullptr explains nullptr and
    // http://www.stroustrup.com/bs_faq2.html#null explains why to use it.
/*
    TictactoeMove* moves_[9] = {
        nullptr, nullptr, nullptr,
        nullptr, nullptr, nullptr,
        nullptr, nullptr, nullptr
    };
*/
};

#endif // TICTACTOE_H_
