#include "ray.h"


int main()
{

    unsigned char white[3] = {(unsigned char) 255, (unsigned char) 255, (unsigned char) 255};
    unsigned char black[3] = {(unsigned char) 0, (unsigned char) 0, (unsigned char) 0};
    unsigned char orange[3] = {(unsigned char) 255, (unsigned char) 102, (unsigned char) 0};
    RayTracer r(800, 600);
    vector<Sphere> scene;

    // Nose
    Vector3* a = new Vector3(0, -3.5, -16);
    scene.push_back(Sphere(a, 0.2, orange));

    // buttons
    a = new Vector3(0, -1.5, -16);
    scene.push_back(Sphere(a, 0.1, black));
    a = new Vector3(0, -1, -16);
    scene.push_back(Sphere(a, 0.1, black));
    a = new Vector3(0, -0.5, -16);
    scene.push_back(Sphere(a, 0.1, black));
    a = new Vector3(0, 0, -16);
    scene.push_back(Sphere(a, 0.1, black));
    a = new Vector3(0, 0.5, -16);
    scene.push_back(Sphere(a, 0.1, black));

    // eyes
    a = new Vector3(-0.5, -4, -16);
    scene.push_back(Sphere(a, 0.2, black));
    a = new Vector3(0.5, -4, -16);
    scene.push_back(Sphere(a, 0.2, black));

     // mouth
    a = new Vector3(-0.4, -3.0, -16);
    scene.push_back(Sphere(a, 0.1, black));
    a = new Vector3(-0.1, -2.8, -16);
    scene.push_back(Sphere(a, 0.1, black));
    a = new Vector3(0.2, -2.8, -16);
    scene.push_back(Sphere(a, 0.1, black));
    a = new Vector3(0.5, -3.0, -16);
    scene.push_back(Sphere(a, 0.1, black));

    // Body
    a = new Vector3(0, 2, -16);
    scene.push_back(Sphere(a, 2.5, white));
    a = new Vector3(0, -1, -16);
    scene.push_back(Sphere(a, 2, white));
    a = new Vector3(0, -3.5, -16);
    scene.push_back(Sphere(a, 1.5, white));

    r.setScene(scene);
    r.render();
    r.write();
    return 0;
}


