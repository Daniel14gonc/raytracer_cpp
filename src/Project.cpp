#include "ray.h"
#include "cube.h"


int main()
{
    float albedoRubber[4] = {0.9, 0.1, 0, 0};
    Material* rubber = new Material(new Color(80, 0, 0), albedoRubber, 10);
    float albedoIvory[4] = {0.695, 0.305, 0.1, 0};
    Material* ivory = new Material(new Color(100, 100, 80), albedoIvory, 50);
    float albedoGlass[4] = {0, 0.5, 0.1, 0.8};
    Material* glass = new Material(new Color(150, 180, 200), albedoGlass, 125, 1.5);
    float albedoMirror[4] = {0, 1, 0.8, 0};
    Material* mirror = new Material(new Color(255, 255, 255), albedoGlass, 1425);
    float albedoCube[4] = {0.9, 0.1, 0, 0};
    vector<Texture> textures;
    
    textures.push_back(Texture("m1.bmp"));
    textures.push_back(Texture("m1.bmp"));
    textures.push_back(Texture("m1.bmp"));
    textures.push_back(Texture("m2.bmp"));
    textures.push_back(Texture("m1.bmp"));
    textures.push_back(Texture("m1.bmp"));
    Material* cube = new Material(new Color(150, 180, 200), albedoCube, 125, textures);


    RayTracer r(800, 600);
    vector<Shape*> scene;

    // Body
    Vector3* position = new Vector3(0, -1.5, -10);
    /*Sphere s(position, 1.5, ivory);
    scene.push_back(new Sphere(position, 1.5, ivory));
    position = new Vector3(0, 0, -5);
    scene.push_back(new Sphere(position, 0.5, glass));
    position = new Vector3(1, 1, -8);
    scene.push_back(new Sphere(position, 1.7, rubber));*/
    Vector3* center = new Vector3(0, -1.5, -10);
    scene.push_back(new Cube(position, 2, cube));

    r.setScene(scene);
    r.render();
    r.write();
    return 0;
}


