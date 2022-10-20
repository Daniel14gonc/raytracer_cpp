#pragma once

#include "vector3.h"
#include "material.h"
#include "shape.h"
#include "intersect.h"

class Sphere : public Shape
{
    private:
        float radius;
        Vector3* center;
        Material* material;
    
    public:
        Sphere(Vector3*, float, Material*);
        Intersect* rayIntersect(Vector3, Vector3) override;
        Material* getMaterial() override;
};