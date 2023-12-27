/* Author: Bas Zoeteman
 * Date of Initial Creation: 27-12-2023
 * The color class, which represents a color in the RGB color space. */

#include <GL/glut.h>

#include "Color.h"

Color::Color(float r, float g, float b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}

float Color::getR() const
{
    return r;
}

float Color::getG() const
{
    return g;
}

float Color::getB() const
{
    return b;
}

void Color::setR(float r)
{
    this->r = r;
}

void Color::setG(float g)
{
    this->g = g;
}

void Color::setB(float b)
{
    this->b = b;
}
