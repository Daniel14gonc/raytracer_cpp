#include "ray.h"

RayTracer::RayTracer(int w, int h)
{
    width = w;
    height = h;
	backgroundColor = new unsigned char[3];
	backgroundColor[2] = (unsigned char) (255);
	backgroundColor[1] = (unsigned char) (255);
	backgroundColor[0] = (unsigned char) (255); 

	currentColor = new unsigned char[3];
	currentColor[2] = (unsigned char) (0);
	currentColor[1] = (unsigned char) (0);
	currentColor[0] = (unsigned char) (0);
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
        	frameBuffer[i][j][2] = backgroundColor[2];
        	frameBuffer[i][j][1] = backgroundColor[1];
        	frameBuffer[i][j][0] = backgroundColor[0];
        }
    }
}

int RayTracer::write(string path)
{
    writer->write(frameBuffer, width, height, path);
    return 0;
}

void RayTracer::point(int x, int y, unsigned char* color)
{
    if (x >= 0 && x < width && y >= 0 && y < height)
    {
        if (color != NULL)
        {
            frameBuffer[y][x][0] = color[2];
            frameBuffer[y][x][1] = color[1];
            frameBuffer[y][x][2] = color[0];
        }
        else
        {
            frameBuffer[y][x][0] = backgroundColor[2];
            frameBuffer[y][x][0] = backgroundColor[1];
            frameBuffer[y][x][0] = backgroundColor[0];
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
            unsigned char* c = castRay(origin, dN);
            point(x, y, c);
        }
    }
}

unsigned char* RayTracer::castRay(Vector3 origin, Vector3 direction)
{
    unsigned char* color = new unsigned char[3];
    for (Sphere s : scene)
    {
        if (s.rayIntersect(origin, direction))
        {
            return s.getColor();
        }
    }

    color[0] = (unsigned char) 0;
    color[1] = (unsigned char) 0;
    color[2] = (unsigned char) 0;

    return color;
}

void RayTracer::setScene(vector<Sphere> spheres)
{
    scene = spheres;
}