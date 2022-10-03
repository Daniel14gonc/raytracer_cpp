#include "material.h"

Material::Material(Color* diffuse, float* albedo, float spec)
{
    this->diffuse = diffuse;
    this->albedo = albedo;
    this->spec = spec;
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