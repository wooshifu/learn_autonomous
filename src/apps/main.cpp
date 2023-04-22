#include "core/log.hpp"
#include "setup_doctest/setup_doctest_run.h"
#include "whereami/whereami.hpp"

#include <ghc/filesystem.hpp>

namespace fs = ghc::filesystem;

TEST_CASE("main test") { REQUIRE(false); }

int main(int argc, char *argv[]) {
  core::setup_spdlog(argc, argv);

  const auto &[exit, err] = run_doctest(argc, argv);
  if (exit || err) {
    return err;
  }

  log_d("debug log");
  for (const auto &file : fs::directory_iterator(fs::path(get_executable_path()).parent_path())) {
    SPDLOG_INFO("file: {}", fs::absolute(file.path()).lexically_normal().u8string());
  }
  SPDLOG_WARN("warning log");
  SPDLOG_ERROR("error log");

  return 0;
}
