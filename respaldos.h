#include "O3DC.h"
#pragma once
class respaldos
{
public:
	O3DC ciambella;
	O3DC cilindro;
	///ciambella di Collegamento///////////
	double translatex;
	double translatey;
	double alturaCM;
	double anchuraCM;
	double profondidadCM;

	///base schiena////
	double translatexBS; 
	double translateyBS;
	double alturaBS;
	double anchuraBS;
	double profondidadBS;
	
	void draw_ciabella(_mode mode);
	void draw_basespalda(_mode mode);
	void draw(_mode mode);
	respaldos(void);
	~respaldos(void);
};

