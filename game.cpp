/* Author: Bas Zoeteman
 * Date of Initial Creation: 26-12-2023
 * Main code from where the game is run.
 * The game is based on Legends of Callasia, of which
 * multiplayer support was closed down. The intent is to
 * build a similar kind of game, at least gameplay wise,
 * so that I can play it with friends. */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <random>
#include <chrono>
#include <thread>
#include <GL/glut.h>

#include "shapes/Square.h"

std::vector<Square> squares;

void timer(int value)
{
    for (Square& square : squares)
    {
        float newX = square.getX() + 0.01;
        if (newX > 1.0 + 0.5*square.getSize())
        {
            newX = -1.0 - 0.5*square.getSize();
        }
        square.setX(newX);
    }

    glutPostRedisplay();
    glutTimerFunc(1000/60, timer, 0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    for (const Square& square : squares)
    {
        square.drawSquare();
    }

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    // initialize the window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Game");

    // initialize the game assets
    for (int i = 0; i < 3; i++)
    {
        squares.push_back(Square(-1.0 + i * 0.4, 0, 0.2, 1.0, 0.0, 0.0));
    }

    glutDisplayFunc(display);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glutTimerFunc(1000/60, timer, 0);
    glutMainLoop();
    return 0;
}
