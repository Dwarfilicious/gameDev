/* Author: Bas Zoeteman
 * Date of Initial Creation: 27-12-2023
 * The continent class, which contains all the territories
 * that make up a continent. These continents build a map. */

#include <string>
#include <vector>

#include "Territory.hpp"
#include "playerResources/Player.hpp"

#ifndef CONTINENT_H
#define CONTINENT_H

class Continent {
public:
    Continent(const std::string& name, int bonusGold);
    void addTerritory(const Territory& territory);
    std::string getName() const;
    int getBonusGold() const;
    const std::vector<Territory>& getTerritories() const;
    bool isOwnedBy(const Player& player) const;
    void draw(int mapSizeX, int mapSizeY) const;

private:
    std::string name;
    int bonusGold;
    std::vector<Territory> territories;
};

#endif /* CONTINENT_H */
