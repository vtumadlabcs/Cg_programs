#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
void myinit()
{
	glClearColor(0.0,0.0,0.0,0.0);	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-5.0,5.0,-5.0,5.0,-10.0,10.0);
//	glMatrixMode(GL_MODELVIEW);
	
}
void display(){
glClear(GL_COLOR_BUFFER_BIT);
	
}

void hexagon(){
	glColor3f(1,0,0);
	glBegin(GL_POLYGON);
	glVertex2i(-1,-2);
	glVertex2i(1,-2);
	glVertex2i(2,0);
	glVertex2i(1,2);
	glVertex2i(-1,2);
	glVertex2i(-2,0);
	glEnd();
	glFlush();
}

void triangle(){
	glColor3f(0,1,0);
	glBegin(GL_POLYGON);
	glVertex2i(-2,-2);
	glVertex2i(2,-2);
	glVertex2i(0,2);
	glEnd();
	glFlush();
}
void myMouse(int button,int state,int x,int y){
	 if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
	 	glutPostRedisplay();
	 	hexagon();
	 }
	 else if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN){
	 	glutPostRedisplay();
	 	triangle();
	 }
}



int main(int argc, char *argv[])
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
glutInitWindowSize(500,500);

glutCreateWindow("square");
myinit();
glutDisplayFunc(display);
glutMouseFunc(myMouse);

glutMainLoop();
}
