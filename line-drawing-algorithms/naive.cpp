#include <Windows.h>
#include <GL/glut.h>
#include <cmath>
#include <time.h>

void naive(float x1, float y1, float x2, float y2)
{
    glColor3f(0, 0, 0);
    glPointSize(3);
    glBegin(GL_POINTS);
    float err = 0.0;
    float dy = y2 - y1;
    float dx = x2 - x1;
    if (x1 == x2)
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

void naiveLine()
{
    glClear(GL_COLOR_BUFFER_BIT);
    int x1, y1, x2, y2;

    x1 = 300;
    x2 = 300;
    y1 = 500;
    y2 = 500;

    naive(x1, y1, x2, y2);

    glFlush();
}

int main(int argc, char *argv[])
{

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Naive Line");

    glClearColor(1, 1, 1, 1);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 600.0, 0.0, 600.0);

    glutDisplayFunc(naiveLine);
    glutMainLoop();

    return 0;
}