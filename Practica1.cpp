//**************************************************************************
// Práctica 1
//
// Domingo Martin Perandres 2013-2016
//
// GPL
//**************************************************************************

#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include <math.h>
#include "O3DC.h"
#include "Tetraedo.h"
#include "Cubo.h"
#include "file_ply_stl.h"
#include "Silla.h"
#include <gli/texture.hpp>
#include <gli/load.hpp>
#include <gli/save.hpp>
#include <gli/gl.hpp>
#include "luzMovil.h"
#include "camara0.h"
#include "malla.h"
typedef enum{CUBO,TETRAEDO,POLYGON,ALFIERE,CILINDER,TUBO,VASO,VASOREV,CONO,SILLA,ESFERA,MALLA} _type;_type type=ESFERA;_mode mode;
_normalMode nMode=VERT;
_color color=AZUL;
_material material=MATE1;
luzMovil luzmovil;
Image* textura;
Image* textura2;
GLfloat Luz1[4]={25,-8,0,0};
malla malla1(5);


double radio=25;
double angle=0;
double posx=25;
double posy=-8;
double posz=0;


bool luz0=false;
bool luz1=false;
bool text=false;


bool camara=true;


int yant=0, xant=0;
bool pulsado_der=false, 
	pulsado_izq=false;

Cubo cube;
Silla silla;
luzMovil luz;
O3DC esfera("perfilEsfera.ply");
camara0 camera0;

// tamaño de los ejes
const int AXIS_SIZE=5000;

// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;

// variables que controlan la ventana y la transformacion de perspectiva
GLfloat Window_width,Window_height,Front_plane,Back_plane;

// variables que determninan la posicion y tamaño de la ventana X
int UI_window_pos_x=50,UI_window_pos_y=50,UI_window_width=500,UI_window_height=500;


const GLfloat ratio = GLfloat(UI_window_height) / GLfloat(UI_window_width);


void clear_window()
{

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}

void mover_dx(){
	
	
	angle=angle+0.2;
	posx=radio*cos(angle);
	posz=radio*sin(angle);
	Luz1[0]=posx;
	Luz1[1]=posy;
	Luz1[2]=posz;


}



//**************************************************************************
// Funcion para definir la transformación de proyeccion
//***************************************************************************

void change_projection()
{
	

	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	/*switch(camara){
		case true: glFrustum(-Window_width,Window_width,-Window_height*ratio,Window_height*ratio,Front_plane,Back_plane);
		case false:glOrtho(-Window_width,Window_width,-Window_height*ratio,Window_height*ratio,Front_plane,Back_plane);
	}*/
	

//camera0.switch_projection(-Window_width,Window_width,-Window_height*ratio,Window_height*ratio,Front_plane,Back_plane,camara);


	if(camara==true){
		
		glFrustum(-Window_width,Window_width,-Window_height*ratio,Window_height*ratio,Front_plane,Back_plane);
	}else if(camara==false){
		
		glOrtho(-Window_width,Window_width,-Window_height*ratio,Window_height*ratio,Front_plane,Back_plane);

	}

// formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
//  Front_plane>0  Back_plane>PlanoDelantero)

}

//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************

void change_observer()
{

// posicion del observador
glMatrixMode(GL_MODELVIEW);
if(camara==true){
glLoadIdentity();
glTranslatef(0,0,-Observer_distance);
glRotatef(Observer_angle_x,1,0,0);
glRotatef(Observer_angle_y,0,1,0);
}else{
glLoadIdentity();
glRotatef(90,1,0,0);
glTranslatef(0,-20*Observer_distance,0);
glRotatef(Observer_angle_x,1,0,0);
glRotatef(-Observer_angle_y,0,0,1);

}
}

