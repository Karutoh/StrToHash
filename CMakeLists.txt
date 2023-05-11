cmake_minimum_required(VERSION 3.21)
project(StrToHash)

set(CMAKE_CXX_STANDARD 20)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    link_directories("${PROJECT_SOURCE_DIR}/../EHS/cmake-build-debug")
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    link_directories("${PROJECT_SOURCE_DIR}/../EHS/cmake-build-release")
endif()

add_executable(StrToHash main.cpp)

target_include_directories(StrToHash PUBLIC "${PROJECT_SOURCE_DIR}/..")

target_link_libraries(StrToHash PRIVATE EHS)