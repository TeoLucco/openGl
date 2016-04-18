#include "O3DC.h"


#pragma once
class rueda
{
public:
	O3DC cilinde;
	O3DC copriruota;
	double angle;
	double altura;
	double anchura;
	double profondidad;
	double raggio;
	
	
	double pos_yCR;
	double alturaCR;
	double anchuraCR;
	double profondidadCR;

	void draw(_mode mode,GLfloat Observer_angle_x);
	double reduceDegree(GLfloat Observer_angle_x);
	
	rueda(void);
	~rueda(void);
};

