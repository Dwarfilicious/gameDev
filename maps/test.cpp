#include <iostream>

#include "mapResources/Map.h"
#include "mapResources/Continent.h"
#include "mapResources/Territory.h"
#include "mapResources/Tile.h"
#include "../playerResources/Player.h"

int main() {
    // Create a player
    Player player("Player1");

    // Create a map
    Map map;

    // Create a continent and add it to the map
    Continent continent("Continent1", 10);
    map.addContinent(continent);

    // Create a territory and add it to the continent
    Territory territory("Territory1");
    territory.setOwner(player);
    continent.addTerritory(territory);

    // Check if the continent is owned by the player
    if (continent.isOwnedBy(player)) {
        std::cout << "The continent is owned by the player." << std::endl;
    } else {
        std::cout << "The continent is not owned by the player." << std::endl;
    }

    return 0;
}
