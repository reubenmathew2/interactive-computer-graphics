#include <cmath>
#include <vector>
#include <iostream>

std::vector<float> naive_arr;
std::vector<float> bld_arr;
std::vector<float> dda_arr;

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

void hex()
{
    //glClear(GL_COLOR_BUFFER_BIT);
    //regular hexagon with center at 300, 300 and raduis = 100

    bld(350, 213, 250, 213);
    bld(250, 213, 200, 300);
    bld(200, 300, 250, 387);
    bld(250, 387, 350, 387);
    bld(350, 387, 400, 300);
    bld(400, 300, 350, 213);

    //glFlush();
}

void err_calc()
{
    std::cout << "Total Number of Points: " << naive_arr.size() << '\n';
    // std::cout << dda_arr.size() << '\n';
    // std::cout << bld_arr.size() << '\n';

    float bld_err = 0.0, dda_err = 0.0;
    for (int i = 0; i < naive_arr.size(); i++)
    {
        bld_err += (bld_arr[i] - naive_arr[i]) * (bld_arr[i] - naive_arr[i]);
        dda_err += (dda_arr[i] - naive_arr[i]) * (dda_arr[i] - naive_arr[i]);
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
    hex();
    err_calc();
    //glutMainLoop();

    return 0;
}