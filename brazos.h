#include "Cubo.h"
#pragma once
class brazos
{
public:
	Cubo cubo;
	double posZ;
	double anchura;
/////quadratoArriba///
	double alturaA;
	double profondidadA;
	double posXA;
	double posYA;
/////quadratoaBajo///
	double alturaB;
	double profondidadB;
	double posXB;
	double posYB;
/////quadratoaDelante///
	double alturaD;
	double profondidadD;
	double posXD;
	double posYD;
	double anguloD;
/////quadratoDEtras///
	double alturaDE;
	double profondidadDE;
	double posXDE;
	double posYDE;

	void draw_brazo(_mode mode);
	void draw_quadratoArriba(_mode mode);
	void draw_quadratoaBajo(_mode mode);
	void draw_quadratoaDelante(_mode mode);
	void draw_quadratoaDEtras(_mode mode);

	brazos(void);
	~brazos(void);
};

