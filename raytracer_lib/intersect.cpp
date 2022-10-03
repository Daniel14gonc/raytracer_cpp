#include "intersect.h"

Intersect::Intersect(float distance, Vector3* point, Vector3* normal)
{
    this->distance = distance;
    this->point = point;
    this->normal = normal;
}

float Intersect::getDistance()
{
    return distance;
}

Vector3 Intersect::getPoint()
{
    return *point;
}

Vector3 Intersect::getNormal()
{
    return *normal;
}