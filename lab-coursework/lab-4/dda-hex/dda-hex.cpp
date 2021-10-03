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

void hex()
{
    glClear(GL_COLOR_BUFFER_BIT);
    //regular hexagon with center at 300, 300 and raduis = 100
    dda(350, 213, 250, 213);
    dda(250, 213, 200, 300);
    dda(200, 300, 250, 387);
    dda(250, 387, 350, 387);
    dda(350, 387, 400, 300);
    dda(400, 300, 350, 213);

    glFlush();
}

int main(int argc, char *argv[])
{

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Lab 4: DDA Hexagon");

    glClearColor(1, 1, 1, 1);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 600.0, 0.0, 600.0);

    glutDisplayFunc(hex);
    glutMainLoop();

    return 0;
}