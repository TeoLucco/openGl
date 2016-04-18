#include "vertex.h"
#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include <vector>

typedef enum{NEGRO,NEGROCLARO,AZUL,GRIS,AMARILLO} _color;

#pragma once
class O3DS
{
public:
	_color color;
	void draw_points();
	void draw_points(_color color);
	void setPoints(vector<_vertex3f> Vertices);
	void setNormales();

	vector<_vertex3f> Vertices;
	vector<_vertex3f> getVertices();
	O3DS(void);
	~O3DS(void);
};

