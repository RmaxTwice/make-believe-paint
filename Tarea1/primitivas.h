#pragma once
#ifndef PRIMITIVAS_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define PRIMITIVAS_H

#include "../headers/glew/glew.h"
#include "../headers/freeglut/freeglut.h"

#include <iostream>

inline void dibujarPunto(int, int);
inline void dibujar8Puntos(int, int, int, int);
inline void dibujarLinea(int, int, int, int);
inline void dibujarRectanguloBorde(int, int, int, int);
inline void dibujarRectanguloRelleno(int, int, int, int);
inline void dibujarCirculoBorde(int, int, int);
inline void dibujarTrianguloBoxBorde(int, int, int, int);
inline void dibujarTrianguloLibreBorde(int, int, int, int, int, int);
#endif