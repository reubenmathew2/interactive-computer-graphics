//house
//updated with circle windows
#include <Windows.h> 
#include<GL/glut.h>
#include<cmath>
#include<time.h>

void wheel(int h, int k, double radius) {

	//silver disc for wheel
	glColor3f(1, 1, 1);
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

void house() {

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0, 0, 0);
	glLineWidth(3);

	//body
	glColor3f(0.26, 0.75, 0.96);
	glBegin(GL_POLYGON); 
	glVertex2f(100, 50);
	glVertex2f(100, 350);
	glVertex2f(500, 350);
	glVertex2f(500, 50);

	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(100, 50);
	glVertex2f(100, 350);
	glVertex2f(500, 350);
	glVertex2f(500, 50);

	glEnd();

	//roof
	glColor3f(0.95, 0.35, 0.36);
	glBegin(GL_POLYGON);
	glVertex2f(100, 350);
	glVertex2f(300, 600);
	glVertex2f(500, 350);
	
	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(100, 350);
	glVertex2f(300, 600);
	glVertex2f(500, 350);

	glEnd();



	//door
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(255, 50);
	glVertex2f(255, 200);
	glVertex2f(345, 200);
	glVertex2f(345, 50);
	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(255, 50);
	glVertex2f(255, 200);
	glVertex2f(345, 200);
	glVertex2f(345, 50);
	glEnd();

	//left window
	glColor3f(1, 1, 1);
	// glBegin(GL_POLYGON);
	// glVertex2f(150, 150);
	// glVertex2f(150, 200);
	// glVertex2f(200, 200);
	// glVertex2f(200, 150);
	// glEnd();
	wheel(175,175,20);

	// glColor3f(0, 0, 0);
	// glBegin(GL_LINE_LOOP);
	// glVertex2f(150, 150);
	// glVertex2f(150, 200);
	// glVertex2f(200, 200);
	// glVertex2f(200, 150);
	// glEnd();

	//right window
	glColor3f(1, 1, 1);
	// glBegin(GL_POLYGON);
	// glVertex2f(400, 150);
	// glVertex2f(400, 200);
	// glVertex2f(450, 200);
	// glVertex2f(450, 150);
	// glEnd();

	// glColor3f(0, 0, 0);
	// glBegin(GL_LINE_LOOP);
	// glVertex2f(400, 150);
	// glVertex2f(400, 200);
	// glVertex2f(450, 200);
	// glVertex2f(450, 150);
	// glEnd();
	wheel(425, 175, 20);

	glFlush();
}



int main(int argc, char* argv[]) {

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE);

	glutInitWindowPosition(0, 0);
	glutInitWindowSize(600, 600);
	glutCreateWindow("1: House");

	glClearColor(1, 1, 1, 1);

	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 600.0, 0.0, 600.0);

	glutDisplayFunc(house);
	glutMainLoop();


	return 0;
}