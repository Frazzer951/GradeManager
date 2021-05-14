cmake_minimum_required(VERSION 3.0.0)
project(GradeManager VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

file(GLOB src_files
     "src/*.cpp"
)

add_executable(${PROJECT_NAME} ${src_files} )
