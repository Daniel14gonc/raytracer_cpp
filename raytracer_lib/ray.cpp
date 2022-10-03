#include "ray.h"
#include "light.h"

RayTracer::RayTracer(int w, int h)
{
    width = w;
    height = h;
    backgroundColor = new Color(0, 0, 0);
    currentColor = new Color(0, 0, 0);
    light = new Light(new Vector3(0, 0, 0), 2, new Color(255, 255, 255));
    writer = new Writer();
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
    int fov = int(M_PI / 2);
    float ar = (float) width / height;
    float tana = tan(fov / 2.0f);

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            float i = ((2 * (x + 0.5) / width) - 1) * ar * tana;
            float j = (1 - (2 * (y + 0.5) / height)) * tana;
            Vector3 origin(0, 0, 0);
            Vector3 d(i, j, -1);
            Vector3 dN = d.normalized();
            Color* c = castRay(origin, dN);
            point(x, y, c);
        }
    }
    cout << "finish" << endl;
}

Color* RayTracer::castRay(Vector3 origin, Vector3 direction)
{
    tuple<Material*, Intersect*> tup = sceneIntersect(origin, direction);
    Material* material = get<0>(tup);
    Intersect* intersect = get<1>(tup);

    if (material == NULL)
        return backgroundColor;

    Vector3 ligthDir = (light->getPosition() - intersect->getPoint()).normalized();
    float diffuseIntensity = ligthDir.dot(intersect->getNormal());
    Color temp = material->getDiffuse();
    Color* diffuse = temp * (diffuseIntensity * material->getAlbedo()[0]);

    Vector3 lightReflection = reflect(ligthDir, intersect->getNormal());
    float reflectionIntensity = max(0, lightReflection.dot(direction));
    float specIntensity = pow(reflectionIntensity, material->getSpec());
    Color* specular = light->getColor() * (specIntensity * material->getAlbedo()[1] * light->getIntensity());
   
    return *diffuse + *specular;
}

void RayTracer::setScene(vector<Sphere> spheres)
{
    scene = spheres;
}

tuple<Material*, Intersect*> RayTracer::sceneIntersect(Vector3 origin, Vector3 direction)
{
    float zBuffer = 99999.0f;
    Material* material = NULL;
    Intersect* intersect = NULL;
    for (Sphere s : scene)
    {
        Intersect* objectIntersect = s.rayIntersect(origin, direction);
        if (objectIntersect != NULL)
        {
            if (objectIntersect->getDistance() < zBuffer)
            {
                zBuffer = objectIntersect->getDistance();
                material = s.getMaterial();
                intersect = objectIntersect;
            }
        }
    }
    tuple<Material*, Intersect*> tup {material, intersect};
    return tup;
}

Vector3 RayTracer::reflect(Vector3 I, Vector3 N)
{
    return (I - (N * (2 * (N.dot(I))))).normalized();
}

float RayTracer::max(float a, float b)
{
    if (a > b)
        return a;
    return b;
}