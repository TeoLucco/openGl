#include "O3DC.h"
#pragma once
class baseAlta
{
public:
	O3DC cilindro;
	O3DC vaso;
	O3DC beethoven;
///////Cilindro Centrale////////
	double alturaCC;
	double anchuraCC;
	double profondidadCC;
	double altezzaCC;
///////Cilindro Basso/////////
	double alturaCB;
	double anchuraCB;
	double profondidadCB;
	double altezzaCB;
	double translateCB;


	////VASO/////
	double alturaVaso;
	double anchuraVaso;
	double profondidadVaso;
	double altezzaVaso;
	
	//////BARRA//////////
	double alturaB;
	double anchuraB;
	double profondidadB;
	double translatexB;
	double translateyB;
	double translatezB;
	double angleB;

	//////beethoven//////
	double alturaBe;
	double anchuraBe;
	double profondidadBe;
	double yBe;


	void draw_baseAlta(_mode mode);
	void draw_vaso(_mode mode);
	void draw_basebaja(_mode mode);
	void draw_barra(_mode mode);
	void draw_cilindro_central(_mode mode);
	void draw_beethoven(_mode mode);

	

	baseAlta(void);
	~baseAlta(void);
};

