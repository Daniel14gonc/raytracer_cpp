#include "sphere.h"

Sphere::Sphere(Vector3* center, float radius, unsigned char* color)
{
    this->center = center;
    this->radius = radius;
    this->color = color;
}

bool Sphere::rayIntersect(Vector3 origin, Vector3 direction)
{
    Vector3 L = *center - direction;
    float tca = L.dot(direction);
    float l = L.length();
    float d2 = pow(l, 2) - pow(tca, 2);
    if (d2 > pow(radius, 2))
        return false;
    
    float thc = pow((pow(radius, 2) - d2), 2);
    float t0 = tca - thc;
    float t1 = tca + thc;

    if (t0 < 0)
        t0 = t1;
    if (t0 < 0)
        return false;

    return true;
}

unsigned char* Sphere::getColor()
{
    return color;
}