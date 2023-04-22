aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src common_src)
add_library(common ${common_src})
target_include_directories(common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_enable_doctest_in_lib(common)
