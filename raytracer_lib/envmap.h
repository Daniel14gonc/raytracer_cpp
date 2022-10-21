#pragma once

#include <string>
#include "color.h"
#include "texture.h"
#include "vector3.h"
#include <cmath>

using namespace std;

class Envmap
{
    private:
        Texture* texture;

    public:
        Envmap(string path);
        Color* getColor(Vector3);
};