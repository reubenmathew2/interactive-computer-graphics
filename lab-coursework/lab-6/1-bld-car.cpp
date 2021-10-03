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

void xbld(float x1, float y1, float x2, float y2)
{
    //glColor3f(0, 0, 0);
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
    //glColor3f(0, 0, 0);
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

    if (abs(y2 - y1) < abs(x2 - x1))
    {
        if (x1 > x2)
        {
            xbld(x2, y2, x1, y1);
        }
        else
        {
            xbld(x1, y1, x2, y2);
        }
    }
    else
    {
        if (y1 > y2)
        {
            ybld(x2, y2, x1, y1);
        }
        else
        {
            ybld(x1, y1, x2, y2);
        }
    }
}

void car()
{
    glClear(GL_COLOR_BUFFER_BIT);
    //body
    glColor3f(0, 0, 0);

    bld(95, 100, 95, 190);
    bld(95, 190, 500, 190);
    bld(500, 190, 500, 100);
    bld(500, 100, 95, 100);

    //roof
    bld(195, 190, 275, 307);
    bld(275, 307, 450, 307);
    bld(450, 307, 500, 190);
    bld(500, 190, 195, 190);

    //front window
    bld(215, 199, 280, 298);
    bld(280, 298, 340, 298);
    bld(340, 298, 340, 199);
    bld(340, 199, 215, 199);

    //rear window
    bld(350, 199, 350, 298);
    bld(350, 298, 442, 298);
    bld(442, 298, 485, 199);
    bld(485, 199, 350, 199);

    glColor3f(0.77, 0.77, 0.77);
    //font wheel
    double radius = 47;
    int h = 200, k = 100;
    // wheel(h, k, radius);
    for (int i = 0; i < 360; i++)
    {
        double radian = i * 3.1415926535897932384626433832795 / 180;

        bld(radius * cos(radian) + h, radius * sin(radian) + k, h, k);
        bld(h, k, radius * cos(radian) + h, radius * sin(radian) + k);
    }

    //rear wheel
    radius = 47;
    h = 420, k = 100;
    // wheel(h, k, radius);
    for (int i = 0; i < 360; i++)
    {
        double radian = i * 3.1415926535897932384626433832795 / 180;

        bld(radius * cos(radian) + h, radius * sin(radian) + k, h, k);
        bld(h, k, radius * cos(radian) + h, radius * sin(radian) + k);
    }


    //midpoint algorithm circle
    
    glColor3f(0, 0, 0);
    mcd(200, 100, 47);
    mcd(420, 100, 47);

    glFlush();
}

int main(int argc, char* argv[])
{

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Lab 6: BLD Car");

    glClearColor(1, 1, 1, 1);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 600.0, 0.0, 600.0);

    glutDisplayFunc(car);
    glutMainLoop();

    return 0;
}