/* Author: Bas Zoeteman
 * Date of Initial Creation: 27-12-2023
 * The continent class, which contains all the territories
 * that make up a continent. These continents build a map. */

#include "Continent.h"

Continent::Continent(const std::string& name, int bonusGold)
    : name(name), bonusGold(bonusGold) {}

void Continent::addTerritory(const Territory& territory)
{
    territories.push_back(territory);
}

std::string Continent::getName() const
{
    return name;
}

int Continent::getBonusGold() const
{
    return bonusGold;
}

const std::vector<Territory>& Continent::getTerritories() const
{
    return territories;
}

bool Continent::isOwnedBy(const Player& player) const
{
    for (const Territory& territory : territories) {
        if (territory.getOwner() != player) {
            return false;
        }
    }
    return true;
}

void Continent::draw(int mapSizeX, int mapSizeY) const
{
    for (const Territory& territory : territories) {
        territory.draw(mapSizeX, mapSizeY);
    }
}
