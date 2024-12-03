cmake_minimum_required(VERSION 3.29)
project(AdventOfCode2024)

set(CMAKE_CXX_STANDARD 20)

set (SOURCE_FILES
        day1.cpp
        day2.cpp
)

foreach(SOURCE_PATH ${SOURCE_FILES})
    get_filename_component(EXECUTABLE_NAME ${SOURCE_PATH} NAME_WE)
    add_executable(${EXECUTABLE_NAME} src/${SOURCE_PATH})
endforeach(SOURCE_PATH ${SOURCE_FILES})