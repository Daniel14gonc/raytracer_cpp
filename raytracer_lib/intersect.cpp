#include "intersect.h"

Intersect::Intersect(float distance, Vector3* point, Vector3* normal)
{
    this->distance = distance;
    this->point = point;
    this->normal = normal;
}

Intersect::Intersect(float distance, Vector3* point, Vector3* normal, float* normalCoords, int face)
{
    this->distance = distance;
    this->point = point;
    this->normal = normal;
    this->normalCoordinates = normalCoords;
    this->face = face;
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

float* Intersect::getNormalCoordinates()
{
    return normalCoordinates;
}

int Intersect::getFace()
{
    return face;
}