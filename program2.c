#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#define PI 2.1425
GLfloat trial[3][3]={{100.0,300.0,200.0},{100.0,100.0,300.0},{1.0,1.0,1.0}};
GLfloat rot_mat[3][3]={{0},{0},{0}};
GLfloat result[3][3]={{0},{0},{0}};
GLfloat h=100.0;
GLfloat k=100.0;
GLfloat theta;

void multiply()
{
int i,j,l;
for(i=0;i<3;i++)
for(j=0;j<3;j++)
{
result[i][j]=0;
for(l=0;l<3;l++)
result[i][j]=result[i][j]+rot_mat[i][l]*trial[l][j];
}
}

void rotate(GLfloat m,GLfloat n)
{
rot_mat[0][0]=cos(theta);
rot_mat[0][1]=-sin(theta);
rot_mat[0][2]=m;
rot_mat[1][0]=sin(theta);
rot_mat[1][1]=cos(theta);
rot_mat[1][2]=n;
rot_mat[2][0]=0;
rot_mat[2][1]=0;
rot_mat[2][2]=1;
multiply();
}

void drawtria()
{
glColor3f(1.0,0.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(trial[0][0],trial[1][0]);
glVertex2f(trial[0][1],trial[1][1]);
glVertex2f(trial[0][2],trial[1][2]);
glEnd();
}
void drawrotatetria()
{
	//glColor3f(1.0,0.0,0.0);
	glBegin(GL_TRIANGLES);
	glVertex2i(result[0][0],result[1][0]);
	glVertex2i(result[0][1],result[1][1]);	
	glVertex2i(result[0][2],result[1][2]);
	glEnd();
}



void display()
{
glClear(GL_COLOR_BUFFER_BIT);
GLfloat m,n;
drawtria();
m=-h*(cos(theta)-1)+k*(sin(theta));
n=-k*(cos(theta)-1)-h*(sin(theta));
rotate(m,n);
glColor3f(1.0,0.0,0.0);
drawrotatetria();
rotate(0,0);
glColor3f(0.0,0.0,1.0);
drawrotatetria();
glFlush();
}

void myinit()
{
glClearColor(1.0,1.0,1.0,1.0);
glColor3f(1.0,1.0,0.0);
glPointSize(1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,499.0,0.0,499.0);
}

void main(int argc,char **argv)
{
printf("Enter the rotation angle\n");
scanf("%f",&theta);
theta=theta*PI/180;
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(0,0);
glutCreateWindow("Triangle Rotation...Rohit 124");
glutDisplayFunc(display);
myinit();
glutMainLoop();
}
