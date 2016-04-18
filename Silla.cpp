#include "Silla.h"
#include "base.h"
#include "baseAlta.h"
#include "brazos.h"
#include "rueda.h"
#include "respaldos.h"
#define PI (3.141592653589793)

Silla::Silla(void){
	dy=0.0;
	dRot=0.0;
	px=0.0;
	pz=0.0;
}

void Silla::draw_silla(_mode mode,GLfloat Observer_angle_x){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslated(px,0,pz);
	base.draw_base(mode);
	rueda.draw(mode,Observer_angle_x);
	glTranslated(0,dy,0);
	glRotated(dRot,0,1,0);
	baseAlta.draw_baseAlta(mode);
	respaldos.draw(mode);
	brazos.draw_brazo(mode);
	glTranslated(0,0,-3.8);
	brazos.draw_brazo(mode);
	glPopMatrix();

}

void Silla::alzar_silla(){
	if(dy<1.5)
	dy=dy+0.3;
}

void Silla::bajar_silla(){
	if(dy>-0.3)
	dy=dy-0.3;
}

void Silla::ruodar_reloj(){
	dRot=dRot-20;
}

void Silla::ruodar_antireloj(){
	dRot=dRot+20;
}

void Silla::mover_sx(){
	px=px+1;
	rueda.estado=VERTICAL;
}

void Silla::mover_sx_inv(){
	px=px-1;
	rueda.estado=VERTICAL;
}

void Silla::mover_sz(){
	pz=pz+1;
	rueda.estado=HORIZONTAL;
}

void Silla::mover_sz_inv(){
	pz=pz-1;
	rueda.estado=HORIZONTAL;
}



void Silla::mover_up(GLfloat Observer_angle_x){

	float radianti=reduceDegree(Observer_angle_x);

	px=px+sin(radianti);
	pz=pz-cos(radianti);
	rueda.estado=VERTICALOBL;

}

void Silla::mover_down(GLfloat Observer_angle_x){

	float radianti=reduceDegree(Observer_angle_x);

	px=px-sin(radianti);
	pz=pz+cos(radianti);
	rueda.estado=VERTICALOBL;
}

void Silla::mover_sx(GLfloat Observer_angle_x){

	float radianti=reduceDegree(Observer_angle_x);

	px=px-cos(radianti);
	pz=pz-sin(radianti);
	rueda.estado=HORIZONTALOBL;
}

void Silla::mover_dx(GLfloat Observer_angle_x){
	
	float radianti=reduceDegree(Observer_angle_x);

	px=px+cos(radianti);
	pz=pz+sin(radianti);
	rueda.estado=HORIZONTALOBL;
}


double Silla::reduceDegree(GLfloat Observer_angle_x){
	float radianti;
	if (Observer_angle_x>=0){
		while(Observer_angle_x>360)
		Observer_angle_x=Observer_angle_x-360;
		radianti = Observer_angle_x * PI / 180;
	}
	else{
		while(Observer_angle_x<-360)
		Observer_angle_x=Observer_angle_x+360;
		radianti = (360+Observer_angle_x) * PI / 180;
	}
	return radianti;
}



Silla::~Silla(void){
}
