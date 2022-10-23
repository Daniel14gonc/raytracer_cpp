#include "plane.h"

Plane::Plane(Vector3* center, float width,float height, Material* material, float orientation)
{
    this->center = center;
    this->material = material;
    this->width = width;
    this->height = height;
    this->orientation = orientation;
}

Intersect* Plane::rayIntersect(Vector3 origin, Vector3 direction)
{
    float d;
    if (orientation == 0)
    {
        d = (center->getZ() - origin.getZ()) / direction.getZ();
    }
    else
    {
        d = (center->getY() - origin.getY()) / direction.getY();
    }
    Vector3 impact = origin + (direction * d);
    Vector3* normal = getNormal(impact);

    if (d <= 0 || impact.getX() > center->getX() + (width / 2) || impact.getX() < center->getX() - (width / 2) || impact.getY() > center->getY() + (height / 2) || impact.getY() < center->getY() - (height / 2) || impact.getZ() > center->getZ() + (height / 2) || impact.getZ() < center->getZ() - (height / 2))
    {
        return NULL;
    }

    float* normalPoint = normalPosition(impact);

    Vector3* impactPointer = new Vector3(impact.getX(), impact.getY(), impact.getZ());

    return new Intersect(d, impactPointer, normal, normalPoint, 0);
}

Vector3* Plane::getNormal(Vector3 impact)
{
    if (orientation == 0)
    {
        return new Vector3(1, 0, 0);
    }

    return new Vector3(0, 1, 0);
}

Material* Plane::getMaterial()
{
    return material;
}

float* Plane::normalPosition(Vector3 point)
{
    return getPosition(point);
}

float* Plane::getPosition(Vector3 point)
{
    float* initialCoordinates = getBox();
    float initialHorizontal = initialCoordinates[0];
    float initialVertical = initialCoordinates[1];
    delete[] initialCoordinates;
    return getNormalPoints(point, initialHorizontal, initialVertical);
}

float* Plane::getNormalPoints(Vector3 point, float initialHorizontal, float initialVertical)
{
    float* points = getPoints(point);
    float x = points[0];
    float y = points[1];
    delete[] points;
    float xNormal = abs((x - initialHorizontal) / width);
    float yNormal = abs((y - initialVertical) / width);
    float* normalPoints = new float[2];
    normalPoints[0] = xNormal;
    normalPoints[1] = yNormal;

    return normalPoints;
}
float* Plane::getPoints(Vector3 point)
{
    float* points = new float[2];
    points[0] = point.getX();
    points[1] = point.getY();

    return points;
}

float* Plane::getBox()
{
    float* box = new float[2];
    box[0] = center->getX() - (width / 2);
    box[1] = center->getY() - (width / 2);
    
    return box;
}

