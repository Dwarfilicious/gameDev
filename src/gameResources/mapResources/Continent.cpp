/* Author: Bas Zoeteman
 * Date of Initial Creation: 27-12-2023
 * The continent class, which contains all the territories
 * that make up a continent. These continents build a map. */

#include "Continent.hpp"

Continent::Continent(int continentID, int bonusGold)
    : continentID(continentID), bonusGold(bonusGold) {}

void Continent::setName(const std::string& name)
{
    this->name = name;
}

void Continent::addTerritory(const Territory& territory)
{
    territories.push_back(territory);
}

int Continent::getID() const
{
    return continentID;
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

bool Continent::hasTerritory(const Territory& territory) const
{
    for (const Territory& t : territories) {
        if (t == territory) {
            return true;
        }
    }
    return false;
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

bool operator==(const Continent& lhs, const Continent& rhs)
{
    return lhs.getID() == rhs.getID();
}

bool operator!=(const Continent& lhs, const Continent& rhs)
{
    return !(lhs == rhs);
}
