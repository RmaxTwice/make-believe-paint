#pragma once
#ifndef PRIMITIVAS_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define PRIMITIVAS_H

#include "../headers/glew/glew.h"
#include "../headers/freeglut/freeglut.h"

#include <iostream>

inline void dibujarPunto(int, int);
inline void dibujar8Puntos(int, int, int, int);
inline void dibujar4puntos(int, int, int, int);
inline void dibujarLinea(int, int, int, int);
inline void dibujarRectanguloBorde(int, int, int, int);
inline void dibujarRectanguloRelleno(int, int, int, int);
inline void dibujarCirculoBorde(int, int, int);
inline void setElipse(int, int, int, int);
inline void dibujarElipseBordeH(int, int, int, int);
inline void dibujarTrianguloBoxBorde(int, int, int, int);
//inline void dibujarTrianguloLibreBorde(int, int, int, int, int, int);


class Primitiva {
protected:
	// Primero los 2 puntos opuestos de la diagonal de la bounding box de la figura.
	int minX, minY;
	int maxX, maxY;
	// La posición en Z para saber que figuras se superponen a otras.
	int posZ;

public:
	//inline Primitive(int minX, int minY, int maxX, int maxY , int Z);

	inline void setBoundingBox(int x0, int y0, int x1, int y1, int Z);

	virtual void paint(void) = 0;
};

class Linea : public Primitiva {
public:
	inline void paint();
};

class Cuadrilatero : public Primitiva {
public:
	inline void paint();
};

/*class Circulo : public Primitiva {
	int centerX, centerY, radius;
public:
	inline Circulo(int cx, int cy, int r);
	//inline void initCirculo(int cx, int cy, int r);
	inline void paint();
};*/
#endif