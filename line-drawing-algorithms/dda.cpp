#include <Windows.h>
#include <GL/glut.h>
#include <cmath>
#include <time.h>

void dda(float x1, float y1, float x2, float y2)
{
    glColor3f(0, 0, 0);
    glPointSize(3);
    glBegin(GL_POINTS);
    float slope = 0;
    if (x2 == x1)
    {
        if (y1 < y2)
        {
            for (int i = y1; i <= y2; i++)
            {
                glVertex2f(round(x1), i);
            }
        }
        else
        {
            for (int i = y1; i >= y2; i--)
            {
                glVertex2f(round(x1), i);
            }
        }
    }
    else
    {
        slope = (y2 - y1) / (x2 - x1);
        float absslope = (slope >= 0) ? (slope) : (-1.0 * slope);
        if (absslope <= 1.0)
        {
            if (x1 < x2)
            {
                for (int i = x1; i <= x2; i++)
                {
                    glVertex2f(i, round(y1));
                    y1 = y1 + slope;
                }
            }
            else
            {
                for (int i = x1; i >= x2; i--)
                {
                    glVertex2f(i, round(y1));
                    y1 = y1 - slope;
                }
            }
        }
        else
        {
            if (y1 < y2)
            {
                for (int i = y1; i <= y2; i++)
                {
                    glVertex2f(round(x1), i);
                    x1 = x1 + (1.0 / slope);
                }
            }
            else
            {
                for (int i = y1; i >= y2; i--)
                {
                    glVertex2f(round(x1), i);
                    x1 = x1 - (1.0 / slope);
                }
            }
        }
    }
    glEnd();
}

void ddaLine()
{
    glClear(GL_COLOR_BUFFER_BIT);
    int x1, y1, x2, y2;

    x1 = 300;
    x2 = 300;
    y1 = 500;
    y2 = 500;

    dda(x1, y1, x2, y2);

    glFlush();
}

int main(int argc, char *argv[])
{

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Lab 4: DDA Line");

    glClearColor(1, 1, 1, 1);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 600.0, 0.0, 600.0);

    glutDisplayFunc(ddaLine);
    glutMainLoop();

    return 0;
}