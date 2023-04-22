#include <doctest/doctest.h>
#include <string>

bool str_contains(const std::string &str, const std::string &contain) {
  (void)str;
  (void)contain;
  return false;
}

TEST_CASE("should str contains success") {
  CHECK(str_contains("abcdef", "bcd"));
}
