#include "brazos.h"
#include "O3DC.h"
#include <GL/gl.h>

brazos::brazos(void)
{	posZ=1.9;
	anchura=0.7;
/////quadratoArriba///
	alturaA=3.0;
	profondidadA=0.2;
	posXA=0.0;
	posYA=5.5;
/////quadratoaBajo///
	alturaB=1.0;
	profondidadB=0.2;
	posXB=0.0;
	posYB=4.2;
/////quadratoaDelante///
	alturaD=0.2;
	profondidadD=1.9;
	posXD=-1.0;
	posYD=4.85;
	anguloD=-40.0;
/////quadratoDEtras///
	alturaDE=0.2;
	profondidadDE=1.9;
	posXDE=1.0;
	posYDE=4.85;
}

void brazos::draw_brazo(_mode mode){
	
	draw_quadratoArriba(mode);
	draw_quadratoaBajo(mode);
	draw_quadratoaDelante(mode);
	draw_quadratoaDEtras(mode);

}

void brazos::draw_quadratoArriba(_mode mode){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslated(posXA,posYA,posZ);
	glRotated(90,0,0,1);
	glRotated(90,0,1,0);
	glScaled(anchura,alturaA,profondidadA);
	cubo.draw(mode,NEGRO);
	glPopMatrix();
}

void brazos::draw_quadratoaBajo(_mode mode){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslated(posXB,posYB,posZ);
	glRotated(90,0,0,1);
	glRotated(90,0,1,0);
	glScaled(anchura,alturaB,profondidadB);
	cubo.draw(mode,NEGRO);
	glPopMatrix();
}

void brazos::draw_quadratoaDelante(_mode mode){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslated(posXD,posYD,posZ);
	glRotated(90,0,0,1);
	glRotated(90,0,1,0);
	glRotated(anguloD,1,0,0);
	glScaled(anchura,alturaD,profondidadD);
	glRotated(5,1,0,0);
	cubo.draw(mode,NEGRO);
	glPopMatrix();
}

void brazos::draw_quadratoaDEtras(_mode mode){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslated(posXDE,posYDE,posZ);
	glRotated(90,0,0,1);
	glRotated(90,0,1,0);
	glRotated(-anguloD,1,0,0);
	glScaled(anchura,alturaDE,profondidadDE);
	glRotated(-5,1,0,0);
	cubo.draw(mode,NEGRO);
	glPopMatrix();
}

brazos::~brazos(void)
{
}
