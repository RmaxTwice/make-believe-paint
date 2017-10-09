#include "../headers/glew/glew.h"
#include "../headers/freeglut/freeglut.h"
#include "primitivas.h"
#include <iostream>

using namespace std;


//A continuación se diseñarán los métodos para desplegar las primitivas 2D y sus versiones rellenas

void dibujarLinea(int x1, int y1, int x2, int y2)
{	GLfloat

	glBegin(GL_LINES);
	glVertex3f(GLfloat(x1), GLfloat(y1), 0.0);
	glVertex3f(GLfloat(x2), GLfloat(y2), 0.0);
	glEnd();
}

void dibujarRectangulo(int x1, int y1, int x2, int y2)
{
	glBegin(GL_POLYGON);
	glVertex3f(GLfloat(x1), GLfloat(y1), 0.0);
	glVertex3f(GLfloat(x2), GLfloat(y1), 0.0);
	glVertex3f(GLfloat(x2), GLfloat(y2), 0.0);
	glVertex3f(GLfloat(x1), GLfloat(y2), 0.0);
	glEnd();
}