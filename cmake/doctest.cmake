function(add_executable_doctest target)
    set(doctest_main_dir ${CMAKE_BINARY_DIR}/doctest)
    set(doctest_main_file ${doctest_main_dir}/doctest_main.cc)
    if (NOT EXISTS ${doctest_main_dir})
        file(MAKE_DIRECTORY ${doctest_main_dir})
    endif ()
    if (NOT EXISTS ${doctest_main_file})
        set(doctest_main_source "
#include \"setup_doctest/setup_doctest_main.h\"
")
        file(WRITE ${doctest_main_file} ${doctest_main_source})
    endif ()
    set(target_name doctest_${target})
    add_executable(${target_name} ${doctest_main_file})
    target_link_libraries(${target_name} PRIVATE ${target} setup_doctest)

    add_test(NAME ${target_name} COMMAND $<TARGET_FILE:${target_name}>)
endfunction()

function(target_enable_doctest_in_lib target)
    get_target_property(target_type ${target} TYPE)
    if (target_type STREQUAL SHARED_LIBRARY)
        set(doctest_in_dll_dir ${CMAKE_BINARY_DIR}/doctest)
        set(doctest_in_dll_file ${doctest_in_dll_dir}/doctest_in_dll.cc)
        if (NOT EXISTS ${doctest_in_dll_dir})
            file(MAKE_DIRECTORY ${doctest_in_dll_dir})
        endif ()
        if (NOT EXISTS ${doctest_in_dll_file})
            set(doctest_in_dll_source "
#define DOCTEST_CONFIG_IMPLEMENTATION_IN_DLL
#define DOCTEST_CONFIG_IMPLEMENT
#include <doctest/doctest.h>
")
            file(WRITE ${doctest_in_dll_file} ${doctest_in_dll_source})
        endif ()
        target_sources(${target} PRIVATE ${doctest_in_dll_file})
        target_link_libraries(${target} PUBLIC doctest::doctest)

        add_executable_doctest(${target})
    elseif (target_type STREQUAL STATIC_LIBRARY)
        include(doctest_force_link_static_lib_in_target)
        set(target_name doctest_${target})
        doctest_make_exe_for_static_lib(${target_name} ${target})
    else ()
        message(FATAL_ERROR "enable doctest in lib to target \"${target}\" for type ${target_type} is not supported yet")
    endif ()
endfunction()
