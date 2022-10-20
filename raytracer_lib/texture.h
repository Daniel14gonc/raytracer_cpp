#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "color.h"

using namespace std;

class Texture
{
    private:
        string path;
        int width;
        int height;
        unsigned char*** pixels;
        void read();

    public:
        Texture(string);
        Color* getColor(float, float);
        unsigned char* getColorIntensity(float, float, float);
        unsigned char*** getPixels();
        int getWidth();
        int getHeight();
};