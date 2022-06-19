#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
GLint r=1,g=1,b=0;
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
void triangle(){
	glColor3f(r,g,b);
	glBegin(GL_POLYGON);
	glVertex2i(-2,-2);
	glVertex2i(2,-2);
	glVertex2i(0,2);
	glEnd();
	glFlush();
	
	
}
void myKeyboard(unsigned char key,int x,int y){
	if(key=='r'||key=='R'){
		glutPostRedisplay();
		r=1;g=0;b=0;
		triangle();
	}
	else if(key=='b' || key=='B'){
		glutPostRedisplay();
		r=0;g=0;b=1;
		triangle();
	}
	else if(key=='g' || key=='G'){
		glutPostRedisplay();
		r=0;g=1;b=0;
		triangle();
	}
	else if(key=='e'||key=='E'){
		exit(0);
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
glutKeyboardFunc(myKeyboard);

glutMainLoop();
}
