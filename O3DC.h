#include "vertex.h"
#include "O3DS.h"
#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include <vector>
#include "file_ply_stl.h"
#include "imageloader.h"

#include "CImg.h"

using namespace cimg_library;


typedef enum{VERTICES,EDGES,SOLID,ALL,CHESS} _mode;typedef enum{VERT,CARAS,OFF} _normalMode;typedef enum{MATE1,MATE2,MATE3} _material;
#pragma once
class O3DC:public O3DS
{
public:
	
	_mode mode;
	_color color;
	_normalMode nMode;
	_material material;
	void drawluz(_mode modo,_normalMode nMode,bool luz0,bool luz1,_material material,Image* textura,GLfloat Luz1[4]);
	void drawluz1(_mode modo,_normalMode nMode,_material material,Image* textura,GLfloat Luz1[4]);
	void drawluz0(_mode modo,_normalMode nMode,_material material,Image* textura);
	void drawluznotext(_mode modo,_normalMode nMode,bool luz0,bool luz1,_material material,GLfloat Luz1[4]);
	void drawluz1notext(_mode modo,_normalMode nMode,_material material,GLfloat Luz1[4]);
	void drawluz0notext(_mode modo,_normalMode nMode,_material material);
	void drawnMode(_normalMode nMode);
	void draw(_mode modo,_color color);
	void draw(_mode modo);
	

	void draw_edges();
	void draw_solid();
	
	void draw_edges(_color color);
	void draw_solid(_color color);
	
	void draw_chess();
	
	O3DC openply(char *nombre);
	
	void barridoAng(vector<_vertex3f> perfil, int n, double angleI, double angleF);
	void barridoST(vector<_vertex3f> perfil, int n);
	void barrido(vector<_vertex3f> profile, int number);

	void setTriangulos(vector<_vertex3i> Triangulos2);
	void normal_faces();
	void normal_points();

	_vertex3f rotate(_vertex3f point, float degree);

	
	//CImg<unsigned char> loadBMP_custom(const char * imagepath);
	void init_textura2 (Image* src);
	void drawsky(_normalMode nMode,Image* textura,GLfloat Luz1[4]);

	Image* init_textura_temp (void);
	Image* init_textura (void);
	void createCoordTexture(int numVertices, int numberRev);
	GLuint setTexture(const char *file_name);

	vector<_vertex2f> _coordTexture; // coordenadas de textura

	



	vector<_vertex2f> ctex;
	CImg<unsigned char>  texture;
	unsigned int tamx, tamy;
	unsigned char * data;
	vector<_vertex3i> Triangles;
	vector<_vertex3i> Edges;
	vector<_vertex3f> Normales_caras;
	vector<_vertex3f> Normales_vertices;

	vector<_vertex2f> _texturas;

	
	O3DC(void);			//costruttore
	O3DC(char* nombre);
	~O3DC(void);		//distruttore
};

