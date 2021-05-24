cmake_minimum_required(VERSION 3.8)
project(GradeManager C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(ClangFormat)
enable_testing()

# Add all files from src/ folder
set( Headers
  src/Assignment.hpp
  src/Course.hpp
  src/Save.hpp
)
set( Sources
  src/Assignment.cpp
  src/Course.cpp
  src/Save.cpp
  src/main.cpp
)

include_directories(thirdparty)

file(GLOB thirdparty_files
     "thirdparty/*.cpp"
     "thirdparty/*.hpp"
)

add_executable(${PROJECT_NAME} ${Sources} ${Headers} ${thirdparty_files} )
add_library(${PROJECT_NAME}_lib STATIC ${Sources} ${Headers} ${thirdparty_files} )

add_subdirectory(tests)

clangformat_setup(
  ${Sources} 
  ${Headers}
)