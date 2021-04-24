cmake_minimum_required(VERSION 3.4)
project(hello)


MESSAGE(STATUS "platform: ${CMAKE_SYSTEM_NAME}")

if(APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -stdlib=libc++")
    message(STATUS "cmake cxx flags: ${CMAKE_CXX_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lpthread")
    message(STATUS "cmake link flags: ${CMAKE_EXE_LINKER_FLAGS}")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -pthread")
    message(STATUS "cmake cxx flags: ${CMAKE_CXX_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pthread")
    message(STATUS "cmake link flags: ${CMAKE_EXE_LINKER_FLAGS}")
endif()

add_subdirectory(src bin)