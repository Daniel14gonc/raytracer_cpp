#include "color.h"

class Material
{
    private:
        Color* diffuse;
        float* albedo;
        float spec;
        
    public:
        Material(Color*, float*, float);
        Color getDiffuse();
        float* getAlbedo();
        float getSpec();
};