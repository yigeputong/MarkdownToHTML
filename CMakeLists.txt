cmake_minimum_required(VERSION 3.0)
project(MarkdownToHTML)
# 添加头文件路径
include_directories(include)
# 添加源文件路径
aux_source_directory(src DIR_SRCS)
add_executable(MarkdownToHTML src/main.cpp)