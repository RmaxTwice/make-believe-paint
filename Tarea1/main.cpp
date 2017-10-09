#include "../headers/glew/glew.h"
#include "../headers/freeglut/freeglut.h"
#include "../headers/AntTweakBar/AntTweakBar.h"
#include "primitivas.cpp"
#include <iostream>

using namespace std;

int gWidth, gHeight, window;
TwBar *myBar;
bool box;
string label;
float color[3];
int xi, yi, xf, yf;
int first = 0;

enum figure
{
	NONE,
	LINEA,
	CUADRILATERO,
	CIRCULO,
	ELIPSE,
	TRIANGULO
} select;

void swapPointsCoord(int &x1, int &y1, int &x2, int &y2) {
	int aux = x1;
	x1 = x2;
	x2 = aux;
	aux = y1;
	y1 = y2;
	y2 = aux;
}

/*
void dibujarLinea(int x1, int y1, int x2, int y2)
{
	glBegin(GL_LINES);
		glVertex3f(x1, y1, 0.0);
		glVertex3f(x2, y2, 0.0);
	glEnd();
}

void dibujarRectangulo(int x1, int y1, int x2, int y2)
{
	glBegin(GL_POLYGON);
		glVertex3f(x1, y1, 0.0);
		glVertex3f(x2, y1, 0.0);
		glVertex3f(x2, y2, 0.0);
		glVertex3f(x1, y2, 0.0);
	glEnd();
}
*/
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 0.0, 0.0);

	dibujarLinea(xi, yi, xf, yf);
	//dibujarRectangulo(xi, yi, xf, yf);

	TwDraw();
	glFlush();
}

void initScene(int x, int y)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glViewport(0, 0, x, y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, x, y, 0.0, 0.0, 1.0);
	TwWindowSize(x, y);
}

void mousePress(int button, int state, int x, int y)
{
	if (TwEventMouseButtonGLUT(button, state, x, y))
		return;

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		cout << "Click" << endl;

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		switch (first)
		{
			case 0:
				xi = x;
				yi = y;
				first = 1;
				break;
			case 1:
				xf = x;
				yf = y;
				first = 0;
				break;
		}
	}
}

void mouseMove(int x, int y)
{
	if (TwEventMouseMotionGLUT(x, y))
		return;
	cout << "Position x: " << x << " Position y: " << y << endl;
}

void keyboard(unsigned char key, int x, int y)
{
	if (TwEventKeyboardGLUT(key, x, y))
		return;

	switch (key)
	{
	case 27:	// Escape key
		glutDestroyWindow(window);
		exit(0);
		break;
	}
}

void TW_CALL action1(void *clientData)
{
	cout << "Dibujando Linea" << endl;
}

void TW_CALL action2(void *clientData)
{
	cout << "Dibujando Rectangulo" << endl;
}

void initGlut(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA OR GLUT_SINGLE | GLUT_RGB
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - gWidth) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - gHeight) / 2);
	glutInitWindowSize(gWidth, gHeight);
	window = glutCreateWindow("Example 1");
	glutReshapeFunc(initScene);
	glutDisplayFunc(display);
	glutMotionFunc(mouseMove);
	glutMouseFunc(mousePress);
	glutKeyboardFunc(keyboard);
}

void initATB()
{
	TwInit(TW_OPENGL, NULL);
	myBar = TwNewBar("Interfaz");

	TwDefine("Interfaz refresh = '0.0001f'");
	TwDefine("Interfaz resizable = false");
	TwDefine("Interfaz fontresizable = false");
	TwDefine("Interfaz movable = true");
	TwDefine("Interfaz visible = true");
	TwDefine("Interfaz position = '5 5'");
	TwDefine("Interfaz size = '200 250'");

	TwEnumVal TypeFEV[] = { { NONE, "Niguno" },{ LINEA, "Linea" },{ CUADRILATERO, "Cudrilatero" },{ CIRCULO, "Circulo" },{ ELIPSE, "Elipse" },{ TRIANGULO, "Triangulo" } };
	TwType TypesF;
	TypesF = TwDefineEnum("comboBox", TypeFEV, 6);
	//TwAddVarRW(myBar, "comboBox", TypesF, &select, NULL);
	TwAddButton(myBar, "button1", action1, NULL, "label = 'Boton 1'");
	TwAddButton(myBar, "button2", action2, NULL, "label = 'Boton 2'");
	//TwAddVarRO(myBar, "label1", TW_TYPE_STDSTRING, &label, "label='label 1'");
	//TwAddVarRW(myBar, "color1", TW_TYPE_COLOR3F, &color[0], "label = 'Color 1'");
	//TwAddVarRW(myBar, "bool1", TW_TYPE_BOOLCPP, &box, "label = 'Booleano 1 '");
}

int main(int argc, char **argv)
{
	gWidth = 800;
	gHeight = 600;
	select = NONE;
	label = "Hola";
	box = true;
	color[0] = color[1] = color[2] = 0.5;
	initGlut(argc, argv);
	initATB();
	glutMainLoop();
	return 0;
}