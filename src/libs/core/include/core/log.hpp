#pragma once

#ifndef SPDLOG_ACTIVE_LEVEL
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_DEBUG
#endif

#include <spdlog/cfg/argv.h>
#include <spdlog/cfg/env.h>
#include <spdlog/spdlog.h>

namespace core {

constexpr const char *default_spdlog_pattern{"%^[%H:%M:%S.%e][%L][%P:%t][%s:%#] %v%$"};
constexpr spdlog::level::level_enum default_debug_level = spdlog::level::level_enum::debug;

void setup_spdlog(int argc, char *argv[], const std::string &pattern = default_spdlog_pattern,
                  const spdlog::level::level_enum &level = default_debug_level) {
  spdlog::default_logger()->set_level(level);
  spdlog::cfg::load_env_levels();
  spdlog::cfg::load_argv_levels(argc, argv);

  spdlog::set_pattern(pattern);
}

#ifndef log_d
#define log_d(...) SPDLOG_DEBUG(__VA_ARGS__)
#endif

#ifndef log_i
#define log_i(...) SPDLOG_INFO(__VA_ARGS__)
#endif

#ifndef log_w
#define log_w(...) SPDLOG_WARN(__VA_ARGS__)
#endif

#ifndef log_e
#define log_e(...) SPDLOG_ERROR(__VA_ARGS__)
#endif

#ifndef log_c
#define log_c(...) SPDLOG_LEVEL_CRITICAL(__VA_ARGS__)
#endif

} // namespace core
