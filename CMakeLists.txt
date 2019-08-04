project(math-engine)

cmake_minimum_required(VERSION 3.0.2)
set(CMAKE_CXX_FLAGS "-Wall -std=c++14 -O3 -g -lpthread")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(GEN src/Quaternion.cpp test.cpp)

add_executable(main ${GEN})
