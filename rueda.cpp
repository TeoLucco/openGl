#include "rueda.h"
#include "O3DC.h"
#include "file_ply_stl.h"
#include <GL/gl.h>
#include <math.h>
#define PI (3.141592653589793)


rueda::rueda(void)
{
	altura=0.45;
	anchura=0.45;
	profondidad=0.45;
	raggio=2.75;
	
	
	pos_yCR=0.1;
	alturaCR=0.55;
	anchuraCR=0.5;
	profondidadCR=0.5;




	copriruota=copriruota.openply("perfilCiambella.ply");
	copriruota.barridoAng(copriruota.getVertices(), 8, 270.0, 450.0);

	cilinde=cilinde.openply("perfilCilinder.ply");
	cilinde.barridoST(cilinde.getVertices(), 12);

}



void rueda::draw(_mode mode,GLfloat Observer_angle_x){
	double radianti=reduceDegree(Observer_angle_x);
	angle = (2.0*PI) / 5;
	double anglepart=angle;
	for(int i=0;i<5;i++){
		double pos_x=raggio*cos(anglepart);
		double pos_z=raggio*sin(anglepart);
		glMatrixMode(GL_MODELVIEW);
		///////////RUEDA//////////
		glPushMatrix();
		glTranslated(pos_x,0,pos_z);

		switch (estado){
		case VERTICAL:
		glRotated(90,0,1,0);
		break;
		case VERTICALOBL:
		glRotated(-radianti,0,1,0);
		break;
		case HORIZONTALOBL:
		glRotated(-radianti+90,0,1,0);
		break;
		}		
		glRotated(90,0,0,1);
		glScaled(altura,anchura,profondidad);
		cilinde.draw(mode,NEGRO);
		glPopMatrix();
		/////////////COBRERUEDA////////////
		glPushMatrix();
		glTranslated(pos_x,pos_yCR,pos_z);
		switch (estado){
		case VERTICAL:
		glRotated(90,0,1,0);
		break;
		case VERTICALOBL:
		glRotated(-radianti,0,1,0);
		break;
		case HORIZONTALOBL:
		glRotated(-radianti+90,0,1,0);
		break;
		}		
		
		glRotated(90,0,0,1);
		glScaled(alturaCR,anchuraCR,profondidadCR);
		copriruota.draw(mode,NEGROCLARO);
		glPopMatrix();

		anglepart=anglepart+angle;
	}
}


double rueda::reduceDegree(GLfloat Observer_angle_x){
	if (Observer_angle_x>=0){
		while(Observer_angle_x>360)
		Observer_angle_x=Observer_angle_x-360;
	}
	else{
		while(Observer_angle_x<-360)
		Observer_angle_x=Observer_angle_x+360;
	}
	return Observer_angle_x;
}

rueda::~rueda(void)
{
}
