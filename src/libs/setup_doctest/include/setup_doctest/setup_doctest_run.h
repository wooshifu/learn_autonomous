#pragma once

#include <doctest/doctest.h>
#include <tuple>

std::tuple<bool, int> run_doctest(int argc, char *argv[]) {
#ifdef DOCTEST_CONFIG_DISABLE
  (void)argc;
  (void)argv;
  return {false, 0};
#else
  doctest::Context context;
  context.applyCommandLine(argc, argv);
  int success = context.run();                   // run
  const bool should_exit = context.shouldExit(); // important - query flags (and --exit) rely on the user doing this
  return {should_exit, success};
#endif
}
