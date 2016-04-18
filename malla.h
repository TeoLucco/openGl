#include "stdlib.h"
#include "stdio.h"
#include "O3DC.h"
#include <GL/glut.h>
#include <math.h>

#pragma once
class malla:public O3DC
{
public:
	
	vector<_vertex2f> _coordTexture2;
	void aplicatex(int mallai,int mallaf,int texti,int textf,Image* text);
	void CreateCoordTexture1(int numVertices);
	malla(int n);
	~malla(void);
};

