#include<GL/glut.h>
#include<stdio.h>
typedef float point[3];
int n;
point v[] = {{ 0.0, 0.0, 1.0},
{-0.8, -0.4, 0.0},
{ 0.0, 0.8, 0.0},
{ 0.8, -0.4, 0.0}};
void divide_triangle(point a, point b, point c, int m){
point v1, v2, v3;
int j;
if(m > 0) {
for(j=0; j<3; j++) v1[j] = (a[j] + b[j]) / 2;
for(j=0; j<3; j++) v2[j] = (a[j] + c[j]) / 2;
for(j=0; j<3; j++) v3[j] = (b[j] + c[j]) / 2;
divide_triangle(a, v1, v2, m-1);
divide_triangle(b, v1, v3, m-1);
divide_triangle(c, v2, v3, m-1);
} else {
glBegin(GL_POLYGON);
glNormal3fv(a);
glVertex3fv(a);
glVertex3fv(b);
glVertex3fv(c);
glEnd();
}
}
void tetrahedron(int m){
glColor3f(1.0, 0.0, 0.0);
divide_triangle(v[0], v[1], v[2], m);
glColor3f(0.0, 1.0, 0.0);
divide_triangle(v[0], v[2], v[3], m);
glColor3f(0.0, 0.0, 1.0);
divide_triangle(v[0], v[1], v[3], m);
glColor3f(1.0, 1.0, 0.0);
divide_triangle(v[1], v[2], v[3], m);
}
void display(){
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
tetrahedron(n);
glFlush();
}
int main(int argc, char ** argv){
printf("How many divisions?: ");
scanf("%d",&n);
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
glutInitWindowPosition(500, 100);
glutInitWindowSize(500, 500);
glutCreateWindow("3D Sierpinski Gasket...Rohit 124");
glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
glutDisplayFunc(display);
glEnable(GL_DEPTH_TEST);
glClearColor(1, 1, 1, 1);
glutMainLoop();
}
