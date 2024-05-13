/* Author: Bas Zoeteman
 * Date of Initial Creation: 27-12-2023
 * The tile class, which represents a single tile on the map.
 * These tiles are used to build a territory,
 * which in turn build a continent. */

#include "Tile.hpp"

Tile::Tile(int x, int y, TileType type)
    : x(x), y(y), type(type) {}

int Tile::getX() const
{
    return x;
}

int Tile::getY() const
{
    return y;
}

TileType Tile::getType() const
{
    return type;
}

float normalizeCoordinate(int coordinate, int mapSize, float tileSize)
{
    return (2.0f * coordinate / mapSize) - 1.0f + 0.5f * tileSize;
}

void Tile::draw(const Color& color, int mapSizeX, int mapSizeY) const
{
    float sizeX = 2.0f / (float) mapSizeX;
    float sizeY = 2.0f / (float) mapSizeY;
    float normalizedX = normalizeCoordinate(x, mapSizeX, sizeX);
    float normalizedY = -normalizeCoordinate(y, mapSizeY, sizeY);

    glBegin(GL_POLYGON);
    glColor3f(color.getR(), color.getG(), color.getB());
    glVertex2f(normalizedX - 0.5*sizeX, normalizedY - 0.5*sizeY);
    glVertex2f(normalizedX + 0.5*sizeX, normalizedY - 0.5*sizeY);
    glVertex2f(normalizedX + 0.5*sizeX, normalizedY + 0.5*sizeY);
    glVertex2f(normalizedX - 0.5*sizeX, normalizedY + 0.5*sizeY);
    glEnd();
}
