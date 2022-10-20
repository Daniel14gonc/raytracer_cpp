#pragma once

#include "vector3.h"

class Intersect
{
    private:
        float distance;
        Vector3* point;
        Vector3* normal;
        float* normalCoordinates;
        int face;

    public:
        Intersect(float, Vector3*, Vector3*);
        Intersect(float, Vector3*, Vector3*, float*, int);
        float getDistance();
        Vector3 getPoint();
        Vector3 getNormal();
        float* getNormalCoordinates();
        int getFace();
};