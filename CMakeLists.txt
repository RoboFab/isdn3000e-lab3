cmake_minimum_required(VERSION 3.28)
project(isdn3000e_lab3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
        polyscope
        GIT_REPOSITORY https://github.com/nmwsharp/polyscope.git
        GIT_TAG master
)

FetchContent_Declare(
        eigen
        GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
        GIT_TAG 3.4.0
)

FetchContent_Declare(
        libigl
        GIT_REPOSITORY https://github.com/libigl/libigl.git
        GIT_TAG v2.5.0
)

FetchContent_MakeAvailable(polyscope)
FetchContent_MakeAvailable(eigen)
FetchContent_MakeAvailable(libigl)

add_executable(isdn3000e_lab3 main.cpp
        src/task1.h
        src/task1.cpp
        src/task2.cpp
        src/task2.h
        src/task3.cpp
        src/task3.h
        src/task4.cpp
        src/task4.h)
target_link_libraries(isdn3000e_lab3
        PRIVATE
        polyscope
        Eigen3::Eigen
        igl::core
)


file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/assets)
configure_file(
        ${CMAKE_SOURCE_DIR}/assets/bunny.obj
        ${CMAKE_BINARY_DIR}/assets/bunny.obj
        COPYONLY
)
