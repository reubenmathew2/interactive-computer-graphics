#include <Windows.h>
#include <GL/glut.h>
#include <vector>
#include <iostream>

void xbld(float x1, float y1, float x2, float y2)
{
    glColor3f(0, 0, 0);
    glPointSize(3);
    glBegin(GL_POINTS);
    float dx, dy, yi;
    float P;
    float err = 0;
    dx = x2 - x1;
    dy = y2 - y1;
    yi = 1;
    if (dy < 0)
    {
        yi = -1;
        dy = -1 * dy;
    }
    P = (2 * dy) - dx;

    for (int i = x1; i <= x2; i++)
    {
        err = y1;
        //bld_arr.push_back(err);
        glVertex2f(i, y1);
        if (P > 0)
        {
            y1 += yi;
            P += 2 * (dy - dx);
        }
        else
            P += 2 * dy;
    }

    glEnd();
}

void ybld(float x1, float y1, float x2, float y2)
{
    glColor3f(0, 0, 0);
    glPointSize(3);
    glBegin(GL_POINTS);
    float dx, dy, xi;
    float P, err = 0;
    dx = x2 - x1;
    dy = y2 - y1;
    xi = 1;
    if (dx < 0)
    {
        xi = -1;
        dx = -1 * dx;
    }
    P = (2 * dx) - dy;

    for (int i = y1; i <= y2; i++)
    {
        err = x1;
        //bld_arr.push_back(err);
        glVertex2f(x1, i);
        if (P > 0)
        {
            x1 += xi;
            P += 2 * (dx - dy);
        }
        else
            P += 2 * dx;
    }

    glEnd();
}
void bld(float x1, float y1, float x2, float y2)
{
    /*glColor3f(0, 0, 0);
    glPointSize(3);
    glBegin(GL_POINTS);*/

    if (abs(y2 - y1) < abs(x2 - x1))
    {
        if (x1 > x2)
        {
            xbld(x2, y2, x1, y1);
            // naive(x2, y2, x1, y1);
            // dda(x2, y2, x1, y1);
        }
        else
        {
            xbld(x1, y1, x2, y2);
            // naive(x1, y1, x2, y2);
            // dda(x1, y1, x2, y2);
        }
    }
    else
    {
        if (y1 > y2)
        {
            ybld(x2, y2, x1, y1);
            // naive(x2, y2, x1, y1);
            // dda(x2, y2, x1, y1);
        }
        else
        {
            ybld(x1, y1, x2, y2);
            // naive(x1, y1, x2, y2);
            // dda(x1, y1, x2, y2);
        }
    }
}

void hex()
{
    glClear(GL_COLOR_BUFFER_BIT);
    //regular hexagon with center at 300, 300 and raduis = 100

    bld(350, 213, 250, 213);
    bld(250, 213, 200, 300);
    bld(200, 300, 250, 387);
    bld(250, 387, 350, 387);
    bld(350, 387, 400, 300);
    bld(400, 300, 350, 213);

    glFlush();
}


int main(int argc, char* argv[])
{

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Lab 5: BLD Hexagon");

    glClearColor(1, 1, 1, 1);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 600.0, 0.0, 600.0);

    glutDisplayFunc(hex);
    //err_calc();
    glutMainLoop();

    return 0;
}