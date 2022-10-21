#pragma once

#include "vector3.h"
#include "material.h"
#include "texture.h"
#include "intersect.h"
#include "shape.h"


class Plane : public Shape
{
    private:
        Vector3* center;
        float width;
        float height;
        Material* material;
        vector<Texture> textures;
        float* normalPosition(Vector3);
        float* getPosition(Vector3);
        float* getNormalPoints(Vector3, float, float);
        float* getPoints(Vector3);
        float* getBox();
        Vector3* getNormal(Vector3);

    public:
        Plane(Vector3*, float, float, Material*);
        Intersect* rayIntersect(Vector3, Vector3) override;
        Material* getMaterial() override;
};