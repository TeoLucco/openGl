#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include "Solids.h"
#include "GraficObjects.h"
#include "Gramophone.h"
#include "Can.h"
#include "Globe.h"
#include "imageloader.h"
using namespace std;

// tama�o de los ejes
const int AXIS_SIZE = 5000;

// variables que definen la posici�n de la camara en coordenadas polares
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;

// variables que controlan la ventana y la transformacion de perspectiva
GLfloat Window_width, Window_height, Front_plane, Back_plane;

// variables que determinan la posici�n y tama�o de la ventana X
int UI_window_pos_x = 50, UI_window_pos_y = 50, UI_window_width = 900, UI_window_height = 900;


//********************************************************************************
// Pr�ctica 1
//********************************************************************************
Cube cube = Cube(0.5);
Tetrahedron tetrahedron = Tetrahedron(0.5);

//********************************************************************************
// Pr�ctica 2
//********************************************************************************
Solid_ply solid_ply = Solid_ply("ply/ant", "Ant");
RevolutionSolid profile = RevolutionSolid(30, 0, 360, true, "ply/perfil", "Peon");
RevolutionSolid cylinder = RevolutionSolid(10, 0, 360, false, "ply/cylinder", "Cylinder");
RevolutionSolid bucket = RevolutionSolid(10, 0, 360, false, "ply/bucket", "Bucket");
RevolutionSolid reversed_bucket = RevolutionSolid(10, 0, 360, false, "ply/reversed_bucket", "Reversed Bucket");
RevolutionSolid tube = RevolutionSolid(10, 0, 360, false, "ply/tube", "Tube");
RevolutionSolid cone = RevolutionSolid(10, 0, 360, false, "ply/cone", "Cone");


////********************************************************************************
//// Pr�ctica 3
////********************************************************************************
Sphere sphere = Sphere(30, 0, 360);
Gramophone gramophone = Gramophone(cylinder, tube, bucket, reversed_bucket, cone, cube);
float degreesFreedom1 = 0;
float degreesFreedom2 = -20;
float degreesFreedom3 = 0;
float degreesFreedom4 = 0;
float degreesFreedom5 = 0;
float degreesFreedom6 = 0;


////********************************************************************************
//// Pr�ctica 4
////********************************************************************************
Can can = Can();
RevolutionSolid peon1 = RevolutionSolid(30, 0, 360, true, "ply/perfil", "Peon 1");
RevolutionSolid peon2 = RevolutionSolid(30, 0, 360, true, "ply/perfil", "Peon 2");
RevolutionSolid peon3 = RevolutionSolid(30, 0, 360, true, "ply/perfil", "Peon 3");
Globe globe = Globe();
GLuint textureId;
// Fuentes de luz
// Para cada fuente de luz, se debe guardar: su color Si (una terna RGB),
// su tipo (un valor l�gico que indique si es direccional o posicional), 
// su posici�n (para las fuentes posicionales), y su direcci�n en coordenadas 
// esf�ricas (para las direccionales). Al menos para la fuente dada en 
// coordenadas esf�ericas, se guardar�n asimismo los valores a y b
struct light_parameter {
	GLfloat lightColor[4];
	bool type;
	int position;
	int direction;
	float alpha, beta;
}light_params;

GLfloat lightColor[] = {1.0f, 0.0f, 0.0f, 1.0f};
typedef enum{POSITIONED, DIRECTED} _light_type;
_light_type light_type = POSITIONED;
GLfloat lightPosition[] = {4.0f, 0.0f, 8.0f, 1.0f}; // 1.0 = positioned light source
GLfloat lightDirection[] = {-1.0f, 0.5f, 0.5f, 0.0f}; // coming from this direction, 0.0 = directed light source
float alpha, beta;

// variable que determina qu� objecto se est� mostrando
typedef enum{TETRA, CUBE, SOLID_PLY, SOLID_REV, CYLINDER, BUCKET, 
REV_BUCKET, TUBE, CONE, SPHERE, HIERARCHICAL, CAN, GLOBE} _object_type;
_object_type object = GLOBE;

// modo por defecto
_rendering_mode Mode = SOLID;


//**************************************************************************
//
//***************************************************************************
void clear_window() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}


//**************************************************************************
// Funci�n para definir la transformaci�n de proyecci�n
//***************************************************************************
void change_projection() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// formato(x_minimo, x_maximo, y_minimo, y_maximo, Front_plane, plano_traser)
	//  Front_plane>0  Back_plane>PlanoDelantero)
	glFrustum(-Window_width, Window_width, -Window_height, Window_height, Front_plane, Back_plane);
}

