//icg

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

void icg() {

	glClear(GL_COLOR_BUFFER_BIT);
	srand(time(0));
	float r = (float)((rand() % 2));
	float g = (float)((rand() % 2));
	float b = (float)((rand() % 2));

/***************************** I ******************************/

	glColor3f(r, g, b);
	glLineWidth(3);

	//I vertical
	glBegin(GL_POLYGON);
	glVertex2f(50, 130);
	glVertex2f(50, 300);
	glVertex2f(90, 300);
	glVertex2f(90, 130);

	glEnd();

	//I serifs

	glBegin(GL_POLYGON);
	glVertex2f(30, 130);
	glVertex2f(30, 150);
	glVertex2f(110, 150);
	glVertex2f(110, 130);

	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(30, 300);
	glVertex2f(30, 280);
	glVertex2f(110, 280);
	glVertex2f(110, 300);

	glEnd();
	glColor3f(1, 1, 1);
	circle(30, 275, 20);

	glColor3f(1, 1, 1);
	circle(110, 275, 20);


	glColor3f(1, 1, 1);
	circle(30, 155, 20);

	glColor3f(1, 1, 1);
	circle(110, 155, 20);

/***************************** C ******************************/

	glColor3f(r, g, b);
	circle(250, 215, 85);

	glColor3f(1, 1, 1);
	circle(265, 215, 65);

	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(300, 260);
	glVertex2f(300, 170);
	glVertex2f(340, 170);
	glVertex2f(340, 260);

	glEnd();


/***************************** G ******************************/

	glColor3f(r, g, b);
	circle(450, 215, 85);

	glColor3f(1, 1, 1);
	circle(465, 215, 65);

	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(500, 260);
	glVertex2f(500, 170);
	glVertex2f(540, 170);
	glVertex2f(540, 260);

	glEnd();

	glColor3f(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2f(512, 215);
	glVertex2f(512, 170);
	glVertex2f(522, 170);
	glVertex2f(522, 215);

	glEnd();

	glColor3f(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2f(502, 215);
	glVertex2f(502, 160);
	glVertex2f(512, 160);
	glVertex2f(512, 215);

	glEnd();

	glColor3f(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2f(492, 215);
	glVertex2f(492, 150);
	glVertex2f(502, 150);
	glVertex2f(502, 215);

	glEnd();

	//G serif

	glColor3f(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2f(477, 215);
	glVertex2f(477, 195);
	glVertex2f(537, 195);
	glVertex2f(537, 215);

	glEnd();

	glColor3f(1,1,1);
	circle(477, 195, 15);

	glColor3f(1, 1, 1);
	circle(537, 195, 15);

	glFlush();
}



int main(int argc, char* argv[]) {

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Lab 3: ICG");

	glClearColor(1, 1, 1, 1);

	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 600.0, 0.0, 600.0);

	glutDisplayFunc(icg);
	glutMainLoop();


	return 0;
}