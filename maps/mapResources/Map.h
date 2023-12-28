/* Author: Bas Zoeteman
 * Date of Initial Creation: 27-12-2023
 * The map class, which contains all the tiles that make up the map. */

#include <vector>
#include <GL/glut.h>

#include "Tile.h"
#include "Territory.h"
#include "Continent.h"

#ifndef MAP_H
#define MAP_H

class Map {
public:
    Map(int mapSizeX, int mapSizeY);
    void addContinent(const Continent& continent);
    void addOceanTile(const Tile& tile);
    void addBorderTile(const Tile& tile);
    void draw() const;

private:
    int mapSizeX, mapSizeY;
    std::vector<Continent> continents;
    std::vector<Tile> oceanTiles;
    std::vector<Tile> borderTiles;
};

#endif /* MAP_H */
