#pragma once

#include "vector3.h"
#include "color.h"

class Light
{
    private:
        Vector3* position;
        float intensity;
        Color* color;
    public:
        Light(Vector3*, float, Color*);
        Vector3 getPosition();
        float getIntensity();
        Color getColor();
};