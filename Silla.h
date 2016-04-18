#include "O3DC.h"
#include "rueda.h"
#include "brazos.h"
#include "baseAlta.h"
#include "base.h"
#include "respaldos.h"
#include <GL/glut.h>
#pragma once
class Silla : public O3DC
{
public:
	rueda rueda;
	brazos brazos;
	baseAlta baseAlta;
	base base;
	respaldos respaldos;
	//posicion de la silla
	double px;
	double pz;
	//posicion della parte alta
	double dy;
	double dRot;

	void draw_silla(_mode mode,GLfloat Observer_angle_x);
	void alzar_silla();
	void bajar_silla();

	void mover_sz();
	void mover_sx();

	void mover_sz_inv();
	void mover_sx_inv();

	void mover_up(GLfloat Observer_angle_x);
	void mover_dx(GLfloat Observer_angle_x);

	void mover_down(GLfloat Observer_angle_x);
	void mover_sx(GLfloat Observer_angle_x);

	double reduceDegree(GLfloat Observer_angle_x);

	void ruodar_reloj();
	void ruodar_antireloj();
	
	Silla(void);
	~Silla(void);
};

