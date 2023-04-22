#pragma once

#include "whereami.h"

#include <string>
#include <tl/expected.hpp>

inline tl::expected<std::string, int> expect_executable_path() {
  int length = wai_getExecutablePath(nullptr, 0, nullptr);
  std::string path(static_cast<std::string::size_type>(length), 0);
  int err = wai_getExecutablePath(path.data(), length, nullptr);
  if (err < 0) {
    return tl::make_unexpected(err);
  }
  return path;
}
inline std::string get_executable_path() { return expect_executable_path().value(); }

inline tl::expected<std::string, int> expect_module_path() {
  int length = wai_getModulePath(nullptr, 0, nullptr);
  std::string path(static_cast<std::string::size_type>(length), 0);
  int err = wai_getModulePath(path.data(), length, nullptr);
  if (err < 0) {
    return tl::make_unexpected(err);
  }
  return path;
}
inline std::string get_module_path() { return expect_module_path().value(); }
