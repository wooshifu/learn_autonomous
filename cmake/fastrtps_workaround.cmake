function(copy_fast_discovery_server)
    set(linux_or_darwin Linux Darwin)

    if(CMAKE_SYSTEM_NAME IN_LIST linux_or_darwin)
        set(fast_discovery_server_name_debug fast-discovery-serverd-1.0.0)
        set(fast_discovery_server_name fast-discovery-server-1.0.0)
    elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
        set(fast_discovery_server_name_debug fast-discovery-serverd-1.0.0.exe)
        set(fast_discovery_server_name fast-discovery-server-1.0.0.exe)
    endif()

    set(fast_discovery_server_debug ${PROJECT_SOURCE_DIR}/third-party/vcpkg/buildtrees/fastrtps/${VCPKG_TARGET_TRIPLET}-dbg/tools/fds/${fast_discovery_server_name_debug})

    set(fast_discovery_server ${PROJECT_SOURCE_DIR}/third-party/vcpkg/buildtrees/fastrtps/${VCPKG_TARGET_TRIPLET}-rel/tools/fds/${fast_discovery_server_name})

    set(fast_discovery_server_dest ${CMAKE_BINARY_DIR}/vcpkg_installed/${VCPKG_TARGET_TRIPLET}/tools/fastrtps)

    if(NOT EXISTS ${fast_discovery_server_dest})
        file(MAKE_DIRECTORY ${fast_discovery_server_dest})
    endif()

    if(EXISTS ${fast_discovery_server_debug} AND NOT EXISTS ${fast_discovery_server_dest}/${fast_discovery_server_name_debug})
        file(COPY ${fast_discovery_server_debug} DESTINATION ${fast_discovery_server_dest})
        message(STATUS "copied ${fast_discovery_server_debug} to ${fast_discovery_server_dest}")
    endif()

    if(EXISTS ${fast_discovery_server} AND NOT EXISTS ${fast_discovery_server_dest}/${fast_discovery_server_name})
        file(COPY ${fast_discovery_server} DESTINATION ${fast_discovery_server_dest})
        message(STATUS "copied ${fast_discovery_server} ${fast_discovery_server_dest}")
    endif()
endfunction()
