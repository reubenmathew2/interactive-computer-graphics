#include <cmath>
#include <vector>
#include <iostream>

std::vector<float> naive_arr;
std::vector<float> bld_arr;
std::vector<float> dda_arr;

void err_calc();
void dda(float x1, float y1, float x2, float y2)
{
    /*glColor3f(0, 0, 0);
    glPointSize(3);
    glBegin(GL_POINTS);*/
    float slope = 0;
    float err = 0.0;
    if (x2 == x1)
    {
        if (y1 < y2)
        {
            for (int i = y1; i <= y2; i++)
            {
                err = x1;
                dda_arr.push_back(round(err));
                //glVertex2f(round(x1), i);
            }
        }
        else
        {
            for (int i = y1; i >= y2; i--)
            {
                err = x1;
                dda_arr.push_back(round(err));
                //glVertex2f(round(x1), i);
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
                    err = y1;
                    dda_arr.push_back(round(err));
                    //glVertex2f(i, round(y1));
                    y1 = y1 + slope;
                }
            }
            else
            {
                for (int i = x1; i >= x2; i--)
                {
                    err = y1;
                    dda_arr.push_back(round(err));
                    //glVertex2f(i, round(y1));
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
                    err = x1;
                    dda_arr.push_back(round(err));
                    //glVertex2f(round(x1), i);
                    x1 = x1 + (1.0 / slope);
                }
            }
            else
            {
                for (int i = y1; i >= y2; i--)
                {
                    err = x1;
                    dda_arr.push_back(round(err));
                    //glVertex2f(round(x1), i);
                    x1 = x1 - (1.0 / slope);
                }
            }
        }
    }
    //glEnd();
}

void naive(float x1, float y1, float x2, float y2)
{
    /*glColor3f(0, 0, 0);
    glPointSize(3);
    glBegin(GL_POINTS);*/
    float err = 0.0;
    float dy = y2 - y1;
    float dx = x2 - x1;
    if (x1 == x2)
    {
        if (y1 < y2)
        {
            for (int i = y1; i <= y2; i++)
            {
                err = x1;
                naive_arr.push_back(err);
                //glVertex2f(x1, i);
            }
        }
        else
        {
            for (int i = y1; i >= y2; i--)
            {
                err = x1;
                naive_arr.push_back(err);
                //glVertex2f(x1, i);
            }
        }
    }
    else
    {
        float m = dy / dx;
        if (abs(m) < 1)
        {
            if (x1 < x2)
            {
                for (int i = x1; i <= x2; i++)
                {
                    //glVertex2f(i, (y1 + dy * (i - x1) / dx));
                    err = (y1 + dy * (i - x1) / dx);
                    naive_arr.push_back(err);
                }
            }
            else
            {
                for (int i = x1; i >= x2; i--)
                {
                    //glVertex2f(i, (y1 + dy * (i - x1) / dx));
                    err = (y1 + dy * (i - x1) / dx);
                    naive_arr.push_back(err);
                }
            }
        }
        else
        {
            if (y1 < y2)
            {
                for (int i = y1; i <= y2; i++)
                {
                    //glVertex2f((x1 + dx * (i - y1) / dy), i);
                    err = x1 + dx * (i - y1) / dy;
                    naive_arr.push_back(err);
                }
            }
            else
            {
                for (int i = y1; i >= y2; i--)
                {
                    //glVertex2f((x1 + dx * (i - y1) / dy), i);
                    err = x1 + dx * (i - y1) / dy;
                    naive_arr.push_back(err);
                }
            }
        }
    }
    //glEnd();
}

void xbld(float x1, float y1, float x2, float y2)
{
    // glColor3f(0, 0, 0);
    // glPointSize(3);
    // glBegin(GL_POINTS);
    float dx, dy, yi;
    float P;
    float err = 0.0;
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
        bld_arr.push_back(err);
        //glVertex2f(i, y1);
        if (P > 0)
        {
            y1 += yi;
            P += 2 * (dy - dx);
        }
        else
            P += 2 * dy;
    }

    //glEnd();
}

