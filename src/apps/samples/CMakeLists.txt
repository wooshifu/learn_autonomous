add_executable(sample_imgui sample_imgui.cc)
target_link_libraries(sample_imgui PRIVATE imgui::imgui glbinding::glbinding glbinding::glbinding-aux)

add_executable(sample_ceres_solver sample_ceres_solver.cc)
target_link_libraries(sample_ceres_solver PRIVATE Ceres::ceres)
