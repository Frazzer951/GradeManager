cmake_minimum_required(VERSION 3.0.0)

project(Example)

set(CMAKE_CXX_STANDARD 17)

include(ClangFormat)

set( Sources
    example.cpp
)

add_executable(${PROJECT_NAME} ${Sources})
target_link_libraries(${PROJECT_NAME} FMenu)

target_clangformat_setup(${PROJECT_NAME})