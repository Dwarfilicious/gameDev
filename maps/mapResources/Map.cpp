/* Author: Bas Zoeteman
 * Date of Initial Creation: 27-12-2023
 * The map class, which contains all the tiles that make up the map. */

#include <iostream>
#include <GL/glut.h>
#include <queue>

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

bool outsideContinent(int x, int y, std::vector<int> data, int mapSizeX, int mapSizeY)
{
    return x < 0 || x >= mapSizeX || y < 0 || y >= mapSizeY || data[y * mapSizeY + x] == 2;
}

/* Helper function: using flood fill algorithm to add tiles to correct territories and territories
 * to the correct continent. */
void determineContinent(int x, int y, std::vector<int>& data,
                        int mapSizeX, int mapSizeY, std::vector<std::vector<bool>>& visited,
                        Continent& continent, Territory& territory)
{
    if (outsideContinent(x, y, data, mapSizeX, mapSizeY) || visited[y][x] == true)
    {
        return;
    }

    if (data[y * mapSizeX + x] == 3)
    {
        return;
    }

    if (data[y * mapSizeX + x] == 1)
    {
        territory.addTile(Tile(x, y, 1));
    }

    visited[y][x] = true;

    std::queue<std::pair<int, int>> newTerritories;
    std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (const std::pair<int, int>& direction : directions)
    {
        int dx = direction.first;
        int dy = direction.second;
        if (!outsideContinent(x + dx, y + dy, data, mapSizeX, mapSizeY) && data[y * mapSizeX + (x-1)] == 3)
        {
            newTerritories.push(std::make_pair(x + 2*dx, y + 2*dy));
        }
        else
        {
            determineContinent(x + dx, y + dy, data, mapSizeX, mapSizeY, visited, continent, territory);
        }
    }

    if (!territory.getTiles().empty())
    {
        continent.addTerritory(territory);
    }

    while (!newTerritories.empty())
    {
        std::pair<int, int> newTerritoryStart = newTerritories.front();
        newTerritories.pop();
        Territory newTerritory("territory");
        determineContinent(newTerritoryStart.first, newTerritoryStart.second, data, mapSizeX, mapSizeY,
                           visited, continent, newTerritory);
    }

    return;
}

void Map::importMap(const std::string& fileName)
{
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

            int tileType = data[y * mapSizeX + x];
            Tile tile(x, y, tileType);
            Continent newContinent("continent", 50);
            Territory newTerritory("territory");

            switch (tileType)
            {
            case 1:
                addContinent(newContinent);
                determineContinent(x, y, data, mapSizeX, mapSizeY,
                                   visited, continents.back(), newTerritory);
                break;
            case 2:
                addOceanTile(tile);
                break;
            case 3:
                addBorderTile(tile);
                break;
            default:
                std::cout << "Error: unknown tile type" << std::endl;
                break;
            }
        }
    }
    std::cout << continents[0].getTerritories().size() << std::endl;
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

Map map;

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60, timer, 0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    map.draw();

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    map.importMap("../Tiled/testMap.json");

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Game");

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(display);
    glutTimerFunc(1000/60, timer, 0);
    glutMainLoop();

    return 0;
}
