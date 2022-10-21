#include "envmap.h"


Envmap::Envmap(string path)
{
    texture = new Texture(path);
}

Color* Envmap::getColor(Vector3 direction)
{
    Vector3 dir = direction.normalized();
    float x = ((atan2(dir.getZ(), dir.getX()) / (2 * M_PI)) + 0.5);
    float y = (acos(-dir.getY()) / M_PI);
    
    return texture->getColor(x, y);
}