//**************************************************************************
// Funci�n para definir la transformaci�n de vista (posicionar la camara)
//***************************************************************************
void change_observer() {
	// posici�n del observador
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0,0,-Observer_distance);
	glRotatef(Observer_angle_x,1,0,0);
	glRotatef(Observer_angle_y,0,1,0);
}

//**************************************************************************
// Funci�n que dibuja los ejes utilizando la primitiva gr�fica de lineas
//***************************************************************************
void draw_axis() {
	glBegin(GL_LINES);
		// eje X, color rojo
		glColor3f(1, 0, 0);
		glVertex3f(-AXIS_SIZE, 0, 0);
		glVertex3f(AXIS_SIZE, 0, 0);

		// eje Y, color verde
		glColor3f(0,1,0);
		glVertex3f(0,-AXIS_SIZE,0);
		glVertex3f(0,AXIS_SIZE,0);

		// eje Z, color azul
		glColor3f(0, 0, 1);
		glVertex3f(0, 0, -AXIS_SIZE);
		glVertex3f(0, 0, AXIS_SIZE);
	glEnd();
}

////**************************************************************************
//// Funci�n que dibuja el escenario para la pr�ctica 4
////***************************************************************************
//void draw_can_pawns() {
//	glEnable(GL_LIGHTING);
//	// Can
//    glPushMatrix();
//		//glScaled(2,2,2);
//        can.draw(Mode);
//    glPopMatrix();
//
//	// Pawn #1
//    glPushMatrix();
//		glScalef(0.2,0.2,0.2);
//		glTranslatef(0,1.4,3.2);
//		peon1.draw(Mode);
//	glPopMatrix();
//
//	// Pawn #2
//    glPushMatrix();
//		glScalef(0.2,0.2,0.2);
//		glTranslatef(2.2,1.4,3.2);
//		peon2.draw(Mode);
//    glPopMatrix();
//
//	// Pawn #3
//    glPushMatrix();
//		glScalef(0.2,0.2,0.2);
//		glTranslatef(4.4,1.4,3.2);
//        peon3.draw(Mode);
//    glPopMatrix();
//    glDisable(GL_LIGHTING);
//}

//**************************************************************************
// Funci�n para activar las fuentes de luz
//***************************************************************************
void activate_light() {
	//// Add ambient light
	//GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f};
	//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
	// enable lighting
	glEnable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);

	if (light_type == POSITIONED) { 
		//// Add positioned light
		//GLfloat lightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f};
		//GLfloat lightPos0[] = {4.0f, 0.0f, 8.0f, 1.0f}; // 1.0 = positioned light source
		glEnable(GL_LIGHT0);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
		glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	}
	if (light_type == DIRECTED) {
		//// Add directed light
		//GLfloat lightColor1[]= {0.5f, 0.2f, 0.2f, 1.0f};
		//GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f}; // coming from this direction, 0.0 = directed light source
		glEnable(GL_LIGHT1);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor);
		glLightfv(GL_LIGHT1, GL_POSITION, lightDirection);
	}


}

//**************************************************************************
// Funci�n que lee una textura de un fichero
//***************************************************************************
GLuint setTexture(const char *file_name) {
	//glClearColor (0.0, 0.0, 0.0, 0.0);
	//glShadeModel(GL_FLAT);
	//glEnable(GL_DEPTH_TEST);

	Image* image = loadBMP(file_name);
	GLuint textureId;
	// Generate a one unique integer name for creating texture
	// object from bit map image if more than one texture is used,
	// texName will be an array and the will be �n� texture names
	glGenTextures(1, &textureId); // Make room for our texture
	// Create texture object with integer name from glGenTextures () for (re)use later in program
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
	// After binding the object to the texture name we now set the texture parameters
	//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	// parametros de aplicacion de la textura
	//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
				 0,                            //0 for now
				 GL_RGB,                       //Format OpenGL uses for image
				 image->width, image->height,  //Width and height
				 0,                            //The border of the image
				 GL_RGB, //GL_RGB, because pixels are stored in RGB format
				 GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
				                   //as unsigned numbers
				 image->pixels);               //The actual pixel data
	printf("Image width: %d, height: %d\n", image->width, image->height);
	delete image;
	printf("Texture ID: %d\n", textureId);
	return textureId; //Returns the id of the texture
}

