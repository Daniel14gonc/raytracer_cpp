#pragma once

#include "vector3.h"
#include "material.h"
#include "intersect.h"

class Shape
{
    /*private:
        float radius;
        Vector3* center;
        Material* material;*/
    public:
        virtual Intersect* rayIntersect(Vector3, Vector3) = 0;
        virtual Material* getMaterial() = 0;
};