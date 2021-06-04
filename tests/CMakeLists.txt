cmake_minimum_required(VERSION 3.8.0)

project(Tests)

set(CMAKE_CXX_STANDARD 17)

include(ClangFormat)
include(CPM)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
CPMAddPackage("gh:google/googletest#release-1.10.0")

set( Sources
    AssignmentTests.cpp
    CourseTests.cpp
    SaveTests.cpp
)

add_executable(${PROJECT_NAME} ${Sources})
target_link_libraries(${PROJECT_NAME} gtest_main GradeManager_lib)

add_test(
    NAME ${PROJECT_NAME}
    COMMAND ${PROJECT_NAME}
)

target_clangformat_setup(${PROJECT_NAME})