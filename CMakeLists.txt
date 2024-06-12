cmake_minimum_required(VERSION 3.27)
project(OpenGL-Testing)

set(CMAKE_CXX_STANDARD 23)

add_executable(OpenGL-Testing main.cpp
        include/Window.h
        src/Window.cpp)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS} ${GLFW3_INCLUDE_DIRS} include ${GLEW_INCLIDE_DIRS})

target_link_libraries(OpenGL-Testing OpenGL glfw GLEW)
