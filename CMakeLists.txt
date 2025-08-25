cmake_minimum_required(VERSION 3.13)
project(shell)

file(GLOB SOURCE_FILES "src/*.c")
add_executable(shell ${SOURCE_FILES})
target_compile_options(shell PRIVATE -Wall -Wextra)

# Put executable in bin/ subdirectory
set_target_properties(shell PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
