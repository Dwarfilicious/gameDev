/* Author: Bas Zoeteman
 * Date of Initial Creation: 27-12-2023
 * The map class, which contains all the tiles that make up the map. */

#include <iostream>
#include <GL/glut.h>
#include <queue>

#include "Map.hpp"
#include "TileTypes.hpp"

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

bool outsideContinent(int x, int y, std::vector<int> data, int mapSizeX, int mapSizeY)
{
    return x < 0
        || x >= mapSizeX
        || y < 0
        || y >= mapSizeY
        || static_cast<TileType>(data[y * mapSizeY + x]) == TileType::OCEAN;
}

/* Helper function: using flood fill algorithm to add tiles to correct territories and territories
 * to the correct continent. */
void determineContinent(int x, int y, std::vector<int>& data,
                        int mapSizeX, int mapSizeY, std::vector<std::vector<bool>>& visited,
                        Continent& continent, Territory& territory, int& territoryID)
{
    std::queue<std::pair<int, int>> toVisit;
    toVisit.push({x, y});

    std::queue<std::pair<int, int>> newTerritories;
    std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (!toVisit.empty())
    {
        auto [x, y] = toVisit.front();
        toVisit.pop();

        territory.addTile({x, y, TileType::LAND});
        visited[y][x] = true;

        for (const std::pair<int, int>& direction : directions)
        {
            auto [dx, dy] = direction;

            if (static_cast<TileType>(data[(y + dy) * mapSizeX + x + dx]) == TileType::LAND
                && !visited[y + dy][x + dx])
            {
                toVisit.push({x + dx, y + dy});
            }
            else if (static_cast<TileType>(data[(y + dy) * mapSizeX + x + dx]) == TileType::BORDER)
            {
                newTerritories.push({x + 2*dx, y + 2*dy});
            }
        }
    }

    while (!newTerritories.empty())
    {
        std::pair<int, int> newTerritoryStart = newTerritories.front();
        newTerritories.pop();
        if (static_cast<TileType>(data[newTerritoryStart.second * mapSizeX + newTerritoryStart.first])
            == TileType::LAND
            && !visited[newTerritoryStart.second][newTerritoryStart.first])
        {
            Territory newTerritory(++territoryID);
            determineContinent(newTerritoryStart.first, newTerritoryStart.second, data, mapSizeX, mapSizeY,
                            visited, continent, newTerritory, territoryID);
            continent.addTerritory(newTerritory);
        }
    }
}

void Map::importMap(const std::string& fileName)
{
    int continentID = 1;
    int territoryID = 1;

    std::ifstream ifs(fileName);

    nlohmann::json jsonFile;
    ifs >> jsonFile;

    mapSizeX = jsonFile["layers"][0]["width"];
    mapSizeY = jsonFile["layers"][0]["height"];
    std::vector<int> data = jsonFile["layers"][0]["data"].get<std::vector<int>>();

    std::vector<std::vector<bool>> visited(mapSizeY, std::vector<bool>(mapSizeX, false));

    for (int y = 0; y < mapSizeY; y++)
    {
        for (int x = 0; x < mapSizeX; x++)
        {
            if (visited[y][x])
            {
                continue;
            }

            TileType tileType = static_cast<TileType>(data[y * mapSizeX + x]);
            Tile tile(x, y, tileType);
            Continent newContinent(continentID, 50);
            Territory newTerritory(territoryID);

            switch (tileType)
            {
            case TileType::LAND:
                addContinent(newContinent);
                determineContinent(x, y, data, mapSizeX, mapSizeY,
                                   visited, continents.back(), newTerritory, territoryID);
                continents.back().addTerritory(newTerritory);
                continentID++;
                break;
            case TileType::OCEAN:
                addOceanTile(tile);
                break;
            case TileType::BORDER:
                addBorderTile(tile);
                break;
            default:
                throw std::runtime_error("Error: unknown tile type.");
                break;
            }
        }
    }
}

const std::vector<Continent>& Map::getContinents() const
{
    return continents;
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
