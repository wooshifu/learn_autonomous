option(CONFIG_BUILD_SHARED_LIBS "build shared libs or not, build static library by default" OFF)
set(BUILD_SHARED_LIBS ${CONFIG_BUILD_SHARED_LIBS} CACHE BOOL "build shared library or not" FORCE)
message(STATUS "BUILD_SHARED_LIBS: ${BUILD_SHARED_LIBS}")

option(CONFIG_DISABLE_DOCTEST "disable doctest" OFF)
option(CONFIG_DISABLE_DOCTEST_IN_RELEASE "disable doctest in release mode" ON)

if(NOT DEFINED CMAKE_BUILD_TYPE OR CMAKE_BUILD_TYPE STREQUAL "")
    message(STATUS "setting cmake_build_type_lowercase to debug")
    set(cmake_build_type_lowercase "debug")
else()
    string(TOLOWER ${CMAKE_BUILD_TYPE} cmake_build_type_lowercase)
endif()

if(CONFIG_DISABLE_DOCTEST OR(CONFIG_DISABLE_DOCTEST_IN_RELEASE AND ${cmake_build_type_lowercase} MATCHES ".*rel.*"))
    message(STATUS "!!! doctest disabled")
    add_compile_definitions(DOCTEST_CONFIG_DISABLE)
endif()
