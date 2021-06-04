cmake_minimum_required(VERSION 3.11)
project(GradeManager C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(ClangFormat)
include(FetchContent)
#set(CMAKE_CXX_CLANG_TIDY clang-tidy)
enable_testing()

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