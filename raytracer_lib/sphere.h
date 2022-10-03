#include "vector3.h"
#include "material.h"
#include "intersect.h"

class Sphere
{
    private:
        float radius;
        Vector3* center;
        Material* material;
    
    public:
        Sphere(Vector3*, float, Material*);
        Intersect* rayIntersect(Vector3, Vector3);
        Material* getMaterial();
};