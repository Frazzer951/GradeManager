cmake_minimum_required(VERSION 3.8)
project(GradeManager C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(ClangFormat)
include(CPM)
#set(CMAKE_CXX_CLANG_TIDY clang-tidy)
enable_testing()

CPMAddPackage("gh:Frazzer951/FMenu@1.0.1")
CPMAddPackage("gh:ArthurSonzogni/nlohmann_json_cmake_fetchcontent@3.9.1")

# Add all files from src/ folder
set( Sources
  src/Assignment.cpp
  src/Course.cpp
  src/Save.cpp
  src/main.cpp
)

add_subdirectory(tests)

include_directories(include)

add_executable(${PROJECT_NAME} ${Sources} )
target_link_libraries(${PROJECT_NAME} FMenu nlohmann_json::nlohmann_json)

add_library(${PROJECT_NAME}_lib ${Sources} )
target_include_directories(${PROJECT_NAME}_lib PUBLIC include)
target_link_libraries(${PROJECT_NAME}_lib FMenu nlohmann_json::nlohmann_json)

clangformat_setup(
  ${Sources}
  ${Headers}
)