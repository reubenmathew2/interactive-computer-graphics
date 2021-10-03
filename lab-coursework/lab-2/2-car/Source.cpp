//car

#include <Windows.h>
#include <GL/glut.h>
#include <cmath>

void wheel(int h, int k, double radius)
{

	//silver disc for wheel
	glColor3f(0.77, 0.77, 0.77);
	glLineWidth(3);

	glBegin(GL_LINES);

	for (int i = 0; i < 360; i++)
	{
		double radian = i * 3.1415926535897932384626433832795 / 180;

		glVertex2d(radius * cos(radian) + h, radius * sin(radian) + k);
		glVertex2d(h, k);
	}

	glEnd();

	//black border for tyre
	glColor3f(0, 0, 0);
	glPointSize(3);
	glBegin(GL_POINTS);

	for (int i = 0; i < 360; i++)
	{
		double radian = i * 3.1415926535897932384626433832795 / 180;

		glVertex2d(radius * cos(radian) + h, radius * sin(radian) + k);
	}

	glEnd();
}

void car()
{

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0, 0, 0);
	glLineWidth(3);

	//body
	glBegin(GL_LINE_LOOP);
	glVertex2f(95, 100);
	glVertex2f(95, 190);
	glVertex2f(500, 190);
	glVertex2f(500, 100);

	glEnd();

	//roof
	glBegin(GL_LINE_STRIP);
	glVertex2f(195, 190);
	glVertex2f(275, 307);
	glVertex2f(450, 307);
	glVertex2f(500, 190);
	glEnd();

	//front window
	glBegin(GL_LINE_LOOP);
	glVertex2f(215, 199);
	glVertex2f(280, 298);
	glVertex2f(340, 298);
	glVertex2f(340, 199);
	glEnd();

	//rear window
	glBegin(GL_LINE_LOOP);
	glVertex2f(350, 199);
	glVertex2f(350, 298);
	glVertex2f(442, 298);
	glVertex2f(485, 199);
	glEnd();

	//font wheel
	double radius = 47;
	int h = 200, k = 100;
	wheel(h, k, radius);

	//rear wheel
	radius = 47;
	h = 420, k = 100;
	wheel(h, k, radius);

	glFlush();
}

int main(int argc, char *argv[])
{

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("2: Car");

	glClearColor(1, 1, 1, 1);

	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 600.0, 0.0, 600.0);

	glutDisplayFunc(car);
	glutMainLoop();

	return 0;
}