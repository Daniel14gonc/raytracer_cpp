#pragma once
#include <string>
#include <vector>
#include "writer.h"
#include "math.h"
#include "vector3.h"
#include "sphere.h"

using namespace std;

class RayTracer
{
    private:
		int width;
		int height;
		unsigned char* backgroundColor;
		unsigned char* currentColor;
		unsigned char*** frameBuffer;
		Writer* writer;
		void point(int x, int y, unsigned char* color = NULL);
		vector<Sphere> scene;

    public:
		RayTracer(int, int);
		void startBuffer(int, int);
		void clear();
		int write(string path = "image.bmp");
		void render();
		unsigned char* castRay(Vector3 origin, Vector3 direction);
		void setScene(vector<Sphere>);
};