add_library(raytracer_lib SHARED
    vector3.h
    vector3.cpp
    ray.h
    ray.cpp
    sphere.h
    sphere.cpp
    writer.h
    writer.cpp
    color.h
    color.cpp
    intersect.h
    intersect.cpp
    light.h
    light.cpp
    material.h
    material.cpp
    shape.h
    cube.h
    cube.cpp
    texture.h
    texture.cpp
    envmap.h
    envmap.cpp
    plane.h
    plane.cpp
)

target_include_directories(raytracer_lib PUBLIC
	${CMAKE_CURRENT_LIST_DIR}
)