#include "ray.h"


int main()
{
    float al[3] = {0.9, 0.1};
    Material* rubber = new Material(new Color(80, 0, 0), al, 10);
    float al1[3] = {0.695, 0.305};
    Material* ivory = new Material(new Color(100, 100, 80), al1, 50);
    Material* brown = new Material(new Color(139, 66, 21), al1, 50);
    Material* mouth = new Material(new Color(249, 226, 212), al1, 50);
    float cotton[3] = {0.151, 0.9};
    Material* black = new Material(new Color(0, 0, 0), cotton, 300);

    RayTracer r(800, 600);
    vector<Sphere> scene;

    // Body
    Vector3* a = new Vector3(0, 1, -10);
    scene.push_back(Sphere(a, 2, brown));
    a = new Vector3(0, -2.1, -10);
    scene.push_back(Sphere(a, 1.3, brown));
    a = new Vector3(-1.6, -5.5, -16);
    scene.push_back(Sphere(a, 0.9, brown));
    a = new Vector3(1.6, -5.5, -16);
    scene.push_back(Sphere(a, 0.9, brown));
    a = new Vector3(-3.1, -0.7, -16);
    scene.push_back(Sphere(a, 1.2, brown));
    a = new Vector3(3.1, -0.7, -16);
    scene.push_back(Sphere(a, 1.2, brown));
    a = new Vector3(-3.1, 4, -16);
    scene.push_back(Sphere(a, 1.2, brown));
    a = new Vector3(3.1, 4, -16);
    scene.push_back(Sphere(a, 1.2, brown));
    
    // Boca
    a = new Vector3(0, -0.9, -5);
    scene.push_back(Sphere(a, 0.3, mouth));

    // nariz
    a = new Vector3(0, -0.6, -3);
    scene.push_back(Sphere(a, 0.05, black));

    // eyes
    a = new Vector3(-0.2, -1.05, -4);
    scene.push_back(Sphere(a, 0.05, black));
    a = new Vector3(0.2, -1.05, -4);
    scene.push_back(Sphere(a, 0.05, black));

    r.setScene(scene);
    r.render();
    r.write();
    return 0;
}


