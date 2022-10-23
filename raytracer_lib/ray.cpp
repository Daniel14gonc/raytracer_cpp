#include "ray.h"
#include "light.h"

const int MAX_RECURSION_DEPTH = 3;

RayTracer::RayTracer(int w, int h)
{
    width = w;
    height = h;
    backgroundColor = new Color(0, 0, 100);
    currentColor = new Color(0, 0, 0);
    light = new Light(new Vector3(20, 10, 20), 2, new Color(255, 255, 255));
    writer = new Writer();
    envmap = NULL;
    startBuffer(width, height);
}

void RayTracer::startBuffer(int w, int h)
{
	height = h;
	width = w;
	frameBuffer = new unsigned char** [height];
	for(int i = 0; i < height; i++)
	{
		frameBuffer[i] = new unsigned char* [width];
	};
	clear();
}

void RayTracer::clear()
{
	for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
        	frameBuffer[i][j] = new unsigned char[3];
            unsigned char* temp = backgroundColor->getColor();
        	frameBuffer[i][j][2] = temp[2];
        	frameBuffer[i][j][1] = temp[1];
        	frameBuffer[i][j][0] = temp[0];
        }
    }
}

int RayTracer::write(string path)
{
    writer->write(frameBuffer, width, height, path);
    return 0;
}

void RayTracer::point(int x, int y, Color* color)
{
    if (x >= 0 && x < width && y >= 0 && y < height)
    {
        if (color != NULL)
        {
            unsigned char* temp = color->getColor();
            frameBuffer[y][x][0] = temp[0];
            frameBuffer[y][x][1] = temp[1];
            frameBuffer[y][x][2] = temp[2];
        }
        else
        {
            unsigned char* temp = backgroundColor->getColor();
            frameBuffer[y][x][0] = temp[0];
            frameBuffer[y][x][0] = temp[1];
            frameBuffer[y][x][0] = temp[2];
        }
        
    }
}

void RayTracer::render()
{
    int fov = int(M_PI / 1.5);
    float ar = (float) width / height;
    float tana = tan(fov / 2.0f);

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            float i = ((2 * (x + 0.5) / width) - 1) * ar * tana;
            float j = ((2 * (y + 0.5) / height) - 1) * tana;
            Vector3 origin(0, 0, 0);
            Vector3 d(i, j, -1);
            Vector3 dN = d.normalized();
            Color* c = castRay(origin, dN);
            point(x, y, c);
        }
    }
    cout << "finish" << endl;
}

