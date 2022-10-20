#pragma once

#include "color.h"
#include "intersect.h"
#include "texture.h"
#include "vector"

class Material
{
    private:
        Color* diffuse;
        float* albedo;
        float spec;
        float refractiveIndex;
        vector<Texture> textures;
        
    public:
        Material(Color*, float*, float);
        Material(Color*, float*, float, float);
        Material(Color*, float*, float, float refractiveIndex, vector<Texture> textures);
        Material(Color*, float*, float, vector<Texture> textures);
        Color getDiffuse();
        float* getAlbedo();
        float getSpec();
        float getRefractiveIndex();
        void changeDiffuse(Intersect);
        void setDiffuse(Intersect);
        bool hasTexture();
};