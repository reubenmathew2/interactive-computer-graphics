#include <Windows.h>
#include <GL/glut.h>
#include <cmath>
#include <time.h>

void gen(int rx, int ry, int xc, int yc, float r, float g, float b)
{
    glPointSize(3);
    glColor3f(r, g, b);
    glBegin(GL_POINTS);
    float y1, y2, x1, x2;
    if (rx > ry)
    {
        for (int i = xc - rx; i <= xc + rx; i++)
        {
            y1 = yc + (1.0 * ry / rx * sqrt(rx * rx - (xc - i) * (xc - i)));
            glVertex2f(i, y1);
            y2 = yc - (1.0 * ry / rx * sqrt(rx * rx - (xc - i) * (xc - i)));
            glVertex2f(i, y2);
        }
    }
    else
    {
        for (int i = yc - ry; i <= yc + ry; i++)
        {
            x1 = xc + (1.0 * rx / ry * sqrt(ry * ry - (yc - i) * (yc - i)));
            glVertex2f(x1, i);
            x2 = xc - (1.0 * rx / ry * sqrt(ry * ry - (yc - i) * (yc - i)));
            glVertex2f(x2, i);
        }
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
    
    gen(rx, ry, xc, yc, r, g, b); //general algo

    glFlush();
}

int main(int argc, char* argv[])
{

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow("General Ellipse Algo");

    glClearColor(1, 1, 1, 1);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 600.0, 0.0, 600.0);

    glutDisplayFunc(ellipse);
    glutMainLoop();

    return 0;
}
