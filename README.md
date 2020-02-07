# cplusplus-unittest
Example of a simple C++ unit test using the Google Test framework.  

You'll also want to read the [Google Test Primer](https://github.com/google/googletest/blob/master/googletest/docs/Primer.md) 
for help writing your own unit tests.

## Setup

This is the tedious part, and I'm sorry about that.  It's only necessary once per machine. :-)

First, install CMake by downloading it from https://cmake.org/download/.
Then put it in your path.  On a Mac, add the following line to the end of ~/.bash_profile:
* PATH="${PATH}:/Applications/CMake.app/Contents/bin"
and then open a new terminal window so this change takes effect. If it worked
* which cmake

should print something (the path to cmake).

Now clone the repo https://github.com/google/googletest the same
parent directory as this repo is cloned.  That is, this repo assumes
Google Test is present as ../googletest.  
That's important, because one repo should not contain another. 
So don't clone googletest into your own repo.

Now build googletest.  Assuming googletest is in the current directory, do these commands:
* cd googletest/googletest
* mkdir make
* cd make
* cmake ..

Then edit "Makefile" and add this line at the very beginning (right before the warning not to edit the file :-):
* CXXFLAGS = -std=c++11

Finally, run
* make

For Mac and Linux users, that's it.

**Note for Cygwin users (on Windows):** If you get compiler errors 
(perhaps including "error: 'fileno' was not declared in this scope"), 
try editing googletest/googletest/make/Makefile and changing "-std=c++11"
to "-std=g++11".  Then run "make" again.

You might need to use "-std=gnu++11" instead.  If make finishes without errors in googletest, 
but you get errors about "fileno" when linking your own code, 
try changing "-std=c++11" to "-std=gnu++11" in your own Makefile, too.

**Note for Windows Subsystem for Linux (WSL) users: (possibly obsolete)** 
In googletest/googletest/make/Makefile, make the following changes:
* Add "gtest.a gtest_main.a" to the all dependencies and clean command
```
all: ... gtest.a gtest_main.a
...
clean:
        rm -f gtest.a gtest_main.a *.o
        ...
```
* Add this stuff after "gtest_main.o" (approximately line 69 or 70)
```
gtest.a: gtest-all.o
        $(AR) $(ARFLAGS) $@ $^

gtest_main.a: gtest-all.o gtest_main.o
        $(AR) $(ARFLAGS) $@ $^
```

## Advanced Use
You probably won't need to consult it, but there is also lengthy [advanced Google Test documentation](https://github.com/google/googletest/blob/master/googletest/docs/advanced.md).  One useful topic is [how to run just some of the tests](https://github.com/google/googletest/blob/master/googletest/docs/advanced.md#running-test-programs-advanced-options).
