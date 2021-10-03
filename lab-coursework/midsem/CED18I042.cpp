/*
* Question:
* Draw first four letters of your name in capital 
* using general line and general ellipse drawing algorithms.
*/

#include <Windows.h>
#include <GL/glut.h>
#include <cmath>
#include <time.h>

void genLine(float x1, float y1, float x2, float y2)
{
    glPointSize(10);
    glBegin(GL_POINTS);
    float err = 0.0;
    float dy = y2 - y1;
    float dx = x2 - x1;
    if (x1 == x2) //for vertical line
    {
        if (y1 < y2)
        {
            for (int i = y1; i <= y2; i++)
            {
                glVertex2f(x1, i);
            }
        }
        else
        {
            for (int i = y1; i >= y2; i--)
            {
                glVertex2f(x1, i);
            }
        }
    }
    float m = dy / dx;
    if (abs(m) < 1)
    {
        if (x1 < x2)
        {
            for (int i = x1; i <= x2; i++)
            {
                glVertex2f(i, (y1 + dy * (i - x1) / dx));
            }
        }
        else
        {
            for (int i = x1; i >= x2; i--)
            {
                glVertex2f(i, (y1 + dy * (i - x1) / dx));
            }
        }
    }
    else
    {
        if (y1 < y2)
        {
            for (int i = y1; i <= y2; i++)
            {
                glVertex2f((x1 + dx * (i - y1) / dy), i);
            }
        }
        else
        {
            for (int i = y1; i >= y2; i--)
            {
                glVertex2f((x1 + dx * (i - y1) / dy), i);
            }
        }
    }
    glEnd();
}

void genElp(int rx, int ry, int xc, int yc, float r, float g, float b)
{
    glPointSize(10);
    glColor3f(r, g, b);
    glBegin(GL_POINTS);
    float y1, y2, x1, x2;
    if (rx > ry)
    {
        for (int i = xc; i <= xc + rx; i++) //loop adjusted to draw half ellipse using general formula
        {
            y1 = yc + (1.0 * ry / rx * sqrt(rx * rx - (xc - i) * (xc - i)));
            glVertex2f(i, y1);
            y2 = yc - (1.0 * ry / rx * sqrt(rx * rx - (xc - i) * (xc - i)));
            glVertex2f(i, y2);
        }
    }
    else
    {
        for (int i = yc - ry; i <= yc; i++)
        {
            x1 = xc + (1.0 * rx / ry * sqrt(ry * ry - (yc - i) * (yc - i)));
            glVertex2f(x1, i);
            x2 = xc - (1.0 * rx / ry * sqrt(ry * ry - (yc - i) * (yc - i)));
            glVertex2f(x2, i);
        }
    }
    glEnd();
}

void name()
{
    glClear(GL_COLOR_BUFFER_BIT);

    float r = 0, g = 0, b = 0;

    glColor3f(r, g, b);

    //R
    genLine(100, 100, 100, 300);
    genLine(100, 200, 200, 100);
    genElp(80, 50, 100, 250, r, g, b);

    //E
    genLine(250, 100, 250, 300);
    genLine(250, 300, 340, 300);
    genLine(250, 200, 340, 200);
    genLine(250, 100, 340, 100);

    //U
    genElp(50, 200, 450, 300, r, g, b);

    //B
    genLine(550, 100, 550, 300);
    genElp(100, 50, 550, 150, r, g, b);
    genElp(80, 50, 550, 250, r, g, b);

    glFlush();
}

int main(int argc, char* argv[])
{

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 400);
    glutCreateWindow("CED18I042 - Midsem");

    glClearColor(1, 1, 1, 1);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 800.0, 0.0, 400.0);

    glutDisplayFunc(name);
    glutMainLoop();

    return 0;
}
