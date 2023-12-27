/* Author: Bas Zoeteman
 * Date of Initial Creation: 27-12-2023
 * The player class, which represents a player in the game. */

#include <string>

#include "../maps/mapResources/Color.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
    Player(const std::string& playerID);
    std::string getID() const;
    const Color& getColor() const;

private:
    std::string playerID;
    Color color;
};

bool operator==(const Player& lhs, const Player& rhs);
bool operator!=(const Player& lhs, const Player& rhs);

#endif /* PLAYER_H */
