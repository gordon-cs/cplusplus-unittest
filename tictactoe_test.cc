// Tests for tictactoe.cc
//
// Author (starting point): Russ Tuck
// Authors (everything else):

#include <gtest/gtest.h>
#include <iostream>
using std::cout;
using std::endl;

#include "tictactoe.h"

TEST(tictactoe, verticalWinner) {
    TictactoeBoard b;
    EXPECT_EQ(TictactoeXO::none, b.winner());
    b.set(0, 0, TictactoeXO::X);
    b.set(1, 0, TictactoeXO::X);
    EXPECT_EQ(TictactoeXO::none, b.winner());
    b.set(2, 0, TictactoeXO::X);
    EXPECT_EQ(TictactoeXO::X, b.winner());
    b.set(1, 0, TictactoeXO::O);
    EXPECT_EQ(TictactoeXO::none, b.winner());
    b.set(0, 0, TictactoeXO::O);
    b.set(2, 0, TictactoeXO::O);
    EXPECT_EQ(TictactoeXO::O, b.winner());
}

// Dummy test, just to show running 2 tests.
TEST(tictactoe, dummy) {
    EXPECT_EQ(1, 1);
}
