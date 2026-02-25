cmake_minimum_required(VERSION 3.16)
project(isdn3000e_lab3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# TODO: Import the external libraries you are using

add_executable(isdn3000e_lab3 main.cpp
        tasks//task1.h
        tasks//task1.cpp
        tasks//task2.cpp
        tasks//task2.h
        tasks//task3.cpp
        tasks//task3.h
        tasks//task4.cpp
        tasks//task4.h)




file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/assets)
configure_file(
        ${CMAKE_SOURCE_DIR}/assets/bunny.obj
        ${CMAKE_BINARY_DIR}/assets/bunny.obj
        COPYONLY
)
