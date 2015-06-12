cmake_minimum_required(VERSION 3.2)
project(testStructuredGame)

#Set directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#Source files
set(SOURCE_FILES main.cpp sdl_graphics.cpp image_data.cpp image.cpp scene_display.cpp sdl_events.cpp hardware_events.cpp)

#include files
include_directories(lib)

#copy resources
file(COPY res DESTINATION ${CMAKE_BINARY_DIR})

#include sdl libraries
find_library(SDL2_LIB SDL2)
find_library(SDL2_IMG_LIB SDL2_image)

#executable
add_executable(testStructuredGame ${SOURCE_FILES})

#link sdl libraries
target_link_libraries(testStructuredGame ${SDL2_LIB} ${SDL2_IMG_LIB})