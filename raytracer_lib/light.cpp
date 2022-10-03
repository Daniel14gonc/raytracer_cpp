#include "light.h"

Light::Light(Vector3* position, float intensity, Color* color)
{
    this->position = position;
    this->intensity = intensity;
    this->color = color;
}

Vector3 Light::getPosition()
{
    return *position;
}

float Light::getIntensity()
{
    return intensity;
}

Color Light::getColor()
{
    return *color;
}