# cplusplus-unittest
Example of a simple C++ unit test using the Google Test framework.
(Read the [Primer](https://github.com/google/googletest/blob/master/googletest/docs/Primer.md) 
for help writing unit tests.)

The repo https://github.com/google/googletest must be cloned in the same
parent directory as this repo is cloned.  That is, this repo assumes
Google Test is present as ../googletest.  If it's somewhere else, just
change the first line of Makefile.

After cloning https://github.com/google/googletest, build it with these 
commands:
* cd googletest/googletest/make
* make

For Mac and Linux users, that's it.

**Note for Cygwin users (on Windows):** If you get compiler errors 
(perhaps including "error: 'fileno' was not declared in this scope"), 
try editing googletest/googletest/make/Makefile and changing "-std=c++11"
to "-std=g++11".  Then run "make" again.

**Note for Windows Subsystem for Linux (WSL) users:** In googletest/googeltest/make/Makefile, make the following changes:
* Add "gtest.a gtest_main.a" to lines 47 and 50
```
all: $(GTEST_LIBS) $(TESTS) gtest.a gtest_main.a

clean:
        rm -f $(GTEST_LIBS) $(TESTS) gtest.a gtest_main.a *.o
```
* Add this stuff after "gtest_main.o" (approximately line 69 or 70)
```
gtest.a: gtest-all.o
        $(AR) $(ARFLAGS) $@ $^

gtest_main.a: gtest-all.o gtest_main.o
        $(AR) $(ARFLAGS) $@ $^
```
