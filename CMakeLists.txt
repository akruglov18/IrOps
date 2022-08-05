cmake_minimum_required(VERSION 3.12)

set(CUR_PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/Configure.cmake")

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/gtest")
include_directories("${CMAKE_SOURCE_DIR}/3rdparty/gtest/googletest/include")

include_directories("${CMAKE_SOURCE_DIR}/3rdparty/")

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/Compiler.cmake")

add_subdirectory(src/tensor)
add_subdirectory(tests)
add_subdirectory(checker)
