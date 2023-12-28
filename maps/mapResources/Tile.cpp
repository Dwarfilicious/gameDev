/* Author: Bas Zoeteman
 * Date of Initial Creation: 27-12-2023
 * The tile class, which represents a single tile on the map.
 * These tiles are used to build a territory,
 * which in turn build a continent. */

#include "Tile.h"

Tile::Tile(int x, int y, int type)
    : x(x), y(y), type(type) {}

int Tile::getX() const
{
    return x;
}

int Tile::getY() const
{
    return y;
}

int Tile::getType() const
{
    return type;
}

float normalizeCoordinate(int coordinate, int mapSize, float tileSize)
{
    return (2.0f * (coordinate - tileSize / 2) / mapSize) - 1.0f;
}

void Tile::draw(const Color& color, int mapSizeX, int mapSizeY) const
{
    float sizeX = 2.0f / (float) mapSizeX;
    float sizeY = 2.0f / (float) mapSizeY;
    float normalizedX = normalizeCoordinate(x, mapSizeX, sizeX);
    float normalizedY = normalizeCoordinate(y, mapSizeY, sizeY);

    glBegin(GL_POLYGON);
    glColor3f(color.getR(), color.getG(), color.getB());
    glVertex2f(normalizedX - 0.5*sizeX, normalizedY - 0.5*sizeY);
    glVertex2f(normalizedX + 0.5*sizeX, normalizedY - 0.5*sizeY);
    glVertex2f(normalizedX + 0.5*sizeX, normalizedY + 0.5*sizeY);
    glVertex2f(normalizedX - 0.5*sizeX, normalizedY + 0.5*sizeY);
    glEnd();
}