//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void draw_axis()
{
glDisable(GL_LIGHTING);
glBegin(GL_LINES);
// eje X, color rojo
glColor3f(1,0,0);
glVertex3f(-AXIS_SIZE,0,0);
glVertex3f(AXIS_SIZE,0,0);
// eje Y, color verde
glColor3f(0,1,0);
glVertex3f(0,-AXIS_SIZE,0);
glVertex3f(0,AXIS_SIZE,0);
// eje Z, color azul
glColor3f(0,0,1);
glVertex3f(0,0,-AXIS_SIZE);
glVertex3f(0,0,AXIS_SIZE);
glEnd();
glEnable(GL_LIGHTING);
}


//**************************************************************************
// Funcion que dibuja los objetos
//***************************************************************************


void draw_objects()
{

	

	switch(type){
	/*case MALLA:malla1.draw(EDGES);malla1.aplicatex(5,10,2,4,textura2);break;*/
	case ESFERA:
		if(text==true){
			esfera.drawluz(mode,nMode,luz0,luz1,material,textura,Luz1);
			if(luz0==false && luz1==true){
				glMatrixMode(GL_MODELVIEW);
				glPushMatrix();
				glScaled(0.25,0.25,0.25);
				glTranslated(-posx,-posy,-posz);
				esfera.draw(SOLID,AMARILLO);
				glPopMatrix();
				glPushMatrix();
				glScaled(5,5,5);
				esfera.drawsky(nMode,textura2,Luz1);
				glPopMatrix();
			}
		}else{
			esfera.drawluznotext(mode,nMode,luz0,luz1,material,Luz1);
			if(luz0==false && luz1==true){
				glMatrixMode(GL_MODELVIEW);
				glPushMatrix();
				glScaled(0.25,0.25,0.25);
				glTranslated(-posx,-posy,-posz);
				esfera.draw(SOLID,AMARILLO);
				glPopMatrix();
			}
		}
		break;	
	case CUBO: 
		cube.draw(mode);
		break;
		}
}

//**************************************************************************
//
//***************************************************************************



void draw_scene(void)
{

clear_window();
change_observer();
draw_axis();
draw_objects();
glutSwapBuffers();
}

//***************************************************************************
// Funcion llamada cuando se produce un cambio en el tamaño de la ventana
//
// el evento manda a la funcion:
// nuevo ancho
// nuevo alto
//***************************************************************************

void change_window_size(int Ancho1,int Alto1)
{
	UI_window_width = Ancho1;
	UI_window_height = Alto1;

change_projection();
glViewport(0,0,Ancho1,Alto1);
glutPostRedisplay();
}


void moveMouse(int x, int y){


  if(pulsado_izq){
      Observer_angle_y=x+xant;
      Observer_angle_x=y+yant;
      yant= y;
      xant=x;
  }

glutPostRedisplay();
}



void mouseClick( int button, int state, int x, int y ){

	switch(button){
		case GLUT_LEFT_BUTTON:if(state==GLUT_DOWN) pulsado_izq=true;break;
		case GLUT_RIGHT_BUTTON:if(state==GLUT_DOWN) Observer_distance/=1.2; break;
		case GLUT_MIDDLE_BUTTON:if(state==GLUT_DOWN) Observer_distance*=1.2; break;

	}
	glutPostRedisplay();
}





//***************************************************************************
// Funcion de incializacion
//***************************************************************************

void initialize(void){
// se inicalizan la ventana y los planos de corte
Window_width=1;
Window_height=1;
Front_plane=1;
Back_plane=1000;


// se inicia la posicion del observador, en el eje z
Observer_distance=10*Front_plane;
Observer_angle_x=0;
Observer_angle_y=0;

// se indica cual sera el color para limpiar la ventana	(r,v,a,al)
// blanco=(1,1,1,1) rojo=(1,0,0,1), ...
glClearColor(1,1,1,1);

// se habilita el z-bufer
glEnable(GL_DEPTH_TEST);
//

change_projection();
//
glViewport(0,0,UI_window_width,UI_window_height);
}


//***************************************************************************
// Programa principal
//
// Se encarga de iniciar la ventana, asignar las funciones e comenzar el
// bucle de eventos
//***************************************************************************



