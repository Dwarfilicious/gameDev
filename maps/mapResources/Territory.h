/* Author: Bas Zoeteman
 * Date of Initial Creation: 27-12-2023
 * The territory class, which contains all the tiles
 * that make up a territory. These territories are used
 * to build a continent. */

#include <string>
#include <vector>
#include <GL/glut.h>

#include "Tile.h"
#include "Color.h"
#include "../../playerResources/Player.h"

#ifndef TERRITORY_H
#define TERRITORY_H

class Territory {
public:
    Territory(const std::string& name);
    void addTile(const Tile& tile);
    void setOwner(const Player& player);
    std::string getName() const;
    const Player& getOwner() const;
    const Color& getColor() const;
    const std::vector<Tile>& getTiles() const;
    void draw(int mapSizeX, int mapSizeY) const;

private:
    std::string name;
    Player owner;
    Color color;
    std::vector<Tile> tiles;
};

#endif /* TERRITORY_H */
