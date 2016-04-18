#include "baseAlta.h"
#include "O3DC.h"
#include "file_ply_stl.h"
#include <GL/gl.h>
#include <math.h>
#define PI (3.141592653589793)

baseAlta::baseAlta(void)
{/////CILINDRO CENTRALE//////
	alturaCC=2.5;
	anchuraCC=0.55;
	profondidadCC=0.55;
	altezzaCC=2.85;
////////VASO///////////
	alturaVaso=0.5;
	anchuraVaso=0.8;
	profondidadVaso=0.8;
	altezzaVaso=3.8;
//////////BARRA/////////
	alturaB=1.2;
	anchuraB=0.2;
	profondidadB=0.2;
	translatexB=0.0;
	translateyB=3.7;
	translatezB=1.0;
	angleB=75;
///////CILINDRO BAJO(poggiaculo)/////////
	alturaCB=3.0;
	anchuraCB=0.6;
	profondidadCB=3.5;
	altezzaCB=4.3;
	translateCB=0.0;
//////beethoven//////
	alturaBe=0.3;
	anchuraBe=0.3;
	profondidadBe=0.3;
	yBe=6;

	
	cilindro=cilindro.openply("perfilCilinder.ply");
	cilindro.barridoST(cilindro.getVertices(), 12);

	

	vaso=vaso.openply("perfilVaso.ply");
	vaso.barridoST(vaso.getVertices(),12);

	beethoven=beethoven.openply("beethoven.ply");
	

}
void baseAlta::draw_baseAlta(_mode mode){
draw_barra(mode);
draw_vaso(mode);
draw_basebaja(mode);
draw_cilindro_central(mode);
draw_beethoven(mode);
}


void baseAlta::draw_beethoven(_mode mode){
	
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslated(0,yBe,0);
	glRotated(-90,0,1,0);
	glScaled(anchuraBe,alturaBe,profondidadBe);
	beethoven.draw(mode,GRIS);
	//beethoven.draw(EDGES,NEGRO);
	glPopMatrix();
}

void baseAlta::draw_barra(_mode mode){
	
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glTranslated(translatexB,translateyB,translatezB);
		glRotated(-angleB,1,0,0);
		glScaled(anchuraB,alturaB,profondidadB);
		cilindro.draw(mode,GRIS);
		glPopMatrix();
}
void baseAlta::draw_vaso(_mode mode){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslated(0,altezzaVaso,0);
	glScaled(anchuraVaso,alturaVaso,profondidadVaso);
	vaso.draw(mode,NEGRO);
	glPopMatrix();
}

void baseAlta::draw_basebaja(_mode mode){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslated(translateCB,altezzaCB,0);
	glRotated(90,0,0,1);
	glScaled(anchuraCB,alturaCB,profondidadCB);
	cilindro.draw(mode,AZUL);
	glPopMatrix();
}
void baseAlta::draw_cilindro_central(_mode mode){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslated(0,altezzaCC,0);
	glScaled(anchuraCC,alturaCC,profondidadCC);
	cilindro.draw(mode,GRIS);
	glPopMatrix();
}

baseAlta::~baseAlta(void)
{
}


