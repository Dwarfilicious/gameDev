/* Author: Bas Zoeteman
 * Date of Initial Creation: 26-12-2023
 * Class data for a square. */

#include <GL/glut.h>

#include "Square.hpp"

Square::Square(float x, float y, float size, float red, float green, float blue)
{
    this->x = x;
    this->y = y;
    this->size = size;
    this->red = red;
    this->green = green;
    this->blue = blue;
}

float Square::getX() const
{
    return x;
}

float Square::getY() const
{
    return y;
}

float Square::getSize() const
{
    return size;
}

float Square::getRed() const
{
    return red;
}

float Square::getGreen() const
{
    return green;
}

float Square::getBlue() const
{
    return blue;
}

void Square::setX(float x)
{
    this->x = x;
}

void Square::setY(float y)
{
    this->y = y;
}

void Square::setSize(float size)
{
    this->size = size;
}

void Square::setRed(float red)
{
    this->red = red;
}

void Square::setGreen(float green)
{
    this->green = green;
}

void Square::setBlue(float blue)
{
    this->blue = blue;
}

void Square::drawSquare() const
{
    glBegin(GL_QUADS);
    glColor3f(red, green, blue);
    glVertex2f(x - 0.5*size, y + 0.5*size);
    glVertex2f(x - 0.5*size, y - 0.5*size);
    glVertex2f(x + 0.5*size, y - 0.5*size);
    glVertex2f(x + 0.5*size, y + 0.5*size);
    glEnd();
}
