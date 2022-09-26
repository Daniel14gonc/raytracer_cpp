cmake_minimum_required(VERSION 3.22.1)

project(Raytracer)

add_executable(ray src/main.cpp)

add_subdirectory(raytracer_lib)

target_link_libraries(ray raytracer_lib)