#cmake_minimum_required (version 3)
project (test111)
include_directories ("${PROJECT_BINARY_DIR}")

file(GLOB SOURCES
    ./main.cpp
    ./mfun.cpp
    #    ./mfun.h
    )
add_executable (test111 ${SOURCES})
