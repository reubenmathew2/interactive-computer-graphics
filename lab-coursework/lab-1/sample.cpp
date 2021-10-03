#include <Windows.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void myinit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0); //set background colour (r, g, b, a)
    glMatrixMode(GL_PROJECTION); //set projection mode and other viewing parameters
    gluOrtho2D(0.0, 200.0, 0.0, 150.0); //set boundary for image in window (xmin, xmax, ymin, ymax)
}

void displayMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 1);
    glVertex2f(1.0, 1.0);
    glVertex2f(-1.0, 0.0);
    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); //initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //set single refresher buffer and colour mode RGB
    glutInitWindowPosition(100, 100); //set window postition
    glutInitWindowSize(400, 300); //set window size
    glutCreateWindow("Triangle"); //creating window with given title
    //myinit();
    glutDisplayFunc(displayMe); //function contained by display window
    glutMainLoop(); //to complete window processing
    return 0;
}