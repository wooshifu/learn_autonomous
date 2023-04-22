#pragma once

#include "setup_doctest_run.h"

#include <tuple>

int main(int argc, char *argv[]) { return std::get<1>(run_doctest(argc, argv)); }
