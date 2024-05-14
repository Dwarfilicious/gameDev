/* Author: Bas Zoeteman
 * Date of Initial Creation: 13-05-2024
 * Class for handling mouse input. */

#ifndef MOUSEHANDLER_H
#define MOUSEHANDLER_H

#include <utility>

void globalMouseCallback(int button, int state, int x, int y);

class MouseHandler {
public:
    MouseHandler(std::pair<int, int> mapSize);
    void mouseCallback(int button, int state, int x, int y);
    void setMapSize(std::pair<int, int> mapSize);
private:
    const std::pair<int, int> getCoordinates(int x, int y);
    std::pair<int, int> mapSize;
};

#endif /* MOUSEHANDLER_H */
