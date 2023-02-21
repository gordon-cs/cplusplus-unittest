# Global compile options
# - warnings are useful
# - Google test needs C++14 (as of 2023)
COPTS = ["-Wall", "-Wextra", "-std=c++14"]

cc_test(
  name = "hello_test",
  size = "small",
  srcs = ["hello_test.cc"],
  deps = ["@com_google_googletest//:gtest_main"],
  copts = COPTS,
)

cc_library(
  name = "tictactoe",
  srcs = ["tictactoe.cc"],
  hdrs = ["tictactoe.h"],
  copts = COPTS,
)

cc_test(
  name = "tictactoe_test",
  size = "small",
  srcs = ["tictactoe_test.cc"],
  deps = [":tictactoe",
          "@com_google_googletest//:gtest_main"],
  copts = COPTS,
)
