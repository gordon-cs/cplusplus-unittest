# cplusplus-unittest
Example of a simple C++ unit test using the Google Test framework.  

You'll also want to read the [Google Test Primer](https://github.com/google/googletest/blob/master/googletest/docs/Primer.md) 
for help writing your own unit tests.

## Setup
On Gordon's Linux workstations, googletest is already set up.  Use this
path in your Makefile:
* GTEST_ROOT = /gc/cps222/googletest

Otherwise, the repo https://github.com/google/googletest must be cloned in 
the same parent directory as this repo is cloned.  That is, this repo assumes
Google Test is present as ../googletest.  
That's important, because one repo should not contain another. 
So don't clone googletest into your own repo.

The latest versions of googletest have build and link issues. (I can't get
them to work.)  Fortunately, older versions are still fine to use.
So, after cloning https://github.com/google/googletest, check out a working
version and build it with these commands:
* git checkout 8b6d3f9c4a774bef3081195d422993323b6bb2e0
* cd googletest/googletest/make
* make

For Mac and Linux users, that's it.

**Note for Cygwin users (on Windows):** If you get compiler errors 
(perhaps including "error: 'fileno' was not declared in this scope"), 
try editing googletest/googletest/make/Makefile and changing "-std=c++11"
to "-std=g++11".  Then run "make" again.

You might need to use "-std=gnu++11" instead.  If make finishes without errors in googletest, 
but you get errors about "fileno" when linking your own code, 
try changing "-std=c++11" to "-std=gnu++11" in your own Makefile, too.

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

## Advanced Use
You probably won't need to consult it, but there is also lengthy [advanced Google Test documentation](https://github.com/google/googletest/blob/master/googletest/docs/advanced.md).  One useful topic is [how to run just some of the tests](https://github.com/google/googletest/blob/master/googletest/docs/advanced.md#running-test-programs-advanced-options).
