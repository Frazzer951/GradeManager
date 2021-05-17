cmake_minimum_required(VERSION 3.8)
project(GradeManager C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

enable_testing()

# Add all files from src/ folder
set( Headers
  src/Assignment.hpp
  src/Course.hpp
  src/Save.hpp
  src/menu.hpp
)
set( Sources
  src/Assignment.cpp
  src/Course.cpp
  src/Save.cpp
  src/main.cpp
  src/menu.cpp
)

add_executable(${PROJECT_NAME} ${Sources} ${Headers} )
add_library(${PROJECT_NAME}_lib STATIC ${Sources} ${Headers} )

add_subdirectory(tests)