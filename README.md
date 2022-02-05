# cplusplus-unittest
Example of a simple C++ unit test using the Google Test framework.

You'll also want to read the [Googletest Primer](https://google.github.io/googletest/primer.html)
for help writing your own unit tests.

## Setup Bazel to build and run tests
Googletest is probably easiest to use with Bazel,
which is a build system Google developed and supports.
While it's a very powerful system, it's more complicated than Make.
So a goal of this example is to get you started as easily as possible.

1. Install Bazel: Follow [these instructions](https://docs.bazel.build/versions/5.0.0/install.html) for your operating system.  (See note below about the Linux  Lab workstations.)
1. Clone this repo and cd into it.
(Special note: be sure that no directory in the path to your repo contains
a space.  If it does, Bazel will complain with anerror message and quit.)
1. Run this command:
        bazel test :all
    It will download a lot of stuff (over 700MB, including Googletest)
    the first time (a little like npm install),
    but should eventually print something like
        //:hello_test                           PASSED
        INFO: Build completed successfully, XX total actions
    If you run it again, it should be very fast.

If you have trouble, consult GoogleTest's [Quickstart: Building with Bazel]
(https://google.github.io/googletest/quickstart-bazel.html).


## Compiling and Running Your Own Unit Tests

There are two parts to this: building your code with Bazel,
and writing unit tests.



## Advanced Use
You won't need to consult it right away, but the
lengthy [Advanced googletest Topics](https://google.github.io/googletest/advanced.html) explains how to many powerful things.
One useful topic is [how to run just some of the tests]
(https://google.github.io/googletest/advanced.html#running-test-programs-advanced-options).
