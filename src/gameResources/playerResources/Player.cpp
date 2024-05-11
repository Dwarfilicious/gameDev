/* Author: Bas Zoeteman
 * Date of Initial Creation: 27-12-2023
 * The player class, which represents a player in the game. */

#include "Player.hpp"

static const Color playerColors[] = {
    Color(1.0f, 0.0f, 0.0f), // Red
    Color(0.0f, 1.0f, 0.0f), // Green
    Color(0.0f, 0.0f, 1.0f), // Blue
    Color(1.0f, 1.0f, 0.0f), // Yellow
    Color(1.0f, 0.0f, 1.0f), // Magenta
    Color(0.0f, 1.0f, 1.0f), // Cyan
    Color(1.0f, 0.5f, 0.0f), // Orange
    Color(0.5f, 0.0f, 1.0f), // Purple
    Color(0.0f, 0.5f, 1.0f), // Light Blue
    Color(0.5f, 1.0f, 0.0f), // Lime
    Color(1.0f, 0.0f, 0.5f), // Pink
    Color(0.0f, 1.0f, 0.5f), // Teal
    Color(0.5f, 0.0f, 0.0f), // Maroon
    Color(0.0f, 0.5f, 0.0f), // Olive
    Color(0.5f, 0.5f, 0.5f)  // Gray
};

static int colorIndex = 0;

Player::Player(int playerID)
    : playerID(playerID), color(playerColors[colorIndex])
{
    colorIndex = (colorIndex + 1) % (sizeof(playerColors) / sizeof(Color));
}

void Player::setName(const std::string& name)
{
    this->name = name;
}

const int Player::getID() const
{
    return playerID;
}

const std::string& Player::getName() const
{
    return name;
}

const Color& Player::getColor() const
{
    return color;
}

bool operator==(const Player& lhs, const Player& rhs)
{
    return lhs.getID() == rhs.getID();
}

bool operator!=(const Player& lhs, const Player& rhs)
{
    return !(lhs == rhs);
}
