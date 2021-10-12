#include <Windows.h>
#include <GL/glut.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float k, x1, x2, x3, focus;

void gen(float x0, float y0, float a, float r, float g, float b)
{
	glColor3f(r, g, b);

	float x;
	float y = y0;
	while (y <= y0 + 100)
	{
		x = x0 + (sqrt(4 * a * (y - y0)));
		glBegin(GL_POINTS);
		glVertex2i(x, y);
		glEnd();
		x = x0 - (sqrt(4 * a * (y - y0)));
		glBegin(GL_POINTS);
		glVertex2i(x, y);
		glEnd();
		y = y + 1;
	}

	glFlush();
}
void para(float x0, float y0, float a, float r, float g, float b)
{
	glColor3f(r, g, b);
	float t = 0;
	float x, y;
	while (t < 2.1)
	{
		y = y0 + (a * t * t);
		x = x0 + (2 * a * t);
		glBegin(GL_POINTS);
		glVertex2f(x, y);
		glEnd();
		x = x0 - (2 * a * t);
		glBegin(GL_POINTS);
		glVertex2f(x, y);
		glEnd();
		t = t + 0.01;
	}

	glFlush();
}
void mpd(int x0, int y0, float a, float r, float g, float b)
{
	glColor3f(r, g, b);
	//region 1
	int x = 0, y = 0;
	float pk = 1 - 2 * a;
	while (x <= 2 * a)
	{
		glBegin(GL_POINTS);
		glVertex2i(x + x0, y + y0);
		glVertex2i(-x + x0, y + y0);
		glEnd();

		if (pk > 0)
		{
			pk = pk + 2 * x + 3 - 4 * a;
			x = x + 1;
			y = y + 1;
		}
		else
		{
			pk = pk + 2 * x + 3;
			x = x + 1;
		}
	}
	int i = 0;
	x = 2 * a;
	y = a;
	pk = (x + 0.5) * (x + 0.5) - (4 * a * (y + 1));
	while (i < 100)
	{
		i = i + 1;
		glBegin(GL_POINTS);
		glVertex2i(x + x0, y + y0);
		glVertex2i(-x + x0, y + y0);
		glEnd();

		if (pk < 0)
		{
			pk = pk + 2 * x + 2 - 4 * a;
			y = y + 1;
			x = x + 1;
		}
		else
		{
			pk = pk - 4 * a;
			y = y + 1;
		}
	}

	glFlush();
}

void parabola()
{
	glClear(GL_COLOR_BUFFER_BIT);
	srand(time(0));
	focus = rand() % 21 + 20;
	k = rand() % 101 + 100;
	x1 = rand() % 101 + 100;
	x2 = rand() % 101 + 100;
	x3 = rand() % 101 + 200;
	glPointSize(3);
	float r = (float)((rand() % 2));
	float g = (float)((rand() % 2));
	float b = (float)((rand() % 2));

	//gen(x1, k, focus, r, g, b);
	//para(x2, k, focus, r, g, b);
	mpd(x3, k, focus, r, g, b);
	glFlush();
}

int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 500);
	glutCreateWindow("Lab 8: Vertical Parabola");
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	gluOrtho2D(0.0, 600.0, 0.0, 500.0);
	glutDisplayFunc(parabola);
	glutMainLoop();
	return 0;
}