#include "respaldos.h"


respaldos::respaldos(void)
{//////////CIAMBELLA////////
	translatex=1.5;
	translatey=4.85;
	alturaCM=2.0;
	anchuraCM=1.5;
	profondidadCM=1.5;
//////////POGGIASCHIENA//////
	alturaBS=2.4;
	anchuraBS=0.6;
	profondidadBS=3.5;
	translatexBS=2.0; 
	translateyBS=6.05;

	ciambella=ciambella.openply("perfilCiambella.ply");
	ciambella.barridoAng(ciambella.getVertices(), 8, 270.0, 360.0);

	cilindro=cilindro.openply("perfilCilinder.ply");
	cilindro.barridoST(cilindro.getVertices(), 12);
}

void respaldos::draw(_mode mode){
	draw_ciabella(mode);
	draw_basespalda(mode);
}

void respaldos::draw_ciabella(_mode mode){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslated(translatex,translatey,0);
	glRotated(90,1,0,0);
	glScaled(anchuraCM,alturaCM,profondidadCM);
	ciambella.draw(mode,AZUL);
	glPopMatrix();
}
void respaldos::draw_basespalda(_mode mode){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslated(translatexBS,translateyBS,0);
	glScaled(anchuraBS,alturaBS,profondidadBS);
	cilindro.draw(mode,AZUL);
	glPopMatrix();
}


respaldos::~respaldos(void)
{
}
