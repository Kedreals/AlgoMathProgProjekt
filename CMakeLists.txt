cmake_minimum_required(VERSION 2.8)

PROJECT(AlgoMathProgProj)

set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(SRC_DIR ${ROOT_DIR}/src)

set(INCLUDE_DIRS ${ROOT_DIR}/inc)

include_directories(${INCLUDE_DIRS})

set(GCC_COMPILER_FLAGS "-std=c++11")
add_definitions(${GCC_COMPILER_FLAGS})

set(SRC
  ${SRC_DIR}/main.cpp
  ${SRC_DIR}/insertion.cpp
  ${SRC_DIR}/quick.cpp
  ${SRC_DIR}/readFile.cpp
  ${SRC_DIR}/heap.cpp
  )

add_executable(MirkoEbert_JoshuaEnder_JanSprigade ${SRC})
