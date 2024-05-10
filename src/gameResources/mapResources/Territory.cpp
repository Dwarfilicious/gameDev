/* Author: Bas Zoeteman
 * Date of Initial Creation: 27-12-2023
 * The territory class, which contains all the tiles
 * that make up a territory. These territories are used
 * to build a continent. */

#include "Territory.hpp"

Territory::Territory(const std::string& name)
    : name(name), owner("Neutral"), color(0.5f, 0.5f, 0.5f) {}

void Territory::addTile(const Tile& tile)
{
    tiles.push_back(tile);
}

void Territory::setOwner(const Player& player)
{
    owner = player;
    color = player.getColor();
}

std::string Territory::getName() const
{
    return name;
}

const Player& Territory::getOwner() const
{
    return owner;
}

const Color& Territory::getColor() const
{
    return color;
}

const std::vector<Tile>& Territory::getTiles() const
{
    return tiles;
}

void Territory::draw(int mapSizeX, int mapSizeY) const
{
    for (const Tile& tile : tiles) {
        tile.draw(color, mapSizeX, mapSizeY);
    }
}