//**************************************************************************
// Funci�n que dibuja los objetos
//***************************************************************************
void draw_objects() {

	// Problem: wenn zuerst im Lines-Modus, dann Ilumination -> beleuchtete Lines
	// wenn dann auf solid -> normaler Solid
	if (Mode == IL_FLAT || Mode == IL_SMOOTH) {
		//// enable lighting
		//glEnable(GL_LIGHTING);
		//// enable two lighting sources: light #1 and #2
		//glEnable(GL_LIGHT0);
		//glEnable(GL_LIGHT1);
		//// Automatically normalize normals
		//glEnable(GL_NORMALIZE);
		activate_light();
	}
	else {
		glDisable(GL_LIGHTING);
	}
	switch (object) {
		case CUBE: cube.draw(Mode); break;
		case TETRA: tetrahedron.draw(Mode); break;
		case SOLID_PLY: solid_ply.draw(Mode); break;
		case SOLID_REV: profile.draw(Mode); break;
		case CYLINDER: cylinder.draw(Mode); break;
		case BUCKET: bucket.draw(Mode); break;
		case REV_BUCKET: reversed_bucket.draw(Mode); break;
		case TUBE: tube.draw(Mode); break;
		case CONE: cone.draw(Mode); break;
		case SPHERE: /*lightColor[4] = {0.0f, 0.8f, 0.0f, 1.0f};*/ sphere.draw(Mode); break;
		case HIERARCHICAL: gramophone.draw(Mode, degreesFreedom1, degreesFreedom2, 
							   degreesFreedom3, degreesFreedom4, degreesFreedom5, 
							   degreesFreedom6); break;
		//case CAN: draw_can_pawns(); break;
		case GLOBE: globe.draw(textureId); break;
	}

}

//**************************************************************************
//
//***************************************************************************
void draw_scene() {
	clear_window();
	change_observer();
	draw_axis();
	draw_objects();
	glutSwapBuffers();
}


//***************************************************************************
// Funci�n llamada cuando se produce un cambio en el tama�o de la ventana
//
// el evento manda a la funci�n:
// nuevo ancho
// nuevo alto
//***************************************************************************
void change_window_size(int Ancho1, int Alto1) {
	change_projection();
	glViewport(0, 0, Ancho1, Alto1);
	glutPostRedisplay();
}




//***************************************************************************
// Funci�n llamada cuando se produce aprieta una tecla normal
// La primera fila de letras del teclado (a partir del 'w', 'q' 
// es para terminar) cambia los s�lidos.
// Los n�meros hasta la '5' cambian los modos (en caso del cubo
// hay con la '6' un modo m�s: muestra el margen del cubo).
// el evento manda a la funci�n:
// codigo de la tecla
// posici�n x del rat�n
// posici�n y del rat�n
//***************************************************************************
void normal_keys(unsigned char Tecla1, int x, int y) {
	switch (Tecla1) {
		case 'q': exit(0); break;

		// Los objectos 
		case '1': object = SOLID_PLY; break;
		case '2': object = SOLID_REV; break;
		case '3': object = HIERARCHICAL; break;
		case '4': object = GLOBE; break;
		//case '1': object = CUBE; break; 
		//case '2': object = TETRA; break;
		//case '3': object = SOLID_PLY; break;
		//case '4': object = CYLINDER; break;
		case '5': object = BUCKET; break;
		case '6': object = REV_BUCKET; break;
		case '7': object = TUBE; break;
		case '8': object = CONE; break;
		case '9': object = SPHERE; break;
		case '0': object = GLOBE; break;


		// Movimiento
		// 1. Grado de Libertad: el gram�fono entero
		case 'z': degreesFreedom5 += 0.1; break;	
		case 'Z': degreesFreedom5 -= 0.1; break;
		
		// 2. Grado de Libertad: la trompeta con elemento de fijaci�n
		case 'x': degreesFreedom4 >= 0.25 ? degreesFreedom4 = 0.25 : degreesFreedom4 += 0.05; break;
		case 'X': degreesFreedom4 < 0.05 ? degreesFreedom4 = 0 : degreesFreedom4 -= 0.05; break;
		// 2. Grado de Libertad: brazo
		case 'v': degreesFreedom2 >= 0 ? degreesFreedom2 = 0 : degreesFreedom2 += 2; break;								
		case 'V': degreesFreedom2 <= -20 ? degreesFreedom2 = -20 : degreesFreedom2 -= 2; break;
		// 2. Grado de Libertad: el carrete
		case 'b': degreesFreedom1 -= 5; break;	
		case 'B': degreesFreedom1 += 5; break;
		// 2. Grado de Libertad: el disco
		case 'n': degreesFreedom3 -= 2; break;	
		case 'N': degreesFreedom3 -= 2; break;		
			
		// 3. Grado de Libertad: la trompeta sola
		case 'c': degreesFreedom6 >= 10 ? degreesFreedom6 = 10 : degreesFreedom6 += 5; break;
		case 'C': degreesFreedom6 <= -60 ? degreesFreedom6 = -60 : degreesFreedom6 -= 5; break;

					
		// Los modos
		case 'p': Mode = VERTICES; break; // puntos
		case 'l': Mode = EDGES; break; // l�neas
		case 's': Mode = SOLID; break; // s�lido
		case 'a': Mode = CHESS; break; // ajedrez
		case 't': Mode = ALL; break; // todo
		case 'i': Mode = IL_FLAT; break; // iluminaci�n y sombreado plano
		case 'I': Mode = IL_SMOOTH; break; // iluminaci�n y sombreado suave
		case 'o': Mode = NORMALS_TRI; break;
		case 'O': Mode = NORMALS_VERT; break;
	}
	glutPostRedisplay();

}

