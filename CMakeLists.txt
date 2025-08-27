cmake_minimum_required(VERSION 3.10)
project(Simple_Shell)

set(CMAKE_C_STANDARD 99)

# Include directories
include_directories(src)
include_directories(src/parser)
include_directories(src/commands)

# Source files
set(SOURCES
    src/main.c
    src/parser/parser.c
    src/commands/commands.c
)

# Add the executable (this was missing!)
add_executable(shell ${SOURCES})

# Set output directory
set_target_properties(shell PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
