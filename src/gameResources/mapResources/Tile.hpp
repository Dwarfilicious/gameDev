/* Author: Bas Zoeteman
 * Date of Initial Creation: 27-12-2023
 * The tile class, which represents a single tile on the map.
 * These tiles are used to build a territory,
 * which in turn build a continent. */

#include <GL/glut.h>

#include "Color.hpp"

#ifndef TILE_H
#define TILE_H

class Tile
{
public:
    Tile(int x, int y, int type);
    int getX() const;
    int getY() const;
    int getType() const;
    void draw(const Color& color, int mapSizeX, int mapSizeY) const;

private:
    int x, y;
    int type;
};

#endif /* TILE_H */
