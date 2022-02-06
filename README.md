# cplusplus-unittest
This repo is an example of writing and running simple C++ unit tests
using the Google Test framework.

This README explains how to get started,
how to build programs with Bazel,
and how to write unit tests
(mostly with references to appropriate documentation).

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
        //:tictactoe_test                       PASSED
        INFO: Build completed successfully, XX total actions

    When you run it again, it should be very fast.
    If you run it again without changing any files,
    it will print "(cached) PASSED"
    to indicate that it didn't need to do anything.

If you have trouble, consult GoogleTest's
[Quickstart: Building with Bazel](https://google.github.io/googletest/quickstart-bazel.html).


## Compiling and Running Your Own Unit Tests

There are two parts to this: building your code with Bazel,
and writing unit tests.

### Bazel Rules
Start by reading this brief [Bazel Overview](https://docs.bazel.build/versions/5.0.0/bazel-overview.html).
Then look at these
[example C++ rules](https://github.com/bazelbuild/bazel/blob/master/examples/cpp/BUILD)
and the BUILD file in this repo to get some practical insight.

That might be all you need to get started.
But you should read
[Bazel Tutorial: Build a C++ Project](https://docs.bazel.build/versions/5.0.0/tutorial/cpp.html)
to get a better understanding for larger projects.  Consult
[Common C++ Build Use Cases](https://docs.bazel.build/versions/5.0.0/cpp-use-cases.html)
for more details as you need to do new things.

### Unit Tests
You can get started by imitating the tests in tictactoe_test.cc,
but you should also read the
[Googletest Primer](https://google.github.io/googletest/primer.html).

You won't need to consult it right away, but the lengthy
[Advanced googletest Topics](https://google.github.io/googletest/advanced.html)
explains many powerful Googletest features.
One useful topic is [how to run just some of the tests]
(https://google.github.io/googletest/advanced.html#running-test-programs-advanced-options).
