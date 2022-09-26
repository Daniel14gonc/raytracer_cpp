#include "vector3.h"

class Sphere
{
    private:
        float radius;
        Vector3* center;
        unsigned char* color;
    
    public:
        Sphere(Vector3*, float, unsigned char*);
        bool rayIntersect(Vector3, Vector3);
        unsigned char* getColor();
};