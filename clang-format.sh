#!/usr/bin/env bash

set -euo pipefail

source_files=$(find ./src -name "*.cpp" -o -name "*.cc" -o -name "*.c" -o -name "*.h" -o -name "*.hpp")
echo -e "formatting following source files\n${source_files}"
# shellcheck disable=SC2086
clang-format -i ${source_files}
