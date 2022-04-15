cmake_minimum_required(VERSION 3.21)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp)
add_executable(test test.cpp)
add_executable(test2 test2.cpp)
add_executable(blackandWhiterFilter BlackandWhiteFilter.cpp)
add_executable(filpFilter FlipFilter.cpp)
add_executable(DetectEdgesFilter DetectEdgesFilter.cpp)
add_executable(mirrorFilter MirrorFilter.cpp)
add_executable(allfilters AllFilters.cpp)