function(dump_cmake_variables)
    if(NOT ${ARGV0} STREQUAL "")
        set(suffix "_${ARGV0}")
    else()
        set(suffix "")
    endif()

    set(filename "${CMAKE_BINARY_DIR}/cmake_variables${suffix}.txt")
    file(WRITE ${filename} "all cmake variables: (for debugging cmake)\n")

    get_cmake_property(_variableNames VARIABLES)
    list(SORT _variableNames)

    foreach(_variableName ${_variableNames})
        file(APPEND ${filename} "${_variableName}=${${_variableName}}\n")
    endforeach()
endfunction()
