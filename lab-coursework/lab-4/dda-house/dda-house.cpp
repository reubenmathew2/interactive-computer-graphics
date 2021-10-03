#include <Windows.h>
#include <GL/glut.h>
#include <cmath>
#include <time.h>

void dda(float x1, float y1, float x2, float y2)
{
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

void house()
{
    glClear(GL_COLOR_BUFFER_BIT);
    //body
    glColor3f(0, 0, 0);
    dda(100, 50, 100, 350);
    dda(100, 350, 500, 350);
    dda(500, 350, 500, 50);
    dda(500, 50, 100, 50);

    //coloring the body
    glColor3f(0.26, 0.75, 0.96);
    for (int i = 103; i <= 497; i++)
        dda(i, 53, i, 347);

    //roof
    glColor3f(0, 0, 0);
    dda(100, 350, 300, 600);
    dda(300, 600, 500, 350);
    dda(500, 350, 100, 350);

    //coloring the roof
    glColor3f(0.95, 0.35, 0.36);
    for (int i = 106; i <= 494; i++)
        dda(300, 595, i, 353);

    //door
    glColor3f(0, 0, 0);
    dda(255, 50, 255, 200);
    dda(255, 200, 345, 200);
    dda(345, 200, 345, 50);
    dda(345, 50, 255, 50);

    //coloring the door
    glColor3f(1, 1, 1);
    for (int i = 258; i <= 342; i++)
        dda(i, 53, i, 197);

    //left window
    glColor3f(0, 0, 0);
    dda(150, 150, 150, 200);
    dda(150, 200, 200, 200);
    dda(200, 200, 200, 150);
    dda(200, 150, 150, 150);

    //coloring the left window
    glColor3f(1, 1, 1);
    for (int i = 153; i <= 197; i++)
        dda(i, 153, i, 197);

    //right window
    glColor3f(0, 0, 0);
    dda(400, 150, 400, 200);
    dda(400, 200, 450, 200);
    dda(450, 200, 450, 150);
    dda(450, 150, 400, 150);

    //coloring the right window
    glColor3f(1, 1, 1);
    for (int i = 403; i <= 447; i++)
        dda(i, 153, i, 197);

    glFlush();
}

int main(int argc, char *argv[])
{

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Lab 4: DDA House");

    glClearColor(1, 1, 1, 1);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 600.0, 0.0, 600.0);

    glutDisplayFunc(house);
    glutMainLoop();

    return 0;
}