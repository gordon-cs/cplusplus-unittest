GTEST_ROOT = ../googletest/googletest
GTEST_MAIN = $(GTEST_ROOT)/make/gtest_main.a

CPPFLAGS = -I $(GTEST_ROOT)/include

# Tictactoe uses C++ 2011.  Compile for debugging (-g) with warnings.
# Google Test needs -pthread.
CXXFLAGS = -std=c++11 -g -Wall -Wextra -pthread

test:	tictactoe_test

tictactoe.cc:		tictactoe.h
tictactoe_test.cc:	tictactoe.h

tictactoe_test:		tictactoe_test.o tictactoe.o $(GTEST_MAIN)
	g++ -o $@ $^
