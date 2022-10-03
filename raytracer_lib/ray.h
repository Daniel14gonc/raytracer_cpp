#pragma once
#include <string>
#include <vector>
#include "writer.h"
#include "math.h"
#include "vector3.h"
#include "sphere.h"
#include "color.h"
#include "intersect.h"
#include <tuple>
#include "light.h"

using namespace std;

class RayTracer
{
    private:
		int width;
		int height;
		Color* backgroundColor;
		Color* currentColor;
		/*unsigned char* backgroundColor;
		unsigned char* currentColor;*/
		unsigned char*** frameBuffer;
		Writer* writer;
		Light* light;
		void point(int x, int y, Color* color = NULL);
		vector<Sphere> scene;
		tuple<Material*, Intersect*> sceneIntersect(Vector3, Vector3);
		Vector3 reflect(Vector3 I, Vector3 N);
		float max(float, float);

    public:
		RayTracer(int, int);
		void startBuffer(int, int);
		void clear();
		int write(string path = "image.bmp");
		void render();
		Color* castRay(Vector3 origin, Vector3 direction);
		void setScene(vector<Sphere>);
};