# vp - ReXGlue Recompiled Project
#
# SDK boilerplate lives in generated/rexglue.cmake.

cmake_minimum_required(VERSION 3.25)
project(vp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(generated/rexglue.cmake)

# Sources
set(VP_SOURCES
    src/main.cpp
)

if(WIN32)
    add_executable(vp WIN32 ${VP_SOURCES})
else()
    add_executable(vp ${VP_SOURCES})
endif()

rexglue_setup_target(vp)
