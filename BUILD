cc_test(
  name = "hello_test",
  size = "small",
  srcs = ["hello_test.cc"],
  deps = ["@com_google_googletest//:gtest_main"],
)

cc_library(
  name = "tictactoe",
  srcs = ["tictactoe.cc"],
  hdrs = ["tictactoe.h"],
)

cc_test(
  name = "tictactoe_test",
  size = "small",
  srcs = ["tictactoe_test.cc"],
  deps = [":tictactoe",
          "@com_google_googletest//:gtest_main"],
)
