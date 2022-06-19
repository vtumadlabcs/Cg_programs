#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
GLfloat size=1;
void myinit()
{
	glClearColor(0.0,0.0,0.0,0.0);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10.0,10.0,-10.0,10.0,-10.0,10.0);
//	glMatrixMode(GL_MODELVIEW);
	
}
void display(){
glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);
	glBegin(GL_POLYGON);
	glVertex2i(-1-size,-1-size);
	glVertex2i(1+size,-1-size);
	glVertex2i(1+size,1+size);
	glVertex2i(-1-size,1+size);
	glEnd();
	glFlush();
}
void size_menu(int id){
	switch(id){
		case 1:if(size+1<10){
		size=size+1;}
		else{
			size=1;
		};break;
		case 2:if(size>1)size=size-1;break;
		case 3:exit(0);
	}
	glutPostRedisplay();
	
}
int main(int argc, char *argv[])
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
glutInitWindowSize(500,500);

glutCreateWindow("square");
myinit();
glutDisplayFunc(display);
glutCreateMenu(size_menu);
glutAddMenuEntry("increase squre",1);
glutAddMenuEntry("decrease square",2);
glutAddMenuEntry("exit",3);
glutAttachMenu(GLUT_RIGHT_BUTTON);
glutMainLoop();
}
