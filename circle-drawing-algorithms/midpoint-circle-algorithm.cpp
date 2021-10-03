#include <Windows.h>
#include <GL/glut.h>
#include <vector>
#include <iostream>

void mcd(int x_centre, int y_centre, int r)
{
    glPointSize(3);
    glBegin(GL_POINTS);
    int x = r, y = 0;

    // Printing the initial point on the axes
    // after translation
    glVertex2f(x + x_centre, y + y_centre);

    // When radius is zero only a single
    // point will be printed
    if (r > 0)
    {
        glVertex2f(x + x_centre, -y + y_centre);
        glVertex2f(y + x_centre, x + y_centre);
        glVertex2f(-y + x_centre, x + y_centre);
    }

    // Initialising the value of P
    int P = 1 - r;
    while (x > y)
    {
        y++;

        // Mid-point is inside or on the perimeter
        if (P <= 0)
            P = P + 2 * y + 1;
        // Mid-point is outside the perimeter
        else
        {
            x--;
            P = P + 2 * y - 2 * x + 1;
        }

        // All the perimeter points have already been printed
        if (x < y)
            break;

        // Printing the generated point and its reflection
        // in the other octants after translation
        glVertex2f(x + x_centre, y + y_centre);
        glVertex2f(-x + x_centre, y + y_centre);
        glVertex2f(x + x_centre, -y + y_centre);
        glVertex2f(-x + x_centre, -y + y_centre);

        // If the generated point is on the line x = y then
        // the perimeter points have already been printed
        if (x != y)
        {
            glVertex2f(y + x_centre, x + y_centre);
            glVertex2f(-y + x_centre, x + y_centre);
            glVertex2f(y + x_centre, -x + y_centre);
            glVertex2f(-y + x_centre, -x + y_centre);
        }
    }
    glEnd();
}

void mcdCircle()
{
    glClear(GL_COLOR_BUFFER_BIT);

    //midpoint algorithm circle
    
    glColor3f(0, 0, 0);

    int x_center = 300, y_center = 300, radius = 100;

    mcd(x_center, y_center, radius);

    glFlush();
}

int main(int argc, char* argv[])
{

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Midpoint Circle Algo");

    glClearColor(1, 1, 1, 1);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 600.0, 0.0, 600.0);

    glutDisplayFunc(mcdCircle);
    glutMainLoop();

    return 0;
}