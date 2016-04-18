#include "base.h"
#include "O3DC.h"
#include "file_ply_stl.h"
#include <GL/gl.h>
#include <math.h>
#define PI (3.141592653589793)

base::base(void)
{
	altura=3.0;
	anchura=0.5;
	profondidad=0.5;
	altezza=0.85;
	anglepiernas=98;
	radio=1.3;
	
	alturaCC=1.8;
	anchuraCC=0.6;
	profondidadCC=0.6;
	altezzaCC=2.2;
	
	cilinde=cilinde.openply("perfilCilinder.ply");
	cilinde.barridoST(cilinde.getVertices(), 12);
	tubo=tubo.openply("perfilTubo.ply");
	tubo.barridoST(tubo.getVertices(), 12);
	

}
void base::draw_base(_mode mode){
	
	angle = (2.0*PI) / 5;
	double anglepart=angle;
	double angleconv;
	for(int i=0;i<5;i++){
		double pos_x=radio*cos(anglepart);
		double pos_z=radio*sin(anglepart);
		glPushMatrix();
		glTranslated(pos_x,altezza,pos_z);
		angleconv=(anglepart*180)/PI;
		glRotated(-angleconv,0,1,0);
		glRotated(-anglepiernas,0,0,1);
		glScaled(anchura,altura,profondidad);
		cilinde.draw(mode, NEGRO);
		glPopMatrix();
		anglepart=anglepart+angle;
	}
	draw_cilindro_central(mode);
}

void base::draw_cilindro_central(_mode mode){
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glTranslated(0,altezzaCC,0);
		glScaled(anchuraCC,alturaCC,profondidadCC);
		tubo.draw(mode, NEGRO);
		glPopMatrix();
}
base::~base(void)
{
}
