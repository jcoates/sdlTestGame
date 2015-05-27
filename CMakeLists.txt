cmake_minimum_required(VERSION 3.2)
project(testStructuredGame)

#Set directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#Source files
set(SOURCE_FILES main.cpp sdl_graphics.cpp)

#Copy resources

set(RESOURCES res/blankground.png)

# we don't want to copy if we're building in the source dir
if (NOT CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_CURRENT_BINARY_DIR)

    foreach(item IN LISTS RESOURCES)
        message(STATUS ${item})
        add_custom_command(
            OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${item}"
            COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/${item}" "${CMAKE_CURRENT_BINARY_DIR}/${item}"
            DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/${item}"
        )
        # files are only copied if a target depends on them
        add_custom_target(data-target ALL DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/")
    endforeach()
endif()


#include files
include_directories(lib)

#include sdl libraries
find_library(SDL2_LIB SDL2)
find_library(SDL2_IMG_LIB SDL2_image)

#executable
add_executable(testStructuredGame ${SOURCE_FILES} lib/sdl_graphics.h)

#link sdl libraries
target_link_libraries(testStructuredGame ${SDL2_LIB} ${SDL2_IMG_LIB})