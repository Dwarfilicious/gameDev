#include "MouseHandler.hpp"

#include <GL/freeglut.h>
#include <iostream>

MouseHandler* gMouseHandler = nullptr;

void globalMouseCallback(int button, int state, int x, int y)
{
    if (gMouseHandler)
    {
        gMouseHandler->mouseCallback(button, state, x, y);
    }
}

MouseHandler::MouseHandler(std::pair<int, int> mapSize)
{
    this->mapSize = mapSize;

    gMouseHandler = this;
    glutMouseFunc(globalMouseCallback);
}

void MouseHandler::setMapSize(std::pair<int, int> mapSize)
{
    this->mapSize = mapSize;
}

const std::pair<int, int> MouseHandler::getCoordinates(int x, int y)
{
    int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
    int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);

    float xRatio = static_cast<float>(mapSize.first) / windowWidth;
    float yRatio = static_cast<float>(mapSize.second) / windowHeight;

    return {(x - 1) * xRatio, (y - 1) * yRatio};
}

void MouseHandler::mouseCallback(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        std::pair<int, int> coordinates = getCoordinates(x, y);
        std::cout << "Mouse clicked at: " << coordinates.first << ", " << coordinates.second << std::endl;
    }
}
