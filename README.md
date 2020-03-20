# cplusplus-unittest
Example of a simple C++ unit test using the Google Test framework.  

You'll also want to read the [Google Test Primer](https://github.com/google/googletest/blob/master/googletest/docs/Primer.md) 
for help writing your own unit tests.

## Setup Googletest
On Gordon's Linux workstations, googletest is already set up.  Use this
path in your Makefile:
* GTEST_ROOT = /gc/cps222/googletest/googletest

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

At this point, the instructions vary slightly by operating system and compiler.

#### Linux and Mac
* make

#### Windows with Mingw or Cygwin
Edit "Makefile" as follows:
* change "-std=c++11" to "-std=gnu++11" on line 31
* delete "-pthread" on line 31 and the last line in the file

Now, run
* make

Note: if you get a compile error about "::OpenThread is not declared",
try editing "Makefile", finding the line that defines CPPFLAGS, and 
adding this to the end:
* -DWINVER=0x0500

(Found this in https://github.com/google/googletest/issues/893)

#### Windows Subsystem for Linux (WSL)
Edit "Makefile" as follows:
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

## Compiling and Running Unit Tests
On Linux and Mac, just run 
* make

On Windows with Cygwin or Mingw, edit "Makefile" as follows
(just like in googletest/make):
* change "-std=c++11" to "-std=gnu++11"
*  delete "-pthread" on the last line

Now, run
* make

## Advanced Use
You probably won't need to consult it, but there is also lengthy [advanced Google Test documentation](https://github.com/google/googletest/blob/master/googletest/docs/advanced.md).  One useful topic is [how to run just some of the tests](https://github.com/google/googletest/blob/master/googletest/docs/advanced.md#running-test-programs-advanced-options).
