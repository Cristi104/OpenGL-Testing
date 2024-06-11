cmake_minimum_required(VERSION 3.27)
project(OpenGL-Testing)

set(CMAKE_CXX_STANDARD 23)

add_executable(OpenGL-Testing main.cpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(OpenGL-Testing ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
