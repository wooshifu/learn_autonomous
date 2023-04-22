cmake_minimum_required(VERSION 3.16)

set(VCPKG_BOOTSTRAP_OPTIONS "-disableMetrics")
set(VCPKG_CMAKE_FILE "${CMAKE_CURRENT_SOURCE_DIR}/third-party/vcpkg/scripts/buildsystems/vcpkg.cmake")
if (NOT EXISTS "${VCPKG_CMAKE_FILE}")
    message(FATAL_ERROR "${VCPKG_CMAKE_FILE} not found, please make sure that you have executed `git submodule init && git submodule update`")
endif ()
set(CMAKE_TOOLCHAIN_FILE "${VCPKG_CMAKE_FILE}" CACHE STRING "Vcpkg toolchain file")


project(learn_autonomous)


enable_testing()


set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(compiler_options)
include(doctest)
include(dump_cmake_variables)
include(find_vcpkg_packages)
include(find_system_packages)


include(options)
add_subdirectory(src)


dump_cmake_variables()
