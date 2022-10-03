#include "color.h"

Color::Color(float r, float g, float b)
{
    color = new unsigned char[3];
    this->r = r;
    this->g = g;
    this->b = b;
    color[0] = (unsigned char) (int) b;
    color[1] = (unsigned char) (int) g;
    color[2] = (unsigned char) (int) r;
}

unsigned char* Color::getColor()
{
    return color;
}

float Color::getR()
{
    return r;
}

float Color::getG()
{
    return g;
}

float Color::getB()
{
    return b;
}

// Sum of colors;
Color* Color::operator+(Color c)
{
    float r1 = r + c.getR();
    float g1 = g + c.getG();
    float b1 = b + c.getB();

    if (r1 > 255) r1 = 255;
    if (g1 > 255) g1 = 255;
    if (b1 > 255) b1 = 255;

    if (r1 < 0) r1 = 0;
    if (g1 < 0) g1 = 0;
    if (b1 < 0) b1 = 0;

    return new Color(r1, g1, b1);
}

// Substraction of arrays
Color* Color::operator+(float a)
{
    float r1 = r + a;
    float g1 = g + a;
    float b1 = b + a;

    if (r1 > 255) r1 = 255;
    if (g1 > 255) g1 = 255;
    if (b1 > 255) b1 = 255;

    if (r1 < 0) r1 = 0;
    if (g1 < 0) g1 = 0;
    if (b1 < 0) b1 = 0;
    return new Color(r1, g1, b1);
}

// Color multiplication.
Color* Color::operator*(Color c)
{
    float r1 = r * c.getR();
    float g1 = g * c.getG();
    float b1 = b * c.getB();

    if (r1 > 255) r1 = 255;
    if (g1 > 255) g1 = 255;
    if (b1 > 255) b1 = 255;

    if (r1 < 0) r1 = 0;
    if (g1 < 0) g1 = 0;
    if (b1 < 0) b1 = 0;
    return new Color(r1, g1, b1);
}

// Constant multiplication of array.
Color* Color::operator*(float a)
{
    float r1 = r * a;
    float g1 = g * a;
    float b1 = b * a;
    
    if (r1 > 255) r1 = 255;
    if (g1 > 255) g1 = 255;
    if (b1 > 255) b1 = 255;

    if (r1 < 0) r1 = 0;
    if (g1 < 0) g1 = 0;
    if (b1 < 0) b1 = 0;
    return new Color(r1, g1, b1);
}

string Color::to_string(){
    return "(r: " + std::to_string(r) + ", g: " + std::to_string(g) + ", b: " + std::to_string(b) + ")";
}