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
