cmake_minimum_required(VERSION 3.24.0)

project(WaveTest VERSION 1.0)

set(target WaveSimulation)

set(include_path "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(source_path "${CMAKE_CURRENT_SOURCE_DIR}/src")

file(GLOB_RECURSE source ${source_path}/*.c)

add_library(${target} ${source})

add_executable(${PROJECT_NAME} test.c)

target_link_libraries(${PROJECT_NAME} PUBLIC WaveSimulation)