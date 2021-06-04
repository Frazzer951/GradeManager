cmake_minimum_required(VERSION 3.8)
project(FMenu C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(ClangFormat)
#set(CMAKE_CXX_CLANG_TIDY clang-tidy)

add_subdirectory(examples)

add_library(${PROJECT_NAME}
    src/FMenu.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_clangformat_setup(${PROJECT_NAME})