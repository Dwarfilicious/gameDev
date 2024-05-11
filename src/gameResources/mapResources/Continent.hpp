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
    Continent(int continentID, int bonusGold);
    void setName(const std::string& name);
    void addTerritory(const Territory& territory);
    int getID() const;
    std::string getName() const;
    int getBonusGold() const;
    const std::vector<Territory>& getTerritories() const;
    bool hasTerritory(const Territory& territory) const;
    bool isOwnedBy(const Player& player) const;
    void draw(int mapSizeX, int mapSizeY) const;

private:
    int continentID;
    std::string name;
    int bonusGold;
    std::vector<Territory> territories;
};

bool operator==(const Continent& lhs, const Continent& rhs);
bool operator!=(const Continent& lhs, const Continent& rhs);

#endif /* CONTINENT_H */
