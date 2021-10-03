#include <Windows.h>
#include <GL/glut.h>
#include <cmath>

#define pi 3.1415

float rtod(float radians)
{
    return radians * 180.0 / pi;
}

void mcd(int x_center, int y_center, int radius, int alpha, int beta)
{

    glPointSize(3);

    int x = 0, y = radius;
    int p = 1 - radius;

    int s1 = 0, e1 = 0, s2 = 0, e2 = 0;
    int start, end;

    if (beta == 360) //full circle
    {
        s1 = 0;
        e1 = 360;
    }
    else if (beta > 0)
    {

        start = (alpha + 360) % 360; //for negative alpha
        end = (alpha + beta + 360) % 360;

        if (end >= start)
        {
            s1 = start;
            e1 = end;
            s2 = start;
            e2 = end;
        }
        else
        {
            s1 = start;
            e1 = 360;
            s2 = 0;
            e2 = end;
        }
    }
    else if (beta < 0)
    {
        start = (alpha + beta + 720) % 360;
        end = (alpha + 360) % 360;

        if (start <= end)
        {
            s1 = start;
            e1 = end;
            s2 = start;
            e2 = end;
        }
        else
        {
            s1 = start;
            e1 = 360;
            s2 = 0;
            e2 = end;
        }
    }

    float a;

    glBegin(GL_POINTS);

    for (x = 0; x <= radius / 1.414; x++) //calculating for one octent and projecting in remaining octents
    {
        
        a = rtod(atan((float)(y) / (float)(x)));  // tan-1(y/x)
        if ((a >= s1 && a <= e1) || (a >= s2 && a <= e2))
            glVertex2i(x_center + x, y_center + y);

        a = rtod(atan((float)(x) / (float)(y)));
        if ((a >= s1 && a <= e1) || (a >= s2 && a <= e2))
            glVertex2i(x_center + y, y_center + x); 

        a = rtod(pi - atan((float)(y) / (float)(x)));
        if ((a >= s1 && a <= e1) || (a >= s2 && a <= e2))
            glVertex2i(x_center + -x, y_center + y); 

        a = rtod(pi - atan((float)(x) / (float)(y)));
        if ((a >= s1 && a <= e1) || (a >= s2 && a <= e2))
            glVertex2i(x_center + -y, y_center + x); 

        a = rtod(pi + atan((float)(x) / (float)(y)));
        if ((a >= s1 && a <= e1) || (a >= s2 && a <= e2))
            glVertex2i(x_center + -y, y_center + -x); 

        a = rtod(pi + atan((float)(y) / (float)(x)));
        if ((a >= s1 && a <= e1) || (a >= s2 && a <= e2))
            glVertex2i(x_center + -x, y_center + -y); 

        a = rtod(2 * pi - atan((float)(y) / (float)(x)));
        if ((a >= s1 && a <= e1) || (a >= s2 && a <= e2))
            glVertex2i(x_center + x, y_center + -y); 

        a = rtod(2 * pi - atan((float)(x) / (float)(y)));
        if ((a >= s1 && a <= e1) || (a >= s2 && a <= e2))
            glVertex2i(x_center + y, y_center + -x); 

        if (p < 0)
        {
            p = p + 2 * x + 3;
        }
        else
        {
            y--;
            p = p + 2 * x - 2 * y + 5;
        }
    }

    glEnd();
}

void arc()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);

    int radius = 150, alpha = -90, beta = 60, x_center = 300, y_center = 300;
    mcd(x_center, y_center, radius, alpha, beta);

    glFlush();
}

int main(int argc, char* argv[])
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow("2: Arc");
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 600, 0, 600);

    glutDisplayFunc(arc);
    glutMainLoop();

    return 0;
}
