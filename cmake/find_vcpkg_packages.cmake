find_package(Armadillo CONFIG REQUIRED)
find_package(CLI11 CONFIG REQUIRED)
find_package(cppitertools CONFIG REQUIRED)
find_package(doctest CONFIG REQUIRED)
find_package(Eigen3 CONFIG REQUIRED)
find_package(fastcdr CONFIG REQUIRED)
include(fastrtps_workaround)
copy_fast_discovery_server()
find_package(fastrtps CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(ghc_filesystem CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glbinding CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(lz4 CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(OpenCV CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(PCL CONFIG REQUIRED)
find_package(Poco CONFIG REQUIRED COMPONENTS JSON XML Util)
find_package(protobuf CONFIG REQUIRED)
find_package(re2 CONFIG REQUIRED)
find_package(SDL2 CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(Taskflow CONFIG REQUIRED)
find_package(tl-expected CONFIG REQUIRED)
find_package(unofficial-concurrentqueue CONFIG REQUIRED)
find_package(unofficial-hash-library CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(yaml-cpp CONFIG REQUIRED)
find_package(ZLIB REQUIRED)

find_path(HEDLEY_INCLUDE_DIRS "hedley.h")
include_directories(${HEDLEY_INCLUDE_DIRS})
find_path(DBG_MACRO_INCLUDE_DIRS "dbg.h")
include_directories(${DBG_MACRO_INCLUDE_DIRS})