Color* RayTracer::castRay(Vector3 origin, Vector3 direction, int recursion)
{
    if (recursion >= MAX_RECURSION_DEPTH)
        return getBackgroundColor(direction);

    tuple<Material*, Intersect*> tup = sceneIntersect(origin, direction);
    Material* material = get<0>(tup);
    Intersect* intersect = get<1>(tup);

    if (material == NULL)
        return getBackgroundColor(direction);
    
    float albedoFirstValue = material->getAlbedo()[0];
    float albedoSecondValue = material->getAlbedo()[1];
    float albedoThirdValue = material->getAlbedo()[2];
    float albedoFourthValue = material->getAlbedo()[3];


    if (material->hasTexture())
    {
        if (material->getDiffuse().getR() == 255 && material->getDiffuse().getG() == 255 && material->getDiffuse().getB() == 255)
        {
            albedoFirstValue = 0;
        }
        else
        {
            albedoFourthValue = 0;
        }
    }

    Vector3 lightDir = (light->getPosition() - intersect->getPoint()).normalized();

    float shadowBias = 1.1;
    Vector3 shadowOrigin = intersect->getPoint() + (intersect->getNormal() * shadowBias);
    tuple<Material*, Intersect*> tupShadow = sceneIntersect(shadowOrigin, lightDir);
    Material* shadowMaterial = get<0>(tupShadow);
    Intersect* shadowIntersect = get<1>(tupShadow);

    float shadowIntensity = 1;

    if (shadowMaterial != NULL)
        shadowIntensity = 0.5;

    // diffuse
    float diffuseIntensity = lightDir.dot(intersect->getNormal());
    Color temp = material->getDiffuse();
    Color* diffuse = temp * (diffuseIntensity * albedoFirstValue * shadowIntensity);

    // specular
    Vector3 lightReflection = reflect(lightDir, intersect->getNormal());
    float reflectionIntensity = max(0, lightReflection.dot(direction));
    float specIntensity = pow(reflectionIntensity, material->getSpec());
    Color* specular = light->getColor() * (specIntensity * albedoSecondValue * light->getIntensity());

    // reflection
    Color* reflectColor;
    if (albedoThirdValue > 0)
    {
        Vector3 reflectDir = reflect(direction, intersect->getNormal());
        float reflectBias = (reflectDir.dot(intersect->getNormal()) < 0) ? -0.5 : 0.5;
        Vector3 reflectOrig = intersect->getPoint() + (intersect->getNormal() * reflectBias);
        reflectColor = castRay(reflectOrig, reflectDir, recursion + 1);
    }
    else
    {
        reflectColor = new Color(0, 0, 0);
    }

    Color* reflection = *reflectColor * albedoThirdValue;

    // refraction
    Color* refractColor;
    if (albedoFourthValue > 0)
    {
        Vector3 refractDir = refract(direction, intersect->getNormal(), material->getRefractiveIndex());
        float refractBias = (refractDir.dot(intersect->getNormal()) < 0) ? -0.5 : 0.5;
        Vector3 refractOrig = intersect->getPoint() + (intersect->getNormal() * refractBias);
        refractColor = castRay(refractOrig, refractDir, recursion + 1);
    }
    else
    {
        refractColor = new Color(0, 0, 0);
    }

    Color* refraction = *refractColor * albedoFourthValue;
   
    Color* diffSpec = *diffuse + *specular;
    Color* refractReflect = *refraction + *reflection;

    return *diffSpec + *refractReflect;
}

void RayTracer::setScene(vector<Shape*> spheres)
{
    scene = spheres;
}

tuple<Material*, Intersect*> RayTracer::sceneIntersect(Vector3 origin, Vector3 direction)
{
    float zBuffer = 99999.0f;
    Material* material = NULL;
    Intersect* intersect = NULL;
    for (Shape* s : scene)
    {
        Intersect* objectIntersect = s->rayIntersect(origin, direction);
        if (objectIntersect != NULL)
        {
            if (objectIntersect->getDistance() > 0 && objectIntersect->getDistance() < zBuffer)
            {
                zBuffer = objectIntersect->getDistance();
                material = s->getMaterial();
                intersect = objectIntersect;
            }
        }
    }

    if (material != NULL)
    {
        if (material->hasTexture())
        {
            material->changeDiffuse(*intersect);
        }
    }

    tuple<Material*, Intersect*> tup {material, intersect};
    return tup;
}

Vector3 RayTracer::reflect(Vector3 I, Vector3 N)
{
    return (I - (N * (2 * (N.dot(I))))).normalized();
}

Vector3 RayTracer::refract(Vector3 I, Vector3 N, float roi)
{
    float etai = 1;
    float etat = roi;
    float cosi = (I.dot(N)) * -1;
    
    if (cosi < 0)
    {
        cosi *= -1;
        etai *= -1;
        etat *= -1;
        N = N * - 1;
    }

    float eta = etai / etat;
    
    float k = 1 - pow(eta, 2) * (1 - pow(cosi, 2));

    if (k < 0)
        return Vector3(0, 0, 0);
    
    float cost = pow(k, 0.5);

    return ((I * eta) + (N * (eta * cosi - cost))).normalized();
}

float RayTracer::max(float a, float b)
{
    if (a > b)
        return a;
    return b;
}

void RayTracer::setEnvmap(string path)
{
    envmap = new Envmap(path);
}

Color* RayTracer::getBackgroundColor(Vector3 direction)
{
    if (envmap) return envmap->getColor(direction);
    
    return backgroundColor;
}