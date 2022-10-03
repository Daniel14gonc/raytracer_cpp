#pragma once

#include <string>

using namespace std;

class Color
{
    private:
        unsigned char* color;
        float r;
        float g;
        float b;
    
    public:
        Color(float, float, float);

        float getR();
        float getG();
        float getB();

        unsigned char* getColor();

        // Sum of colors;
        Color* operator+(Color);

        // Substraction of arrays
        Color* operator+(float);

        // Color multiplication.
        Color* operator*(Color);

        // Constant multiplication of array.
        Color* operator*(float);

        string to_string();
};