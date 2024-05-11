/* Author: Bas Zoeteman
 * Date of Initial Creation: 27-12-2023
 * The player class, which represents a player in the game. */

#include <string>

#include "mapResources/Color.hpp"

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
    Player(int playerID);
    void setName(const std::string& name);
    const int getID() const;
    const std::string& getName() const;
    const Color& getColor() const;

private:
    int playerID;
    std::string name;
    Color color;
};

bool operator==(const Player& lhs, const Player& rhs);
bool operator!=(const Player& lhs, const Player& rhs);

#endif /* PLAYER_H */
