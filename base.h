#include "O3DC.h"

#pragma once
class base
{
public:
	O3DC cilinde;
	O3DC tubo;
	/////piernas/////
	double angle;
	double anglepiernas;
	double radio;
	double altura;
	double anchura;
	double profondidad;
	double altezza;
	////cilindro central//
	double alturaCC;
	double anchuraCC;
	double profondidadCC;
	double altezzaCC;
	void draw_cilindro_central(_mode mode);
	void draw_base(_mode mode);
	base(void);
	~base(void);
};

