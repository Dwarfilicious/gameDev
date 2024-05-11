/* Author: Bas Zoeteman
 * Date of Initial Creation: 27-12-2023
 * The territory class, which contains all the tiles
 * that make up a territory. These territories are used
 * to build a continent. */

#include <string>
#include <vector>

#include "Tile.hpp"
#include "Color.hpp"
#include "playerResources/Player.hpp"

#ifndef TERRITORY_H
#define TERRITORY_H

class Territory {
public:
    Territory(const int territoryID);
    void setName(const std::string& name);
    void addTile(const Tile& tile);
    void setOwner(const Player& player);
    int getID() const;
    std::string getName() const;
    const Player& getOwner() const;
    const Color& getColor() const;
    const std::vector<Tile>& getTiles() const;
    void draw(int mapSizeX, int mapSizeY) const;

private:
    int territoryID;
    std::string name;
    Player owner;
    Color color;
    std::vector<Tile> tiles;
};

bool operator==(const Territory& lhs, const Territory& rhs);
bool operator!=(const Territory& lhs, const Territory& rhs);

#endif /* TERRITORY_H */
