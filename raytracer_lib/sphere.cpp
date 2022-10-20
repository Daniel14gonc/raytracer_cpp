#include "sphere.h"

Sphere::Sphere(Vector3* center, float radius, Material* material)
{
    this->center = center;
    this->radius = radius;
    this->material = material;
}

Intersect* Sphere::rayIntersect(Vector3 origin, Vector3 direction)
{
    Vector3 L = *center - origin;
    float tca = L.dot(direction);
    float l = L.length();
    float d2 = pow(l, 2) - pow(tca, 2);
    if (d2 > pow(radius, 2))
        return NULL;
    
    float thc = pow((pow(radius, 2) - d2), 0.5);
    float t0 = tca - thc;
    float t1 = tca + thc;

    if (t0 < 0)
        t0 = t1;
    if (t0 < 0)
        return NULL;

    Vector3 impact = origin + (direction * t0);
    Vector3 normal = (impact - *center).normalized();

    Vector3* v1 = new Vector3(impact.getX(), impact.getY(), impact.getZ());
    Vector3* v2 = new Vector3(normal.getX(), normal.getY(), normal.getZ());

    return new Intersect(t0, v1, v2);
}

Material* Sphere::getMaterial()
{
    return material;
}