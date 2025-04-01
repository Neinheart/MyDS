cmake_minimum_required(VERSION 3.16)
project(DSUTestFramework)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directories
include_directories(
        include
        test
        bench
        common
        third_party
)

# Collect all source, test, benchmark, and main files
file(GLOB_RECURSE SRC src/*.cpp)
file(GLOB_RECURSE TEST test/*.cpp)
file(GLOB_RECURSE BENCH bench/*.cpp)
file(GLOB_RECURSE MAIN main.cpp)

# Build the main executable
add_executable(main ${SRC} ${TEST} ${BENCH} ${MAIN})