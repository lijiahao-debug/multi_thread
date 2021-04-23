cmake_minimum_required(VERSION 3.4)
project(hello)

# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lpthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -pthread")
message(STATUS "cmake cxx flags: ${CMAKE_CXX_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pthread")
message(STATUS "cmake link flags: ${CMAKE_EXE_LINKER_FLAGS}")
add_subdirectory(src bin)