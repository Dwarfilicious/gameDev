cmake_minimum_required(VERSION 3.22.1)

project(gameDev)

add_subdirectory(external)
add_subdirectory(src)

add_executable(${PROJECT_NAME} main.cpp)
