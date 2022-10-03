#pragma once

#include "vector3.h"

class Intersect
{
    private:
        float distance;
        Vector3* point;
        Vector3* normal;

    public:
        Intersect(float, Vector3*, Vector3*);
        float getDistance();
        Vector3 getPoint();
        Vector3 getNormal();
};