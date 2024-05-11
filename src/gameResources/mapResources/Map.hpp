/* Author: Bas Zoeteman
 * Date of Initial Creation: 27-12-2023
 * The map class, which contains all the tiles that make up the map. */

#include <fstream>
#include <vector>
#include "json.hpp"

#include "Tile.hpp"
#include "Territory.hpp"
#include "Continent.hpp"

#ifndef MAP_H
#define MAP_H

class Map {
public:
    Map();
    void addContinent(const Continent& continent);
    void addOceanTile(const Tile& tile);
    void addBorderTile(const Tile& tile);
    void importMap(const std::string& fileName);
    std::vector<Continent>& getContinents();
    void draw() const;

private:
    int mapSizeX, mapSizeY;
    std::vector<Continent> continents;
    std::vector<Tile> oceanTiles;
    std::vector<Tile> borderTiles;
};

#endif /* MAP_H */
