#pragma once

#include "vector3.h"
#include "material.h"
#include "shape.h"
#include "intersect.h"
#include "cmath"

using namespace std;

class Cube : public Shape
{
    private:
        float width;
        Vector3* center;
        Material* material;
        Vector3* min;
        Vector3* max;
        int face;

        void setBoundingBox();
        Vector3* getNormal(Vector3);
        float* normalPosition(Vector3);
        float* getPosition(Vector3);
        float* getNormalPoints(Vector3, float, float);
        float* getPoints(Vector3);
        float* getBox();

    
    public:
        Cube(Vector3*, float, Material*);
        Intersect* rayIntersect(Vector3, Vector3) override;
        Material* getMaterial() override;
};