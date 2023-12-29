/* Author: Bas Zoeteman
 * Date of Initial Creation: 27-12-2023
 * The map class, which contains all the tiles that make up the map. */

#include <iostream>
#include "Map.h"

Map::Map() {}

void Map::addContinent(const Continent& continent)
{
    continents.push_back(continent);
}

void Map::addOceanTile(const Tile& tile)
{
    oceanTiles.push_back(tile);
}

void Map::addBorderTile(const Tile& tile)
{
    borderTiles.push_back(tile);
}

void Map::importMap(const std::string& fileName)
{
    std::ifstream ifs(fileName);

    nlohmann::json jsonFile;
    ifs >> jsonFile;

    mapSizeX = jsonFile["layers"][0]["width"];
    mapSizeY = jsonFile["layers"][0]["height"];
}

void Map::draw() const
{
    for (const Continent& continent : continents)
    {
        continent.draw(mapSizeX, mapSizeY);
    }

    for (const Tile& tile : oceanTiles)
    {
        tile.draw(Color(0.0f, 0.0f, 0.5f), mapSizeX, mapSizeY);
    }

    for (const Tile& tile : borderTiles)
    {
        tile.draw(Color(0.0f, 0.0f, 0.0f), mapSizeX, mapSizeY);
    }
}

int main()
{
    Map map;
    map.importMap("../Tiled/testMap.json");
}
