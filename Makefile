GTEST_ROOT = ../googletest/googletest
GTEST_MAIN = $(GTEST_ROOT)/make/gtest_main.a

CPPFLAGS = -I $(GTEST_ROOT)/include

# Tictactoe uses C++ 2011.  Compile for debugging (-g) with warnings.
CXXFLAGS = -std=c++11 -g -Wall -Wextra

test:	tictactoe_test

tictactoe.cc:		tictactoe.h
tictactoe_test.cc:	tictactoe.h

tictactoe_test:		tictactoe_test.o tictactoe.o $(GTEST_MAIN)
# On Linux, need -pthread after gtest_main.a to link correctly.
# On Mac, the -pthread gives a harmless warning that it's not needed.
	g++ -o $@ $^ -pthread