void ybld(float x1, float y1, float x2, float y2)
{
    // glColor3f(0, 0, 0);
    // glPointSize(3);
    // glBegin(GL_POINTS);
    float dx, dy, xi;
    float P, err = 0.0;
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
        bld_arr.push_back(err);
        //glVertex2f(x1, i);
        if (P > 0)
        {
            x1 += xi;
            P += 2 * (dx - dy);
        }
        else
            P += 2 * dx;
    }

    //glEnd();
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
            naive(x2, y2, x1, y1);
            dda(x2, y2, x1, y1);
        }
        else
        {
            xbld(x1, y1, x2, y2);
            naive(x1, y1, x2, y2);
            dda(x1, y1, x2, y2);
        }
    }
    else
    {
        if (y1 > y2)
        {
            ybld(x2, y2, x1, y1);
            naive(x2, y2, x1, y1);
            dda(x2, y2, x1, y1);
        }
        else
        {
            ybld(x1, y1, x2, y2);
            naive(x1, y1, x2, y2);
            dda(x1, y1, x2, y2);
        }
    }
}

void house()
{
    //glClear(GL_COLOR_BUFFER_BIT);
    //body
    //glColor3f(0, 0, 0);
    bld(100, 50, 100, 350);

    bld(100, 350, 500, 350);
    bld(500, 350, 500, 50);
    bld(500, 50, 100, 50);

    //coloring the body
    //glColor3f(0.26, 0.75, 0.96);
    for (int i = 103; i <= 497; i++)
        bld(i, 53, i, 347);

    //roof
    //glColor3f(0, 0, 0);
    bld(100, 350, 300, 600);
    bld(300, 600, 500, 350);
    bld(500, 350, 100, 350);

    //coloring the roof
    //glColor3f(0.95, 0.35, 0.36);
    for (int i = 106; i <= 494; i++)
        bld(300, 595, i, 353);

    //door
    //glColor3f(0, 0, 0);
    bld(255, 50, 255, 200);
    bld(255, 200, 345, 200);
    bld(345, 200, 345, 50);
    bld(345, 50, 255, 50);

    //coloring the door
    //glColor3f(1, 1, 1);
    for (int i = 258; i <= 342; i++)
        bld(i, 53, i, 197);

    //left window
    //glColor3f(0, 0, 0);
    bld(150, 150, 150, 200);
    bld(150, 200, 200, 200);
    bld(200, 200, 200, 150);
    bld(200, 150, 150, 150);

    //coloring the left window
    //glColor3f(1, 1, 1);
    for (int i = 153; i <= 197; i++)
        bld(i, 153, i, 197);

    //right window
    //glColor3f(0, 0, 0);
    bld(400, 150, 400, 200);
    bld(400, 200, 450, 200);
    bld(450, 200, 450, 150);
    bld(450, 150, 400, 150);

    //coloring the right window
    //glColor3f(1, 1, 1);
    for (int i = 403; i <= 447; i++)
        bld(i, 153, i, 197);

    //glFlush();
}

void err_calc()
{
    std::cout << "Total Number of Points: " << naive_arr.size() << '\n';
    //std::cout << dda_arr.size() << '\n';
    //std::cout << bld_arr.size() << '\n';

    float bld_err = 0.0, dda_err = 0.0;
    for (int i = 0; i < naive_arr.size(); i++)
    {
        bld_err += (bld_arr[i] - naive_arr[i]) * (bld_arr[i] - naive_arr[i]);
        //std::cout << bld_err << '\n';
        dda_err += (dda_arr[i] - naive_arr[i]) * (dda_arr[i] - naive_arr[i]);
        //std::cout << dda_err << '\n';
    }

    float bld_avg = bld_err / naive_arr.size();
    float dda_avg = dda_err / naive_arr.size();

    std::cout << "BLD Error: " << bld_avg << '\n';
    std::cout << "DDA Error: " << dda_avg << '\n';
}

int main(int argc, char *argv[])
{

    // glutInit(&argc, argv);

    // glutInitDisplayMode(GLUT_SINGLE);

    // glutInitWindowPosition(100, 100);
    // glutInitWindowSize(600, 600);
    // glutCreateWindow("Lab 5: BLD Hexagon");

    // glClearColor(1, 1, 1, 1);

    // glMatrixMode(GL_PROJECTION);
    // gluOrtho2D(0.0, 600.0, 0.0, 600.0);

    // glutDisplayFunc(hex);
    house();
    err_calc();
    //glutMainLoop();

    return 0;
}