//***************************************************************************
// Funci�n llamada cuando se produce aprieta una tecla especial
//
// el evento manda a la funci�n:
// codigo de la tecla
// posici�n x del rat�n
// posici�n y del rat�n

//***************************************************************************
void special_keys(int Tecla1, int x, int y) {
	switch (Tecla1) {
		case GLUT_KEY_LEFT:Observer_angle_y--; break;
		case GLUT_KEY_RIGHT:Observer_angle_y++; break;
		case GLUT_KEY_UP:Observer_angle_x--; break;
		case GLUT_KEY_DOWN:Observer_angle_x++; break;
		case GLUT_KEY_PAGE_UP:Observer_distance*=1.2; break;
		case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2; break;
		}
	glutPostRedisplay();
}



//***************************************************************************
// Funci�n de incializaci�n
//***************************************************************************
void initialize() {
	// se inicalizan la ventana y los planos de corte
	Window_width = 0.5;
	Window_height = 0.5;
	Front_plane = 1;
	Back_plane = 1000;

	// se inicia la posici�n del observador, en el eje z
	Observer_distance = 2*Front_plane;
	Observer_angle_x = 0;
	Observer_angle_y = 0;

	// se indica cu�l ser� el color para limpiar la ventana	(r,v,a,al)
	glClearColor(1, 1, 1, 1);

	// se habilita el z-bufer
	glEnable(GL_DEPTH_TEST);


	// load textura
	textureId = setTexture("textures/dia_8192.bmp");

	//
	change_projection();

	//
	glViewport(0, 0, UI_window_width, UI_window_height);
}



//***************************************************************************
// Programa principal
//
// Se encarga de iniciar la ventana, asignar las funciones e comenzar el
// bucle de eventos
//***************************************************************************
int main(int argc, char **argv) {
	// se llama a la inicializaci�n de glut
	glutInit(&argc, argv);

	// se indica las caracter�sticas que se desean para la visualizaci�n con OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

	// posici�n de la esquina inferior izquierdad de la ventana
	glutInitWindowPosition(UI_window_pos_x, UI_window_pos_y);

	// tama�o de la ventana (ancho y alto)
	glutInitWindowSize(UI_window_width, UI_window_height);

	// llamada para crear la ventana, indicando el titulo (no se visualiza hasta que se llama
	// al bucle de eventos)
	glutCreateWindow("Pr�ctica 3");

	// asignaci�n de la funci�n llamada "dibujar" al evento de dibujo
	glutDisplayFunc(draw_scene);

	// asignaci�n de la funci�n llamada "cambiar_tamanio_ventana" al evento correspondiente
	glutReshapeFunc(change_window_size);
	
	// asignaci�n de la funci�n llamada "tecla_normal" al evento correspondiente
	glutKeyboardFunc(normal_keys);
	// asignaci�n de la funci�n llamada "tecla_Especial" al evento correspondiente
	glutSpecialFunc(special_keys);

	// texturas
	

	// funci�n de inicializaci�n
	initialize();


	// inicio del bucle de eventos
	glutMainLoop();
	return 0;
}