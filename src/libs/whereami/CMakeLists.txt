add_library(whereami src/whereami.c)
target_include_directories(whereami PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/whereami)
target_include_directories(whereami PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
