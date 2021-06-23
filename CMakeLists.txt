cmake_minimum_required(VERSION 3.11)
project(GradeManager C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(MSVC)
  add_compile_options(-W4)
  string(REGEX REPLACE "/W3" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
else()
  add_compile_options(-Wall -Wextra -Werror -Wdouble-promotion -Wconversion -fno-common -Wno-sign-compare)
endif()

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(ClangFormat)
include(FetchContent)
#set(CMAKE_CXX_CLANG_TIDY clang-tidy)
enable_testing()

# Download Third party Libraries
FetchContent_Declare(
  fmenu
  GIT_REPOSITORY https://github.com/Frazzer951/FMenu.git
  GIT_TAG v1.0.1
)

FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent.git
  GIT_TAG v3.9.1
)

FetchContent_GetProperties(fmenu)
if(NOT fmenu_POPULATED)
  FetchContent_Populate(fmenu)
  add_subdirectory(${fmenu_SOURCE_DIR} ${fmenu_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
  FetchContent_Populate(json)
  add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

# Create Libraries for each class to create a dependency tree
add_library(assignment src/Assignment.cpp)
target_include_directories(assignment PUBLIC include)

add_library(course src/Course.cpp)
target_include_directories(course PUBLIC include)
target_link_libraries(course assignment)

add_library(save src/Save.cpp)
target_include_directories(save PUBLIC include)
target_link_libraries(save assignment course nlohmann_json::nlohmann_json)

add_subdirectory(tests)

add_executable(${PROJECT_NAME} src/main.cpp )
target_link_libraries(${PROJECT_NAME} FMenu assignment course save)

add_library(${PROJECT_NAME}_lib src/main.cpp )
target_include_directories(${PROJECT_NAME}_lib PUBLIC include)
target_link_libraries(${PROJECT_NAME}_lib FMenu assignment course save)

file(GLOB Sources
     "src/*.cpp"
)

file(GLOB Headers
     "include/*.hpp"
)

clangformat_setup(
  ${Sources}
  ${Headers}
)