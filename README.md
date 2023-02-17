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

1. Install Bazel: Follow
   [these instructions](https://docs.bazel.build/versions/5.0.0/install.html)
   for your operating system.  The following notes may help.

   1. On **Windows**, consider whether you develop in Windows itself (probably
      using git-bash), or in WSL.  If you do your coding in WSL,
      follow the Linux install instructions for Bazel.  There are several
      options, and I found "Using Bazel's apt repository" worked well.

      If you do your coding in Windows itself, then you can probably skip the
      "Install the prerequisites," step in the Windows instructions,
      since you have C++ working already.
      Also, when you go to the Bazel website, scroll down to the "Latest"
      version (skipping all the "pre-", or pre-release versions), then
      keep going to the "Assets" section.  You probably want
      "bazel-5.0.0-windows-x86_64.exe".

      Note that this file is
      the actual program, not the installer, which is why the instructions
      say to rename it and put it in your path.  
      When you finish, `bazel --version` should work.

   2. On **MacOS**, I recommend the "Homebrew" option.  If you already have
      Homebrew installed, it's just one command: "brew install bazel".
      (And if you don't, it's just one command to install homebrew first.)
      When you finish, `bazel --version` should work.
      
      **On newer versions of MacOS, that's all you need to do.  However, 
      if brew says your MacOS version is too old, the rest of this section
      might help.**
      
      Note: On some older versions of MacOS, "brew install bazel" fails, 
      or the resulting bazel install doesn't work.  The rest of this section applies only
      In this case, try using nvm, similarly to Linux.  Start with

            brew install nvm

      If `which nvm` returns a path, then you are ready for the next 
      set of commands. Otherwise, follow the instructions printed by
      brew about what to add to your `~/.bash_profile` file (creating
      it if it doesn't already exist).  You may also need to create 
      a symlink with `cd ~/.nvm; ln -s nvm-exec nvm` and add ~/.nvm
      to your path by adding this line to ~/.bash_profile:
      `export PATH=$PATH:$HOME/.nvm`.  
      Then type `source ~/.bash_profile`.
      Now `which nvm` should return a path.
      
      Now that you've installed nvm, continue with:

            nvm install --lts
            nvm use --lts
            npm install -g @bazel/bazelisk
            
      Now `bazel --version` should work.
            
   3. On **Linux**, including the lab workstations, 
      use the recommended "bazelisk" approach, which
      requires npm.  Get npm via nvm. 
      Briefly (assuming nothing has changed):
      
            curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.39.3/install.sh | bash

      (If you have trouble installing nvm, [these instructions](https://github.com/nvm-sh/nvm#installing-and-updating) may help.)
      
      Now, use nvm to install npm, and then npm to install bazel:

            # (then close the terminal and open another to update the path)
            nvm install --lts
            nvm use --lts
            npm install -g @bazel/bazelisk

      Now `bazel --version` should work.

1. Clone this repo and cd into it.
(Special note: be sure that no directory in the path to your repo contains
a space.  If it does, Bazel will complain with an error message and quit.)
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
One useful topic is
[how to run just some of the tests](https://google.github.io/googletest/advanced.html#running-test-programs-advanced-options).