void special_keys(int Tecla1,int x,int y){
	if(camara==true){
		switch (Tecla1){
			case GLUT_KEY_LEFT:Observer_angle_y--;break;
			case GLUT_KEY_RIGHT:Observer_angle_y++;break;
			case GLUT_KEY_UP:Observer_angle_x--;break;
			case GLUT_KEY_DOWN:Observer_angle_x++;break;
			case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;
			case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;
		}
	}else{
		switch (Tecla1){
			case GLUT_KEY_LEFT:Observer_angle_y--;break;
			case GLUT_KEY_RIGHT:Observer_angle_y++;break;
			case GLUT_KEY_UP:Observer_angle_x--;break;
			case GLUT_KEY_DOWN:Observer_angle_x++;break;
			case GLUT_KEY_PAGE_UP:
				
				glMatrixMode(GL_PROJECTION);
				
				glOrtho(-Window_width*1.2,Window_width*1.2,-Window_height*ratio*1.2,Window_height*ratio*1.2,Front_plane,Back_plane);
				
				break;
			case GLUT_KEY_PAGE_DOWN:
				glMatrixMode(GL_PROJECTION);
				
				glOrtho(-Window_width*0.8,Window_width*0.8,-Window_height*ratio*0.8,Window_height*ratio*0.8,Front_plane,Back_plane);
				break;
		}
	}
	glutPostRedisplay();
}


void normal_keys(unsigned char Tecla1,int x,int y)
{

	switch (toupper(Tecla1)){
	
	case 'Q': exit(0);break;
	case '9': nMode=VERT; break;
	case '0': nMode=CARAS;break;
	case 'A': luz0=false;luz1=true;printf("LUZ1 ENCENDIDA");break;
	case 'S': luz0=true;luz1=false;printf("LUZ0 ENCENDIDA");break;
	case 'D': luz0=false;luz1=false;printf("LUZ pagadas");break;
	case 'L': material=MATE1;printf("MATERIAL1");break;
	case 'K': material=MATE2;printf("MATERIAL2");break;
	case 'J': material=MATE3;printf("MATERIAL3");break;
	case 'M': mover_dx();break;
	case 'T': if(text==true)text=false;else text=true;break;
	case 'C': if(camara==true){camara=false;change_projection();}else{ camara=true;change_projection();}break;
	case 'Z': type=CUBO;break;
	case 'X': type=ESFERA;break;
	case 'B': type=MALLA;break;


/*	case 'd': silla.mover_sx(); break;

	case 'g': silla.mover_down(Observer_angle_y);break;
	case 'f': silla.mover_sx(Observer_angle_y); break;
	case 't': silla.mover_up(Observer_angle_y);break;
	case 'h': silla.mover_dx(Observer_angle_y); break;
	
	case 'z': type=SILLA;break;
	case 'o': silla.alzar_silla();break;
	case 'p': silla.bajar_silla();break;
	case 'k': silla.ruodar_reloj();break;
	case 'l': silla.ruodar_antireloj();break;
	case 'n': luz.mover_dx();break;
	case 'm': luz.mover_sx();break;
	
	*/
	case '1': mode=VERTICES;break;
	case '2': mode=EDGES;break;
	case '3': mode=SOLID;break;
	case '4': mode=CHESS;break;
	case '5': mode=ALL;break;
	
	}

	glutPostRedisplay();
}


