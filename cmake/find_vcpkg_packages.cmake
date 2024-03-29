find_package(Armadillo CONFIG REQUIRED)
find_package(Ceres CONFIG REQUIRED)
find_package(CLI11 CONFIG REQUIRED)
find_package(cppitertools CONFIG REQUIRED)
find_package(doctest CONFIG REQUIRED)
find_package(Eigen3 CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(ghc_filesystem CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glbinding CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(re2 CONFIG REQUIRED)
find_package(SDL2 CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(Taskflow CONFIG REQUIRED)
find_package(tl-expected CONFIG REQUIRED)
find_package(unofficial-concurrentqueue CONFIG REQUIRED)
find_package(unofficial-hash-library CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(yaml-cpp CONFIG REQUIRED)

find_path(HEDLEY_INCLUDE_DIRS "hedley.h")
include_directories(${HEDLEY_INCLUDE_DIRS})
find_path(DBG_MACRO_INCLUDE_DIRS "dbg.h")
include_directories(${DBG_MACRO_INCLUDE_DIRS})
