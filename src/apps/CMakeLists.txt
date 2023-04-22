add_executable(learn_autonomous main.cpp)
target_compile_strict(learn_autonomous)
target_link_libraries(
        learn_autonomous
        PRIVATE
        core
        common
        fmt::fmt
        whereami
        spdlog::spdlog
        ghcFilesystem::ghc_filesystem
)
add_test(NAME doctest_learn_autonomous COMMAND $<TARGET_FILE:learn_autonomous> --exit)

add_executable(pcl_vis pcl_vis.cpp)
target_link_libraries(
        pcl_vis
        PRIVATE
        z
        pcl_visualization
        pcl_features
)
