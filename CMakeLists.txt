cmake_minimum_required(VERSION 3.10)
project(MarkdownToHTML CXX)

set(CMAKE_BUILD_TYPE Debug)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(MarkdownToHTML 
    src/main.cpp 
    src/MTH.cpp
)