#include "cube.h"

Cube::Cube(Vector3* center, float width, Material* material)
{
    this->center = center;
    this->material = material;
    this->width = width;
    this->face = -1;
    setBoundingBox();
}

Intersect* Cube::rayIntersect(Vector3 origin, Vector3 direction)
{
    float tmin = (min->getX() - origin.getX()) / direction.getX();
    float tmax = (max->getX() - origin.getX()) / direction.getX();

    if (tmin > tmax)
    {
        float temp = tmin;
        tmin = tmax;
        tmax = temp;
    }

    float tymin = (min->getY() - origin.getY()) / direction.getY();
    float tymax = (max->getY() - origin.getY()) / direction.getY();

    if (tymin > tymax)
    {
        float temp = tymin;
        tymin = tymax;
        tymax = temp;
    }

    if (tmin > tymax || tymin > tmax)
    {
        return NULL;
    }

    if (tymin > tmin)
    {
        tmin = tymin;
    }

    if (tymax < tmax)
    {
        tmax = tymax;
    }

    float tzmin = (min->getZ() - origin.getZ()) / direction.getZ();
    float tzmax = (max->getZ() - origin.getZ()) / direction.getZ();

    if (tzmin > tzmax)
    {
        float temp = tzmin;
        tzmin = tzmax;
        tzmax = temp;
    }

    if (tmin > tzmax || tzmin > tmax)
    {
        return NULL;
    }

    if (tzmin > tmin)
    {
        tmin = tzmin;
    }

    if (tzmax < tmax)
    {
        tmax = tzmax;
    }

    if (tmin > tmax)
    {
        return NULL;
    }

    Vector3 impact = origin + (direction * tmin);
    Vector3* normal = getNormal(impact);

    float* normalPoint = normalPosition(impact);

    Vector3* impactPointer = new Vector3(impact.getX(), impact.getY(), impact.getZ());

    return new Intersect(tmin, impactPointer, normal, normalPoint, face);
}

Vector3* Cube::getNormal(Vector3 impact)
{
    cout << impact.getY() << endl;

    float x = impact.getX();
    float y = impact.getY();
    float z = impact.getZ();

    /*float x = ceil(impact.getX() * 100) / 100.0;
    float y = ceil(impact.getY() * 100) / 100.0;
    float z = ceil(impact.getZ() * 100) / 100.0;*/
    cout << x << endl;
    cout << y << endl;
    cout << z << endl << endl;

    if(x >= min->getX() && y >= min->getY() && z == min->getZ())
    {
        face = 0;
        return new Vector3(0, 0, -1);
    }
    else if(x >= min->getX() && y >= min->getY() && z == max->getZ())
    {
        face = 1;
        return new Vector3(0, 0, 1);
    }
    else if(x >= min->getX() && y == min->getY() && z >= min->getZ())
    {
        face = 2;
        return new Vector3(0, -1, 0);
    }
    else if(x >= min->getX() && y == max->getY() && z >= min->getZ())
    {
        face = 3;
        return new Vector3(0, 1, 0);
    }
    else if(x == min->getX() && y >= min->getY() && z >= min->getZ())
    {
        face = 4;
        return new Vector3(-1, 0, 0);
    }
    else
    {
        face = 5;
        return new Vector3(1, 0, 0);
    }
}

Material* Cube::getMaterial()
{
    return material;
}

void Cube::setBoundingBox()
{
    float minx = center->getX() - (width / 2);
    float miny = center->getY() - (width / 2);
    float minz = center->getZ() - (width / 2);
    
    float maxx = center->getX() + (width / 2);
    float maxy = center->getY() + (width / 2);
    float maxz = center->getZ() + (width / 2);
    min = new Vector3(minx, miny, minz);
    max = new Vector3(maxx, maxy, maxz);
}

float* Cube::normalPosition(Vector3 point)
{
    return getPosition(point);
}

float* Cube::getPosition(Vector3 point)
{
    float* initialCoordinates = getBox();
    float initialHorizontal = initialCoordinates[0];
    float initialVertical = initialCoordinates[1];
    delete[] initialCoordinates;
    return getNormalPoints(point, initialHorizontal, initialVertical);
}

float* Cube::getNormalPoints(Vector3 point, float initialHorizontal, float initialVertical)
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
float* Cube::getPoints(Vector3 point)
{
    float* points = new float[2];
    if (face == 0 || face == 1)
    {
        points[0] = point.getX();
        points[1] = point.getY();
    }
    else if(face == 2 || face == 3)
    {
        points[0] = point.getX();
        points[1] = point.getZ();
    }
    else
    {
        points[0] = point.getZ();
        points[1] = point.getY();
    }

    return points;
}

float* Cube::getBox()
{
    float* box = new float[2];
    if (face == 0)
    {
        box[0] = center->getX() + (width / 2);
        box[1] = center->getY() - (width / 2);
    }
    else if (face == 1)
    {
        box[0] = center->getX() - (width / 2);
        box[1] = center->getY() - (width / 2);
    }
    else if (face == 2)
    {
        box[0] = center->getX() - (width / 2);
        box[1] = center->getZ() - (width / 2);
    }
    else if (face == 3)
    {
        box[0] = center->getX() - (width / 2);
        box[1] = center->getZ() + (width / 2);
    }
    else if (face == 4)
    {
        box[0] = center->getZ() - (width / 2);
        box[1] = center->getY() - (width / 2);
    }
    else if (face == 5)
    {
        box[0] = center->getZ() + (width / 2);
        box[1] = center->getY() - (width / 2);
    }
    
    return box;
}

