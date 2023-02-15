# Advanced Topics
## Updating Googletest
Bazel and Googletest follows Google's internal philosphy of 
always running from "head", but building hermetically 
so builds are completely reproducible.  
But outside Google, it's not as easy to automatically stay
up to date.

In practice, this means the WORKSPACE file should be 
updated periodically with the latest commit number from
https://github.com/google/googletest.

## Changing C++ Version
Googletest currently (Feb. 2023) requires C++14.  
If Googletest, or other code in a repo, needs a newer
C++ version, then 2 files will need changing:
* .bazelrc - which is present here only for this purpose
* BUILD - specifically the COPTS variable
