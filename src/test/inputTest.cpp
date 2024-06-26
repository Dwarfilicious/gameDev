#include <GL/glut.h>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "mapResources/Map.hpp"
#include "inputResources/MouseHandler.hpp"

Map map;

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60, timer, 0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    map.draw();

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    std::string exePath(argv[0]);
    std::string exeDir = exePath.substr(0, exePath.find_last_of("\\/"));

    std::string mapPath = exeDir + "/testMap.json";
    map.importMap(mapPath);

    std::vector<Player> players;

    for (int i = 0; i < 4; i++)
    {
        Player player(i);
        players.push_back(player);
    }

    srand(static_cast<unsigned int>(time(0)));
    for (Continent& continent : map.getContinents())
    {
        for (Territory& territory : continent.getTerritories())
        {
            int randomIndex = rand() % players.size();
            territory.setOwner(players[randomIndex]);
        }
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Game");

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(display);
    glutTimerFunc(1000/60, timer, 0);
    MouseHandler mouseHandler(map.getMapSize());
    glutMainLoop();

    return 0;
}
