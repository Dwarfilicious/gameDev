#include <GL/glut.h>

#include "mapResources/Map.hpp"

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
    map.importMap("testMap.json");

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Game");

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(display);
    glutTimerFunc(1000/60, timer, 0);
    glutMainLoop();

    return 0;
}