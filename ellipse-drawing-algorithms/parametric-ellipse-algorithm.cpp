#include <Windows.h>
#include <GL/glut.h>
#include <cmath>
#include <time.h>


void para(int rx, int ry, int xc, int yc, float r, float g, float b)
{
    glPointSize(3);
    glColor3f(r, g, b);
    glBegin(GL_POINTS);
    float x, y;
    for (int i = 0; i < 360; i++)
    {
        double radian = i * 3.141592653589 / 180;
        glVertex2f((xc + 1.0 * rx * cos(radian)), (yc + 1.0 * ry * sin(radian)));
    }
    glEnd();
}


void ellipse()
{
    glClear(GL_COLOR_BUFFER_BIT);
    srand(time(0));
    float r = (float)((rand() % 2));
    float g = (float)((rand() % 2));
    float b = (float)((rand() % 2));

    int xc = 200, yc = 200, rx = 20, ry = 30;
    xc = (int)(200 + (rand() % 201));
    yc = (int)(200 + (rand() % 201));
    rx = (int)((rand() % 151));
    ry = (int)((rand() % 151));

    para(rx, ry, xc, yc, r, g, b); //parametric algo

    glFlush();
}

int main(int argc, char* argv[])
{

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Parametric Ellipse Algo");

    glClearColor(1, 1, 1, 1);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 600.0, 0.0, 600.0);

    glutDisplayFunc(ellipse);
    glutMainLoop();

    return 0;
}
