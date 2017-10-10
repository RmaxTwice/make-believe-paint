#include "../headers/glew/glew.h"
#include "../headers/freeglut/freeglut.h"
#include "primitivas.h"
#include <iostream>

using namespace std;


//A continuación se diseñarán los métodos para desplegar las primitivas 2D y sus versiones rellenas

void dibujarPunto(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex3f(GLfloat(x), GLfloat(y), 0.0);
	glEnd();
}

void dibujar8Puntos(int x, int y, int cx, int cy) {
	dibujarPunto(x + cx, y + cy);
	dibujarPunto(-x + cx, -y + cy);
	dibujarPunto(-x + cx, y + cy);
	dibujarPunto(x + cx, -y + cy);
	dibujarPunto(y + cx, x + cy);
	dibujarPunto(-y + cx, -x + cy);
	dibujarPunto(-y + cx, x + cy);
	dibujarPunto(y + cx, -x + cy);
}

void dibujarLinea(int x1, int y1, int x2, int y2)
{
	/*
	int m = (y2 - y1) / (x2 - x1);
	int b = y1 - m*x1;
	int y = y1;
	glBegin(GL_POINTS);
	glVertex3f(GLfloat(x1), GLfloat(y1), 0.0);
	for (int x = x1 + 1; x <= x2; x++) {
		y = m * x + b;
		glVertex3f(GLfloat(x), GLfloat(y), 0.0);
	}
	glEnd();

	int dx = x2 - x1;
	int dy = y2 - y1;
	int d = dx - 2 * dy;
	int incE = 2 * dy;
	int incNE = 2 * (dx - dy);
	int x = x1;
	int y = y1;

	//cout << x << " , "<< y;
	dibujarPunto(x, y);
	while (x < x2) {
		if (d <= 0) {
			d += incNE;
			y++;
		}
		else {
			d += incE;
		}
		x++;
		dibujarPunto(x, y);
	}
	*/

	glBegin(GL_LINES);
		glVertex3f(GLfloat(x1), GLfloat(y1), 0.0);
		glVertex3f(GLfloat(x2), GLfloat(y2), 0.0);
	glEnd();
}

void dibujarRectanguloBorde(int x1, int y1, int x2, int y2)
{
	glBegin(GL_LINES);
		glVertex3f(GLfloat(x1), GLfloat(y1), 0.0);
		glVertex3f(GLfloat(x2), GLfloat(y1), 0.0);

		glVertex3f(GLfloat(x2), GLfloat(y1), 0.0);
		glVertex3f(GLfloat(x2), GLfloat(y2), 0.0);

		glVertex3f(GLfloat(x2), GLfloat(y2), 0.0);
		glVertex3f(GLfloat(x1), GLfloat(y2), 0.0);

		glVertex3f(GLfloat(x1), GLfloat(y2), 0.0);
		glVertex3f(GLfloat(x1), GLfloat(y1), 0.0);
	glEnd();
}

void dibujarRectanguloRelleno(int x1, int y1, int x2, int y2)
{
	glBegin(GL_POLYGON);
	glVertex3f(GLfloat(x1), GLfloat(y1), 0.0);
	glVertex3f(GLfloat(x2), GLfloat(y1), 0.0);
	glVertex3f(GLfloat(x2), GLfloat(y2), 0.0);
	glVertex3f(GLfloat(x1), GLfloat(y2), 0.0);
	glEnd();
}

void dibujarCirculoBorde(int radius, int cx, int cy) {
	int x, y, d;
	x = 0;
	y = radius;
	d = 1 - radius;
	dibujar8Puntos(x, y,cx,cy);
	while (y > x) {
		if (d < 0) {
			d = d + (x << 1) + 3; //  x << 1 == 2 * x
		}
		else {
			d = d + ((x - y) << 1) + 5; //  x << 1 == 2 * x
			y = y - 1;
		}
		x = x + 1;
		dibujar8Puntos(x, y, cx, cy);
	}
}

void dibujarTrianguloBoxBorde(int x1, int y1, int x2, int y2) { // Triangulo con base paralela a Eje X
	int aux, auy;
	cout << " Pi(" << x1 << ", " << y1 << ")   Pf(" << x2 << ", " << y2 << ")\n";
	if (x1 < x2) {  //Mantenemos a x1,y1 lo mas a la izq posible.
		aux = x1;
		auy = y1;
		y1 = y2;
		x1 = x2;
		x2 = aux;
		y2 = auy;
	}

	if (y2 > y1) { // Se invierte la logica de despliegue debido a que la coordenada 0,0 esta en la esquina superior Izq.
		dibujarLinea(x1, y2, x2, y2);
		dibujarLinea(x2, y2, ((x2 - x1) / 2) + x1, y1);
		dibujarLinea(x1, y2, ((x2 - x1) / 2) + x1, y1);
	}
	else {
		dibujarLinea(x1, y1, x2, y1);
		dibujarLinea(x2, y1, ((x2 - x1) / 2) + x1, y2);
		dibujarLinea(x1, y1, ((x2 - x1) / 2) + x1, y2);
	}
}

void dibujarTrianguloLibreBorde(int x1, int y1, int x2, int y2, int x3, int y3) {
	dibujarLinea(x1, y1, x2, y2);
	dibujarLinea(x2, y2, x3, y3);
	dibujarLinea(x3, y3, x1, y1);
}