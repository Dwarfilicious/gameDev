/* Author: Bas Zoeteman
 * Date of Initial Creation: 27-12-2023
 * The tile class, which represents a single tile on the map.
 * These tiles are used to build a territory,
 * which in turn build a continent. */

#include <GL/glut.h>

#include "Color.hpp"
#include "TileTypes.hpp"

#ifndef TILE_H
#define TILE_H

class Tile
{
public:
    Tile(int x, int y, TileType type);
    int getX() const;
    int getY() const;
    TileType getType() const;
    void draw(const Color& color, int mapSizeX, int mapSizeY) const;

private:
    int x, y;
    TileType type;
};

#endif /* TILE_H */
