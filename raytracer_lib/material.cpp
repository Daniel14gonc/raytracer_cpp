#include "material.h"

Material::Material(Color* diffuse, float* albedo, float spec)
{
    this->diffuse = diffuse;
    this->albedo = albedo;
    this->spec = spec;
    this->refractiveIndex = 0;
}

Material::Material(Color* diffuse, float* albedo, float spec, float refractiveIndex)
{
    this->diffuse = diffuse;
    this->albedo = albedo;
    this->spec = spec;
    this->refractiveIndex = refractiveIndex;
}

Material::Material(Color* diffuse, float* albedo, float spec, float refractiveIndex, vector<Texture> textures)
{
    this->diffuse = diffuse;
    this->albedo = albedo;
    this->spec = spec;
    this->refractiveIndex = refractiveIndex;
    this->textures = textures;
}

Material::Material(Color* diffuse, float* albedo, float spec, vector<Texture> textures)
{
    this->diffuse = diffuse;
    this->albedo = albedo;
    this->spec = spec;
    this->refractiveIndex = 0;
    this->textures = textures;
}

Color Material::getDiffuse()
{
    return *diffuse;
}

float* Material::getAlbedo()
{
    return albedo;
}

float Material::getSpec()
{
    return spec;
}

float Material::getRefractiveIndex()
{
    return refractiveIndex;
}

void Material::changeDiffuse(Intersect intersect)
{
    setDiffuse(intersect);
}

void Material::setDiffuse(Intersect intersect)
{
    int face = intersect.getFace();
    Texture texture = textures.at(face);
    float* points = intersect.getNormalCoordinates();
    float x = points[0];
    float y = points[1];
    diffuse = texture.getColor(x, y);
}

bool Material::hasTexture()
{
    return textures.size() > 0;
}