#include<cstdio>
#include <GL/gl.h>
#include <GL/glut.h>
#include<math.h>
#define PI 2*acos(0.00)
GLfloat position = 0.0f;
GLfloat speed = 0.1f;


GLfloat position2 = 0.0f;
GLfloat speed2 = 0.1f;


void drawBG();

void car1();
void car2();
void drawQuad(GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat);
void drawLine(GLfloat , GLfloat , GLfloat , GLfloat);
void drawTriangle(GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat);

void drawCircle(GLfloat,GLfloat,GLfloat);

void drawDigits(GLfloat,GLfloat,GLfloat);
void handleMouse(int , int , int , int );

void Idle();

void handleKeypress(unsigned char , int , int );

void drawRain();


void drawRain()
{
   // drawLine();
}


void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
case 'a':
     speed2-=0.1;//
    break;
case 'd':
     speed2+=0.1;
    break;
glutPostRedisplay();
}}



void Idle()
{
glutPostRedisplay();//// marks the current window as needing to be redisplayed
}

void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
	    speed+=0.1;
	}
	/*if(button==GLUT_RIGHT_BUTTON)
    {
        speed-=0.1;
        speed2-=0.1;
    }*/

    glutPostRedisplay();
}

void drawBitmapText(char *str,float x,float y,float z)
{
	char *c;
	glRasterPos3f(x, y,z);

	for (c=str ; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *c);
	}
}


void drawCircle(GLfloat x,GLfloat y,GLfloat radius)
{
	int i;
	int lineAmount = 100;
	GLfloat twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x,y);
	//glColor3ub(255, 0, 191);
		for(i = 0; i <= lineAmount;i++)
        {
			glVertex2f(x + (radius * cos(i *  twicePi / lineAmount)),y + (radius* sin(i * twicePi / lineAmount)));

		}
	glEnd();
}




void drawDigits(float x,float y,float radius)
{
    char digits[12][3]={"3","2","1","12","11","10","9","8","7","6","5","4"};
	int i;
	int lineAmount = 12;
	float twicePi = 2.0f * PI;
	//glColor3ub(255, 0, 191);
		for(i = 0; i < 12;i++)
        {
			drawBitmapText(digits[i],x + (radius * cos(i *  twicePi / lineAmount)),y + (radius* sin(i * twicePi / lineAmount)),0.0);

		}
	glEnd();

}

void drawGrid()
{
    glColor3ub(128,128,128);
	glBegin(GL_LINES);
	for(double i=1.0;i>=-1.0;i-=0.2)
    {
        glVertex2f(1.0,(i));
        glVertex2f(-1.0,(i));
    }
    for(double i=1.0;i>=-1.0;i-=0.2)
    {
        glVertex2f((i),1.0);
        glVertex2f((i),-1.0);
    }
    glColor3ub(0, 102, 255);
    glVertex2f(1.0,0.0);
    glVertex2f(-1.0,0.0);
    glVertex2f(0.0,1.0);
    glVertex2f(0.0,-1.0);
	glEnd();
}


void drawQuad(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3)
{
    glBegin(GL_QUADS);

    glVertex2f(x0,y0);

    glVertex2f(x1,y1);

    glVertex2f(x2,y2);

    glVertex2f(x3,y3);

    glEnd();
}


void drawLine(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1)
{
    glBegin(GL_LINES);

    glVertex2f(x0,y0);

    glVertex2f(x1,y1);

    glEnd();
}

void drawTriangle(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2)
{
    glBegin(GL_TRIANGLES);

    glVertex2f(x0,y0);

    glVertex2f(x1,y1);

    glVertex2f(x2,y2);

    glEnd();
}

void drawBG()
{
    glBegin(GL_QUADS);
    glColor3ub(128, 170, 255);
    glVertex2f(1.0,1.0);
    glVertex2f(-1.0,1.0);
    glVertex2f(-1.0,-1.0);
    glVertex2f(1.0,-1.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(96, 32, 32);
    glVertex2f(1.0,-0.1);
    glVertex2f(-1.0,-0.1);
    glVertex2f(-1.0,-1.0);
    glVertex2f(1.0,-1.0);
    glEnd();
}

void update1(int value) {
    if(position <-1.5 )
        position = 1.5f;
    if(position>1.5)
    {
        position=1.5;
    }
    position -= speed;
	glutPostRedisplay();
	glutTimerFunc(70, update1, 0);
}


void update2(int value) {
    if(position2 >1.5)
        position2 = -1.5f;
    if(position2<-1.5)
    {
        position2=-1.5;
    }
    position2 += speed2;
	glutPostRedisplay();
	glutTimerFunc(90, update2, 0);
}


void init() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}


void car1()
{
   glLoadIdentity();
glPushMatrix();
glTranslatef(position,0.0, 0.0f);
glColor3ub(13, 13, 13);
      drawCircle(-0.185,-0.79,0.09);
      glColor3ub(13, 13, 13);
      drawCircle(0.185,-0.79,0.09);
   glBegin(GL_QUADS);
      glColor3ub(153, 153, 102);
      glVertex2f(-0.4f, -0.8f);
      glVertex2f( 0.4f, -0.8f);
      glVertex2f( 0.4f,  -0.4f);
      glVertex2f(-0.4f,  -0.4f);

   glEnd();
glPopMatrix();

}

void car2()
{
    glLoadIdentity();
glPushMatrix();
glTranslatef(position2,0.0, 0.0f);
glColor3ub(13, 13, 13);
      drawCircle(-0.185,-0.19,0.09);
      glColor3ub(13, 13, 13);
      drawCircle(0.185,-0.19,0.09);
   glBegin(GL_QUADS);
      glColor3ub(255, 0, 0);
      glVertex2f(0.4f, -0.2f);
      glVertex2f(- 0.4f, -0.2f);
      glVertex2f(- 0.4f,  0.2f);
      glVertex2f(0.4f,  0.2f);
   glEnd();
glPopMatrix();
}


void display() {

   glClear(GL_COLOR_BUFFER_BIT);
drawBG();

   car1();
   car2();
   drawRain();
   glFlush();
   glutSwapBuffers();
}



int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(320, 320);
   glutInitWindowPosition(50, 50);
   glutInitDisplayMode(GLUT_DOUBLE);
   glutCreateWindow("Translation Animation");
   glutDisplayFunc(display);
   init();
  // glutIdleFunc(Idle);
   glutMouseFunc(handleMouse);
   glutKeyboardFunc(handleKeypress);
   glutTimerFunc(70, update1, 0);
   glutTimerFunc(90, update2, 0);
   glutMainLoop();
   return 0;
}
