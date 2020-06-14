
#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>

const double pi = 3.141592653589793;

void init(){
	glClearColor(0,0,0,0);
	glPointSize(10.0);
	glLineWidth(2);
	gluOrtho2D(0.0,600,0.0,450);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

}

void lingkaran(float x_mid,float y_mid,float x_size, float y_size, float n, float rot){
	float rotangle= rot*pi/180;

	for(int i=1;i<=n;i++){
		float x= x_mid + (x_size)*cos((i*2*pi/n)+rotangle);
		float y= y_mid + (y_size)*sin((i*2*pi/n)+rotangle);
		glVertex2f(x,y);
	}

}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0.676234123,0.543124);
	glBegin(GL_POLYGON);
		lingkaran(300,225,200,200,6,0);
	glEnd();
	
	for (int i=0;i<50;i++){
		glColor3f(0,(255-(i*5))/255.0f,(255-i*3)/255.0f);
		glBegin(GL_LINE_LOOP);
		lingkaran(300,225,200-(i*4),200-(i*4),6,i);
		glEnd();
	}
	
	glFlush();
}


int main(int argc,char**argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600,450);
	glutInitWindowPosition(100,40);
	glutCreateWindow("Jessi Febria - 672018079");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	
}











