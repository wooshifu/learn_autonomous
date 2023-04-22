function(target_compile_strict target)
    target_compile_options(
            ${target}
            PRIVATE
            $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
            -Wall -Wextra -pedantic -Werror>
            $<$<CXX_COMPILER_ID:MSVC>:
            /W4 /WX>
    )
endfunction()
