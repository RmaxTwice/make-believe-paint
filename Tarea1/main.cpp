#include "../headers/glew/glew.h"
#include "../headers/freeglut/freeglut.h"
#include "../headers/AntTweakBar/AntTweakBar.h"
#include <iostream>

using namespace std;

int gWidth, gHeight, window;
//TwBar *sceneInterface;
bool box;
string label;
float color[3];

enum figure
{
	NONE,
	LINEA,
	CUADRILATERO,
	CIRCULO,
	ELIPSE,
	TRIANGULO
} select;

void paint()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
		glVertex3f(0.25, 0.25, 0.0);
		glVertex3f(0.75, 0.25, 0.0);
		glVertex3f(0.75, 0.75, 0.0);
		glVertex3f(0.25, 0.75, 0.0);
	glEnd();
	//TwDraw();
	glFlush();
}

void initScene(int x, int y)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glViewport(0, 0, x, y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
	//TwWindowSize(x, y);
}

void mousePress(int button, int state, int x, int y)
{
	if (TwEventMouseButtonGLUT(button, state, x, y))
		return;
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN)
			cout << "Click" << endl;
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
	cout << "Presionaste el boton" << endl;
}

void initGlut(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA OR GLUT_SINGLE | GLUT_RGB
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - gWidth) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - gHeight) / 2);
	glutInitWindowSize(gWidth, gHeight);
	window = glutCreateWindow("Example 1");
	glutReshapeFunc(initScene);
	glutDisplayFunc(paint);
	glutMotionFunc(mouseMove);
	glutMouseFunc(mousePress);
	glutKeyboardFunc(keyboard);
}
/*
void initATB()
{
	TwInit(TW_OPENGL, NULL);
	sceneInterface = TwNewBar("Interfaz");

	TwDefine("Interfaz refresh = '0.0001f'");
	TwDefine("Interfaz resizable = false");
	TwDefine("Interfaz fontresizable = false");
	TwDefine("Interfaz movable = true");
	TwDefine("Interfaz visible = true");
	TwDefine("Interfaz position = '20 20'");
	TwDefine("Interfaz size = '220 320'");

	TwEnumVal TypeFEV[] = { { NONE, "Niguno" },{ LINEA, "Linea" },{ CUADRILATERO, "Cudrilatero" },{ CIRCULO, "Circulo" },{ ELIPSE, "Elipse" },{ TRIANGULO, "Triangulo" } };
	TwType TypesF;
	TypesF = TwDefineEnum("comboBox", TypeFEV, 6);
	TwAddVarRW(sceneInterface, "comboBox", TypesF, &select, NULL);
	TwAddButton(sceneInterface, "button1", action1, NULL, "label = 'Boton 1'");
	TwAddVarRO(sceneInterface, "label1", TW_TYPE_STDSTRING, &label, "label='label 1'");
	TwAddVarRW(sceneInterface, "color1", TW_TYPE_COLOR3F, &color[0], "label = 'Color 1'");
	TwAddVarRW(sceneInterface, "bool1", TW_TYPE_BOOLCPP, &box, "label = 'Booleano 1 '");
}
*/
int main(int argc, char **argv)
{
	gWidth = 800;
	gHeight = 600;
	select = NONE;
	label = "Hola";
	box = true;
	color[0] = color[1] = color[2] = 0.5;
	initGlut(argc, argv);
	//initATB();
	glutMainLoop();
	return 0;
}