int main(int argc, char **argv)
{
	esfera.barridoST(esfera.getVertices(), 24);
	textura=esfera.init_textura();
	textura2=esfera.init_textura_temp();
	
	
	
	
	
/*	
	tubo.barridoAng(tubo.getVertices(), 8, 45.0, 180.0);
	cilinder.barridoAng(cilinder.getVertices(), 8, 45.0, 180.0);
	vaso.barridoAng(vaso.getVertices(), 8, 45.0, 180.0);
	vasoRev.barridoAng(vasoRev.getVertices(), 8, 45.0, 180.0);
	cono.barridoAng(cono.getVertices(), 8, 45.0, 180.0);
*/

// se llama a la inicialización de glut
glutInit(&argc, argv);


// se indica las caracteristicas que se desean para la visualización con OpenGL
// Las posibilidades son:
// GLUT_SIMPLE -> memoria de imagen simple
// GLUT_DOUBLE -> memoria de imagen doble
// GLUT_INDEX -> memoria de imagen con color indizado
// GLUT_RGB -> memoria de imagen con componentes rojo, verde y azul para cada pixel
// GLUT_RGBA -> memoria de imagen con componentes rojo, verde, azul y alfa para cada pixel
// GLUT_DEPTH -> memoria de profundidad o z-bufer
// GLUT_STENCIL -> memoria de estarcido
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

// posicion de la esquina inferior izquierdad de la ventana
glutInitWindowPosition(UI_window_pos_x,UI_window_pos_y);

// tamaño de la ventana (ancho y alto)
glutInitWindowSize(UI_window_width,UI_window_height);

// llamada para crear la ventana, indicando el titulo (no se visualiza hasta que se llama
// al bucle de eventos)
glutCreateWindow("Práctica 1");

// asignación de la funcion llamada "dibujar" al evento de dibujo
glutDisplayFunc(draw_scene);
// asignación de la funcion llamada "cambiar_tamanio_ventana" al evento correspondiente
glutReshapeFunc(change_window_size);
// asignación de la funcion llamada "tecla_normal" al evento correspondiente
glutKeyboardFunc(normal_keys);
// asignación de la funcion llamada "tecla_Especial" al evento correspondiente
glutSpecialFunc(special_keys);



glutMouseFunc(mouseClick);
glutMotionFunc(moveMouse);

// funcion de inicialización
initialize();

printf("Teclas:\n'Q': exit\n\n'1':vertices\n'2':lineas profile\n'3':solido\n'4':aldejerez\n'5':all\n\n'9':smooth\n'0':flat\n\n'D':sin luz\n'S':luz0\n'A':luz1\n'M':Mover luz1\n\n'L':material 1\n'K':material 2\n'J':material 3\n\n'T':aplicar/remover textura\n'C':cambio camara\n'Z':cubo\n'X':esfera\n\n");
//
//
//	case 'Q': exit(0);break;
//	case '9': nMode=VERT; break;
//	case '0': nMode=CARAS;break;
//	case 'A': luz0=false;luz1=true;printf("LUZ1 ENCENDIDA");break;
//	case 'S': luz0=true;luz1=false;printf("LUZ0 ENCENDIDA");break;
//	case 'D': luz0=false;luz1=false;printf("LUZ apagadas");break;
//	case 'L': material=MATE1;printf("MATERIAL1");break;
//	case 'K': material=MATE2;printf("MATERIAL2");break;
//	case 'J': material=MATE3;printf("MATERIAL3");break;
//	case 'M': mover_dx();break;
//	case 'T': if(text==true)text=false;else text=true;break;
//	case 'C': if(camara==true){camara=false;change_projection();}else{ camara=true;change_projection();}break;
//	case 'Z': type=CUBO;break;
//	case 'X': type=ESFERA;break;
//	case 'B': type=MALLA;break;
//
//
///*	case 'd': silla.mover_sx(); break;
//
//	case 'g': silla.mover_down(Observer_angle_y);break;
//	case 'f': silla.mover_sx(Observer_angle_y); break;
//	case 't': silla.mover_up(Observer_angle_y);break;
//	case 'h': silla.mover_dx(Observer_angle_y); break;
//	
//	case 'z': type=SILLA;break;
//	case 'o': silla.alzar_silla();break;
//	case 'p': silla.bajar_silla();break;
//	case 'k': silla.ruodar_reloj();break;
//	case 'l': silla.ruodar_antireloj();break;
//	case 'n': luz.mover_dx();break;
//	case 'm': luz.mover_sx();break;
//	
//	*/
//	case '1': mode=VERTICES;break;
//	case '2': mode=EDGES;break;
//	case '3': mode=SOLID;break;
//	case '4': mode=CHESS;break;
//	case '5': mode=ALL;break;
//
//



// inicio del bucle de eventos
glutMainLoop();

return 0;
}