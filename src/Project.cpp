#include "ray.h"
#include "plane.h"
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
    Material* mirror = new Material(new Color(255, 255, 255), albedoMirror, 1425);
    float albedoCube[4] = {0.9, 0.1, 0, 0};
    vector<Texture> textures;
    
    textures.push_back(Texture("m1.bmp"));
    textures.push_back(Texture("m1.bmp"));
    textures.push_back(Texture("m1.bmp"));
    textures.push_back(Texture("m2.bmp"));
    textures.push_back(Texture("m1.bmp"));
    textures.push_back(Texture("m1.bmp"));
    Material* cube = new Material(new Color(150, 180, 200), albedoCube, 125, textures);

    textures.clear();
    textures.push_back(Texture("bush.bmp"));
    float albedoFlower[4] = {1, 0.5, 0, 1};
    Material* bush = new Material(new Color(150, 180, 200), albedoFlower, 125, 1, textures);

    textures.clear();
    textures.push_back(Texture("gold.bmp"));
    textures.push_back(Texture("gold.bmp"));
    textures.push_back(Texture("gold.bmp"));
    textures.push_back(Texture("gold.bmp"));
    textures.push_back(Texture("gold.bmp"));
    textures.push_back(Texture("gold.bmp"));
    float albedoGold[4] = {1.1, 0.16, 0.1, 0};
    Material* goldCube = new Material(new Color(255, 255, 255), albedoGold, 50, textures);

    textures.clear();
    textures.push_back(Texture("brick.bmp"));
    textures.push_back(Texture("brick.bmp"));
    textures.push_back(Texture("brick.bmp"));
    textures.push_back(Texture("brick.bmp"));
    textures.push_back(Texture("brick.bmp"));
    textures.push_back(Texture("brick.bmp"));
    float albedoBrick[4] = {0.7, 0.6, 0, 0};
    Material* brick = new Material(new Color(255, 255, 255), albedoBrick, 4050, textures);

    textures.clear();
    textures.push_back(Texture("window.bmp"));
    textures.push_back(Texture("window.bmp"));
    textures.push_back(Texture("window.bmp"));
    textures.push_back(Texture("window.bmp"));
    textures.push_back(Texture("window.bmp"));
    textures.push_back(Texture("window.bmp"));
    Material* window = new Material(new Color(255, 255, 255) , albedoGlass, 125, 1, textures);

    textures.clear();
    textures.push_back(Texture("rock.bmp"));
    textures.push_back(Texture("rock.bmp"));
    textures.push_back(Texture("rock.bmp"));
    textures.push_back(Texture("rock.bmp"));
    textures.push_back(Texture("rock.bmp"));
    textures.push_back(Texture("rock.bmp"));
    float albedoRock[4] = {0.4, 0.6, 0, 0};
    Material* rock = new Material(new Color(255, 255, 255) , albedoRock, 125, textures);

    textures.clear();
    textures.push_back(Texture("door.bmp"));
    float albedoDoor[4] = {0.7, 0.4, 0, 0};
    Material* door = new Material(new Color(255, 255, 25), albedoDoor, 125, textures);

    textures.clear();
    textures.push_back(Texture("tree.bmp"));
    textures.push_back(Texture("tree.bmp"));
    textures.push_back(Texture("tree.bmp"));
    textures.push_back(Texture("tree.bmp"));
    textures.push_back(Texture("tree.bmp"));
    textures.push_back(Texture("tree.bmp"));
    Material* tree = new Material(new Color(255, 255, 255) , albedoDoor, 125, textures);

    textures.clear();
    textures.push_back(Texture("leaves.bmp"));
    textures.push_back(Texture("leaves.bmp"));
    textures.push_back(Texture("leaves.bmp"));
    textures.push_back(Texture("leaves.bmp"));
    textures.push_back(Texture("leaves.bmp"));
    textures.push_back(Texture("leaves.bmp"));
    float albedoLeaves[4] = {1, 0.5, 0, 0.8};
    Material* leaves = new Material(new Color(255, 255, 255) , albedoLeaves, 125, 1, textures);


    RayTracer r(1400, 800);
    vector<Shape*> scene;

    r.setEnvmap("menvmap.bmp");

    Vector3* center = new Vector3(-11, -1.5, -7);
    scene.push_back(new Cube(center, 1.5, goldCube));
    center = new Vector3(-12.5, -1.5, -7);
    scene.push_back(new Cube(center, 1.5, goldCube));
    center = new Vector3(-11.5, 0, -7);
    scene.push_back(new Cube(center, 1.5, goldCube));

    // Wall
    center = new Vector3(-2, -1.5, -12);
    scene.push_back(new Cube(center, 2, brick));
    center = new Vector3(0, -1.5, -12);
    scene.push_back(new Cube(center, 2, brick));
    center = new Vector3(2, -1.5, -12);
    scene.push_back(new Cube(center, 2, brick));
    center = new Vector3(4, -1.5, -12);
    scene.push_back(new Cube(center, 2, brick));
    center = new Vector3(6, -1.5, -12);
    scene.push_back(new Cube(center, 2, brick));
    center = new Vector3(8, -1.5, -12);
    scene.push_back(new Cube(center, 2, brick));
    center = new Vector3(10, -1.5, -12);
    scene.push_back(new Cube(center, 2, brick));
    
    center = new Vector3(-2, 0.5, -12);
    scene.push_back(new Cube(center, 2, brick));
    center = new Vector3(0, 0.5, -12);
    scene.push_back(new Cube(center, 2, brick));
    center = new Vector3(2, 0.5, -12);
    scene.push_back(new Cube(center, 2, brick));
    center = new Vector3(4, 0.5, -12);
    scene.push_back(new Cube(center, 2, brick));
    center = new Vector3(6, 0.5, -12);
    scene.push_back(new Cube(center, 2, brick));
    center = new Vector3(8, 0.5, -12);
    scene.push_back(new Cube(center, 2, brick));
    center = new Vector3(10, 0.5, -12);
    scene.push_back(new Cube(center, 2, brick));

    center = new Vector3(-2, 2.5, -12);
    scene.push_back(new Cube(center, 2, brick));
    center = new Vector3(0, 2.5, -12);
    scene.push_back(new Cube(center, 2, window));
    center = new Vector3(2, 2.5, -12);
    scene.push_back(new Cube(center, 2, window));
    center = new Vector3(4, 2.5, -12);
    scene.push_back(new Cube(center, 2, brick));
    center = new Vector3(6, 2.5, -12);
    scene.push_back(new Cube(center, 2, brick));
    center = new Vector3(8, 2.5, -12);
    scene.push_back(new Cube(center, 2, brick));
    center = new Vector3(10, 2.5, -12);
    scene.push_back(new Cube(center, 2, brick));

    center = new Vector3(-2, 4.5, -12);
    scene.push_back(new Cube(center, 2, brick));
    center = new Vector3(0, 4.5, -12);
    scene.push_back(new Cube(center, 2, window));
    center = new Vector3(2, 4.5, -12);
    scene.push_back(new Cube(center, 2, window));
    center = new Vector3(4, 4.5, -12);
    scene.push_back(new Cube(center, 2, brick));
    center = new Vector3(6, 4.5, -12);
    scene.push_back(new Cube(center, 2, window));
    center = new Vector3(8, 4.5, -12);
    scene.push_back(new Cube(center, 2, window));
    center = new Vector3(10, 4.5, -12);
    scene.push_back(new Cube(center, 2, brick));

    center = new Vector3(-2, 6.5, -12);
    scene.push_back(new Cube(center, 2, brick));
    center = new Vector3(0, 6.5, -12);
    scene.push_back(new Cube(center, 2, brick));
    center = new Vector3(2, 6.5, -12);
    scene.push_back(new Cube(center, 2, brick));
    center = new Vector3(4, 6.5, -12);
    scene.push_back(new Cube(center, 2, brick));
    center = new Vector3(6, 6.5, -12);
    scene.push_back(new Cube(center, 2, brick));
    center = new Vector3(8, 6.5, -12);
    scene.push_back(new Cube(center, 2, brick));
    center = new Vector3(10, 6.5, -12);
    scene.push_back(new Cube(center, 2, brick));

    // Roof
    center = new Vector3(-3.5, 6.75, -11.5);
    scene.push_back(new Cube(center, 1.5, rock));
    center = new Vector3(11.5, 6.75, -11.5);
    scene.push_back(new Cube(center, 1.5, rock));

    center = new Vector3(-2, 8, -11.5);
    scene.push_back(new Cube(center, 1.5, rock));
    center = new Vector3(10, 8, -11.5);
    scene.push_back(new Cube(center, 1.5, rock));

    // Bricks from roof
    center = new Vector3(-0.5, 8, -12);
    scene.push_back(new Cube(center, 1.7, brick));
    center = new Vector3(1, 8, -12);
    scene.push_back(new Cube(center, 1.7, brick));
    center = new Vector3(2.5, 8, -12);
    scene.push_back(new Cube(center, 1.7, brick));
    center = new Vector3(4, 8, -12);
    scene.push_back(new Cube(center, 1.7, brick));
    center = new Vector3(5.5, 8, -12);
    scene.push_back(new Cube(center, 1.7, brick));
    center = new Vector3(7, 8, -12);
    scene.push_back(new Cube(center, 1.7, brick));
    center = new Vector3(8.5, 8, -12);
    scene.push_back(new Cube(center, 1.7, brick));
    center = new Vector3(10, 8, -12);
    scene.push_back(new Cube(center, 1.7, brick));

    center = new Vector3(1, 9.5, -12);
    scene.push_back(new Cube(center, 1.7, brick));
    center = new Vector3(2.5, 9.5, -12);
    scene.push_back(new Cube(center, 1.7, brick));
    center = new Vector3(4, 9.5, -12);
    scene.push_back(new Cube(center, 1.7, brick));
    center = new Vector3(5.5, 9.5, -12);
    scene.push_back(new Cube(center, 1.7, brick));

    center = new Vector3(2.5, 10, -12);
    scene.push_back(new Cube(center, 1.7, brick));
    center = new Vector3(4, 10, -12);
    scene.push_back(new Cube(center, 1.7, brick));
    center = new Vector3(5.5, 10, -12);
    scene.push_back(new Cube(center, 1.7, brick));

    // More roof
    center = new Vector3(-0.5, 9.5, -11.5);
    scene.push_back(new Cube(center, 1.5, rock));
    center = new Vector3(8.5, 9.5, -11.5);
    scene.push_back(new Cube(center, 1.5, rock));

    center = new Vector3(1, 10.5, -11.5);
    scene.push_back(new Cube(center, 1.5, rock));
    center = new Vector3(7, 10.5, -11.5);
    scene.push_back(new Cube(center, 1.5, rock));

    center = new Vector3(2.5, 11.5, -11.5);
    scene.push_back(new Cube(center, 1.5, rock));
    center = new Vector3(4, 11.5, -11.5);
    scene.push_back(new Cube(center, 1.5, rock));
    center = new Vector3(5.5, 11.5, -11.5);
    scene.push_back(new Cube(center, 1.5, rock));

    // Door
    center = new Vector3(6.5, -0.25, -10);
    scene.push_back(new Plane(center, 4, 4, door));

    // Tree
    center = new Vector3(-10.5, -1.5, -14);
    scene.push_back(new Cube(center, 1.5, tree));
    center = new Vector3(-10.5, 0, -14);
    scene.push_back(new Cube(center, 1.5, tree));
    center = new Vector3(-10.5, 1.5, -14);
    scene.push_back(new Cube(center, 1.5, tree));
    center = new Vector3(-10.5, 3, -14);
    scene.push_back(new Cube(center, 1.5, tree));

    center = new Vector3(-7.5, 4.5, -14);
    scene.push_back(new Cube(center, 1.5, leaves));
    center = new Vector3(-7.5, 4.5, -13);
    scene.push_back(new Cube(center, 1.5, leaves));
    center = new Vector3(-7.5, 4.5, -12);
    scene.push_back(new Cube(center, 1.5, leaves));
    center = new Vector3(-9, 4.5, -14);
    scene.push_back(new Cube(center, 1.5, leaves));
    center = new Vector3(-9, 4.5, -13);
    scene.push_back(new Cube(center, 1.5, leaves));
    center = new Vector3(-9, 4.5, -12);
    scene.push_back(new Cube(center, 1.5, leaves));
    center = new Vector3(-10.5, 4.5, -14);
    scene.push_back(new Cube(center, 1.5, leaves));
    center = new Vector3(-10.5, 4.5, -13);
    scene.push_back(new Cube(center, 1.5, leaves));
    center = new Vector3(-10.5, 4.5, -12);
    scene.push_back(new Cube(center, 1.5, leaves));
    center = new Vector3(-12, 4.5, -14);
    scene.push_back(new Cube(center, 1.5, leaves));
    center = new Vector3(-12, 4.5, -13);
    scene.push_back(new Cube(center, 1.5, leaves));
    center = new Vector3(-12, 4.5, -12);
    scene.push_back(new Cube(center, 1.5, leaves));
    center = new Vector3(-13.5, 4.5, -14);
    scene.push_back(new Cube(center, 1.5, leaves));
    center = new Vector3(-13.5, 4.5, -13);
    scene.push_back(new Cube(center, 1.5, leaves));
    center = new Vector3(-13.5, 4.5, -12);
    scene.push_back(new Cube(center, 1.5, leaves));

    
    scene.push_back(new Cube(center, 1.5, leaves));
    center = new Vector3(-9, 6, -14);
    scene.push_back(new Cube(center, 1.5, leaves));
    center = new Vector3(-9, 6, -13);
    scene.push_back(new Cube(center, 1.5, leaves));
    center = new Vector3(-10.5, 6, -14);
    scene.push_back(new Cube(center, 1.5, leaves));
    center = new Vector3(-10.5, 6, -13);
    scene.push_back(new Cube(center, 1.5, leaves));
    center = new Vector3(-12, 6, -14);
    scene.push_back(new Cube(center, 1.5, leaves));
    center = new Vector3(-12, 6, -13);
    scene.push_back(new Cube(center, 1.5, leaves));
    center = new Vector3(-12, 6, -12);

    center = new Vector3(-10.5, 7.5, -13);
    scene.push_back(new Cube(center, 1.5, leaves));



    r.setScene(scene);
    r.render();
    r.write();
    return 0;
}


