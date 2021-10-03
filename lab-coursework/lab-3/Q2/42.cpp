//42

//updated to 45

#include <Windows.h> 
#include<GL/glut.h>
#include<cmath>
#include<time.h>

void circle(int h, int k, double radius) {

	glLineWidth(3);

	glBegin(GL_LINES);

	for (int i = 0; i < 360; i++)
	{
		double radian = i * 3.1415926535897932384626433832795 / 180;

		glVertex2d(radius * cos(radian) + h, radius * sin(radian) + k);
		glVertex2d(h, k);
	}

	glEnd();
}

void rollno() {

	glClear(GL_COLOR_BUFFER_BIT);

	//random colours
	srand(time(0));
	float r = (float)((rand() % 2));
	float g = (float)((rand() % 2));
	float b = (float)((rand() % 2));

	glColor3f(r, g, b);
	glLineWidth(3);

	/*************************** 4 ************************/

		//4 base
	glBegin(GL_POLYGON);
	glVertex2f(120, 175);
	glVertex2f(120, 200);
	glVertex2f(265, 200);
	glVertex2f(265, 175);

	glEnd();

	//4 triangle black
	glBegin(GL_POLYGON);
	glVertex2f(120, 200);
	glVertex2f(200, 300);
	glVertex2f(200, 200);

	glEnd();



	//4 vertical
	glBegin(GL_POLYGON);
	glVertex2f(200, 130);
	glVertex2f(200, 300);
	glVertex2f(240, 300);
	glVertex2f(240, 130);

	glEnd();

	//4 triangle white
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(135, 200);
	glVertex2f(200, 280);
	glVertex2f(200, 200);

	glEnd();


	/********************************** 2 ***************************/


	glColor3f(r, g, b);
	circle(360, 180, 62);

	glColor3f(1, 1, 1);
	circle(352.5, 180, 40);

	glColor3f(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2f(300, 275);
	glVertex2f(300, 300);
	glVertex2f(425, 300);
	glVertex2f(425, 275);

	glEnd();

	glColor3f(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2f(300, 275);
	glVertex2f(300, 210);
	glVertex2f(325, 210);
	glVertex2f(325, 275);

	glEnd();

	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(295, 210);
	glVertex2f(295, 150);
	glVertex2f(325, 150);
	glVertex2f(325, 210);

	glEnd();

//	glColor3f(1, 1, 1);
//	glBegin(GL_POLYGON);
//	glVertex2f(290, 200);
//	glVertex2f(290, 260);
//	glVertex2f(352.5, 260);
//	glVertex2f(352.5, 200);

//	glEnd();
	glFlush();
}



int main(int argc, char* argv[]) {

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Lab 3: 42");

	glClearColor(1, 1, 1, 1);

	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 600.0, 0.0, 600.0);

	glutDisplayFunc(rollno);
	glutMainLoop();


	return 0;
}