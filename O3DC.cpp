#include "O3DC.h"
#include "O3DS.h"

#define PI (3.141592653589793)

#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include "imageloader.h"

vector<_vertex3i> Triangles;
vector<_vertex3i> Edges;

void O3DC::draw(_mode modo){
	switch (modo){
			case VERTICES: //Puntos
				draw_points();
				break;
			case EDGES: //Edges
				draw_edges();
				break;
			case SOLID: //Solido
				draw_solid();
				break;
			case CHESS: //Chess
				draw_chess();
				break;
			case ALL:  //Todo
				draw_edges();
				draw_points();
				draw_solid();
				break;
		}
}

void O3DC::draw(_mode modo, _color color){
	switch (modo){
			case VERTICES: //Puntos
				draw_points(color);
				break;
			case EDGES: //Edges
				draw_edges(color);
				break;
			case SOLID: //Solido
				draw_solid(color);
				break;
			case CHESS: //Chess
				draw_chess();
				break;
			case ALL:  //Todo
				draw_edges(color);
				draw_points(color);
				draw_solid(color);
				break;
		}
}

void O3DC::draw_edges(){
	glBegin(GL_LINES);
	glColor3f(0,0,0);	
	for(int i=0;i<Triangles.size();i++){
		glVertex3f(Vertices[Triangles[i]._0].x,Vertices[Triangles[i]._0].y,Vertices[Triangles[i]._0].z);
		glVertex3f(Vertices[Triangles[i]._1].x,Vertices[Triangles[i]._1].y,Vertices[Triangles[i]._1].z);

		glVertex3f(Vertices[Triangles[i]._1].x,Vertices[Triangles[i]._1].y,Vertices[Triangles[i]._1].z);
		glVertex3f(Vertices[Triangles[i]._2].x,Vertices[Triangles[i]._2].y,Vertices[Triangles[i]._2].z);

		glVertex3f(Vertices[Triangles[i]._2].x,Vertices[Triangles[i]._2].y,Vertices[Triangles[i]._2].z);
		glVertex3f(Vertices[Triangles[i]._0].x,Vertices[Triangles[i]._0].y,Vertices[Triangles[i]._0].z);


	}

glEnd();
}

void O3DC::draw_solid(){

	glBegin(GL_TRIANGLES);
glColor3f(0,1,1);	
for(int i=0;i<Triangles.size();i++){
		glVertex3f(Vertices[Triangles[i]._0].x,Vertices[Triangles[i]._0].y,Vertices[Triangles[i]._0].z);
		glVertex3f(Vertices[Triangles[i]._1].x,Vertices[Triangles[i]._1].y,Vertices[Triangles[i]._1].z);
		glVertex3f(Vertices[Triangles[i]._2].x,Vertices[Triangles[i]._2].y,Vertices[Triangles[i]._2].z);
}

glEnd();



}

void O3DC::draw_chess(){

	glBegin(GL_TRIANGLES);
	
	int a=0;
	for(int i=0;i<Triangles.size();i++){
		if(a==0){
			glColor3f(0,1,1);
			glVertex3f(Vertices[Triangles[i]._0].x,Vertices[Triangles[i]._0].y,Vertices[Triangles[i]._0].z);
			glVertex3f(Vertices[Triangles[i]._1].x,Vertices[Triangles[i]._1].y,Vertices[Triangles[i]._1].z);
			glVertex3f(Vertices[Triangles[i]._2].x,Vertices[Triangles[i]._2].y,Vertices[Triangles[i]._2].z);
			a=1;
		}else{
			glColor3f(0,0,1);
			glVertex3f(Vertices[Triangles[i]._0].x,Vertices[Triangles[i]._0].y,Vertices[Triangles[i]._0].z);
			glVertex3f(Vertices[Triangles[i]._1].x,Vertices[Triangles[i]._1].y,Vertices[Triangles[i]._1].z);
			glVertex3f(Vertices[Triangles[i]._2].x,Vertices[Triangles[i]._2].y,Vertices[Triangles[i]._2].z);
			a=0;
		
		}
	}

glEnd();

}

void O3DC::draw_edges(_color color){
	glBegin(GL_LINES);

	switch (color){
			case NEGROCLARO:
				glColor3f(0.419,0.415,0.524);
				break;
			case NEGRO: 
				glColor3f(0,0,0);
				break;
			case AZUL:
				glColor3f(0.078, 0.035, 0.698);
				break;
			case GRIS:
				glColor3f(0.898, 0.898, 0.898);
				break;
			case AMARILLO:
				glColor3f(1, 1, 0);
				break;
		}

		
	for(int i=0;i<Triangles.size();i++){
		glVertex3f(Vertices[Triangles[i]._0].x,Vertices[Triangles[i]._0].y,Vertices[Triangles[i]._0].z);
		glVertex3f(Vertices[Triangles[i]._1].x,Vertices[Triangles[i]._1].y,Vertices[Triangles[i]._1].z);

		glVertex3f(Vertices[Triangles[i]._1].x,Vertices[Triangles[i]._1].y,Vertices[Triangles[i]._1].z);
		glVertex3f(Vertices[Triangles[i]._2].x,Vertices[Triangles[i]._2].y,Vertices[Triangles[i]._2].z);

		glVertex3f(Vertices[Triangles[i]._2].x,Vertices[Triangles[i]._2].y,Vertices[Triangles[i]._2].z);
		glVertex3f(Vertices[Triangles[i]._0].x,Vertices[Triangles[i]._0].y,Vertices[Triangles[i]._0].z);


	}

glEnd();
}

void O3DC::draw_solid(_color color){

	glBegin(GL_TRIANGLES);
switch (color){
			case NEGROCLARO:
				glColor3f(0.419,0.415,0.524);
				break;
			case NEGRO: 
				glColor3f(0,0,0);
				break;
			case AZUL:
				glColor3f(0.078, 0.035, 0.698);
				break;
			case GRIS:
				glColor3f(0.898, 0.898, 0.898);
				break;
			case AMARILLO:
				glColor3f(1, 1, 0);
				break;
		}	
for(int i=0;i<Triangles.size();i++){
		glVertex3f(Vertices[Triangles[i]._0].x,Vertices[Triangles[i]._0].y,Vertices[Triangles[i]._0].z);
		glVertex3f(Vertices[Triangles[i]._1].x,Vertices[Triangles[i]._1].y,Vertices[Triangles[i]._1].z);
		glVertex3f(Vertices[Triangles[i]._2].x,Vertices[Triangles[i]._2].y,Vertices[Triangles[i]._2].z);
}

glEnd();



}



void O3DC::setTriangulos(vector<_vertex3i> Triangulos2){
	Triangles.resize(Triangulos2.size());
	int max= Triangulos2.size();
	for(int i=0; i<max;i++){
		Triangles[i]=Triangulos2[i];
	}

}

void O3DC::barridoAng(vector<_vertex3f> perfil, int n, double angleI, double angleF)
{
    float anglePaso;
	vector<_vertex3i> caras;
    vector<_vertex3f> vertices;
	vector<_vertex3f> primero;
	angleI=angleI * PI / 180;
	angleF=angleF * PI / 180;

    anglePaso = (angleF-angleI) / n;
	primero.resize(perfil.size()); 
    // Genero la primera culmna de puntos en angleI
	for (int k = 0; k < perfil.size(); k++){
            primero[k] = rotate(perfil[k], angleI);   //calculo la coordinata del nuevo punto
			vertices.push_back(primero[k]);   //la añaido al vector vertices
	}
	vector<_vertex3f> next;     //next vector
	next.resize(perfil.size()); //same dimension of input vert
	next=primero;
	//Genero todos lo otros puntos
	for (int i = 0; i < n; i++){
				
        for (int x = 0; x < perfil.size(); x++){
            next[x] = rotate(next[x], anglePaso);   //calculo la coordinata del nuevo punto
			vertices.push_back(next[x]);   //la añaido al vector vertices
		}

        // calculo el indice de los primero puntos de las dos 'columnas'
        int primero1, primero2;
        primero1 = i * perfil.size();
        primero2 = primero1 + perfil.size();
		
		//Genero las caras
		for (int z = primero1 +1, k = primero2+1; z < primero2; z++, k++)
        {
            caras.push_back(_vertex3i(z-1, k-1, k));
            caras.push_back(_vertex3i(z-1, k,   z));
        }
		
		perfil = next;

    }

	setPoints(vertices);
    setTriangulos(caras);
	
	normal_faces();
	normal_points();

}

void O3DC::barrido(vector<_vertex3f> perfil, int n)
{
    double angle;
    vector<_vertex3i> caras;
    vector<_vertex3f> vertices(perfil);

    angle = (2.0*PI) / n;

    // Genero los puntos y los añaido al vector vertices

    for (int i = 0; i < n; i++)
    {
        vector<_vertex3f> next;     //next vector
		next.resize(perfil.size());   //same dimension of input vert
        for (int k = 0; k < perfil.size(); k++){
            next[k] = rotate(perfil[k], angle);   //calculo la coordinata del nuevo punto
			vertices.push_back(next[k]);   //la añaido al vector vertices
		}

        // calculo el indice de los primero puntos de las dos 'columnas'
        int primero1, primero2;
        primero1 = i * perfil.size();
        primero2 = primero1 + perfil.size();
		
		//Genero las caras
		for (int z = primero1 +1, k = primero2+1; z < primero2; z++, k++)
        {
            caras.push_back(_vertex3i(z-1, k-1, k));
            caras.push_back(_vertex3i(z-1, k,   z));
        }
		
		perfil = next;

    }
	
    // Genero las tapas

	    // Genero la tapa de abajo
		    // Genero el punto central
			_vertex3f puntoCentral(0.0, vertices.front().y, 0.0);
			vertices.push_back(puntoCentral);
			
			//Genero las caras de la tapa
			for (int i = 0; i < n; i++)
			{
				int primero1 = i * perfil.size();
				int primero2 = primero1 + perfil.size();
				caras.push_back(_vertex3i(vertices.size()-1, primero2, primero1));
	        }

        // Genero la tapa de arriba
    	    // Genero el punto central
		    _vertex3f puntoCentral2(0.0, vertices[perfil.size() - 1].y, 0.0);
			vertices.push_back(puntoCentral2);
			
			//Genero las caras de la tapa
			for (int i = 0; i < n; i++)
			{
				int ultimo1 = (i+1) * perfil.size() -1;
				int ultimo2 = ultimo1 + perfil.size();
				caras.push_back(_vertex3i(vertices.size()-1, ultimo1, ultimo2)); 
			}

       
    setPoints(vertices);
    setTriangulos(caras);
	
	normal_faces();
	normal_points();
	

}

void O3DC::barridoST(vector<_vertex3f> perfil, int n)
{
    double angle;
    vector<_vertex3i> caras;
    vector<_vertex3f> vertices(perfil);

    angle = (2.0*PI) / n;

    // Genero los puntos y los añaido al vector vertices

    for (int i = 0; i < n; i++)
    {
        vector<_vertex3f> next;     //next vector
		next.resize(perfil.size());   //same dimension of input vert
        for (int k = 0; k < perfil.size(); k++){
            next[k] = rotate(perfil[k], angle);   //calculo la coordinata del nuevo punto
			vertices.push_back(next[k]);   //la añaido al vector vertices
		}

        // calculo el indice de los primero puntos de las dos 'columnas'
        int primero1, primero2;
        primero1 = i * perfil.size();
        primero2 = primero1 + perfil.size();
		
		//Genero las caras
		for (int z = primero1 +1, k = primero2+1; z < primero2; z++, k++)
        {
            caras.push_back(_vertex3i(z-1, k-1, k));
            caras.push_back(_vertex3i(z-1, k,   z));
        }
		
		perfil = next;

    }
       
    setPoints(vertices);
    setTriangulos(caras);
	
	normal_faces();
	normal_points();
	

}



O3DC O3DC::openply(char *nombre) {
    vector<_vertex3f> vertices;
    vector<_vertex3i> caras;
	_file_ply fichero;
	O3DC figura;
    
	fichero.open(nombre);

    vector<float>ply_vertices;
    vector<int>ply_caras;

    fichero.read(ply_vertices,ply_caras);

  
    for (int j = 0; j < ply_vertices.size(); j+=3)
    {
        _vertex3f vert;
        vert.x = ply_vertices[j] ;
        vert.y = ply_vertices[j+1] ;
        vert.z = ply_vertices[j+2] ;

        vertices.push_back(vert);

    }

    for (int j = 0; j < ply_caras.size(); j+=3)
    {

        _vertex3i triangulo;
        triangulo._0 = ply_caras[j] ;
        triangulo._1 = ply_caras[j+1] ;
        triangulo._2 = ply_caras[j+2] ;

        caras.push_back(triangulo);

    }

    figura.setPoints(vertices);
    figura.setTriangulos(caras);

	return figura;


}

_vertex3f O3DC::rotate(_vertex3f point, float degree)
{
    _vertex3f punto;

    punto.x = cos(degree) * point.x + sin(degree) * point.z;
    punto.y = point.y;
    punto.z = -sin(degree) * point.x + cos(degree) * point.z;

    return punto;
}


void O3DC::normal_faces(){
  int v0,v1,v2, tam=Triangles.size();
  Normales_caras.resize(tam);
  _vertex3f a,b;
   vector<_vertex3f> bariv;
   bariv.resize(tam);
  for(unsigned i=0; i<Triangles.size(); i++){
      v0 = Triangles[i]._0;
      v1 = Triangles[i]._1;
      v2 = Triangles[i]._2;

      bariv[i].x=(Vertices[v0].x+Vertices[v1].x+Vertices[v2].x)/3;
      bariv[i].y=(Vertices[v0].y+Vertices[v1].y+Vertices[v2].y)/3;
      bariv[i].z=(Vertices[v0].z+Vertices[v1].z+Vertices[v2].z)/3;

      a= Vertices[v2]-Vertices[v0];
      b= Vertices[v1]-Vertices[v0];


      Normales_caras[i]=a.cross_product(b);
      Normales_caras[i].normalize();
  }
}


bool is_here(int v0, int v1, int v2, int val){
  bool found=false;
  if ((v0 == val || v1 == val || v2 == val) && !(v0==0 && v1==0 && v2==0)){
      found=true;

    }
  return found;
}

void O3DC::normal_points(){
  unsigned v0,v1,v2,cnt;
 int tam=Vertices.size();
 Normales_vertices.resize(tam);

 for(unsigned i=0; i<Vertices.size();i++){
     cnt=0;
     Normales_vertices[i].x=0;
     Normales_vertices[i].y=0;
     Normales_vertices[i].z=0;

     for(unsigned j=0; j<Triangles.size() && cnt < 6; j++){
         v0 = Triangles[j]._0;
         v1 = Triangles[j]._1;
         v2 = Triangles[j]._2;
         if(is_here(v0,v1,v2,i)){
             Normales_vertices[i].x+=Normales_caras[j].x;
             Normales_vertices[i].y+=Normales_caras[j].y;
             Normales_vertices[i].z+=Normales_caras[j].z;
             cnt++;
         }
     }
     Normales_vertices[i].x/=cnt;
     Normales_vertices[i].y/=cnt;
     Normales_vertices[i].z/=cnt;

     Normales_vertices[i].normalize();
 }
}


//*********************************************************************************
// Función que asocia coordenadas de textura a cada vértice
// En las mallas que no tengan o no necesiten coordenadas de textura, dicha tabla 
// estará vacía (0 elementos) o será un puntero nulo.
//*********************************************************************************
void O3DC::createCoordTexture(int numVertices, int numberRev) {
	_coordTexture.resize(numVertices*(numberRev+1));
	_vertex2f coordinate;

	// calcular las distancias para cada valor del perfil
	vector<float> distances;
	distances.push_back(0);

	// Las distancia se definen como sigue:
	// d0 = 0
	// dj+1 = dj + ||pj+1 - pj||
	// y se pueden calcular y almacenar en un vector temporal durante la creación 
	// de la malla. 
	int i;
	float tmp;
	for (i = 1; i < numVertices; i++) {
		tmp = distances[i-1] + (Vertices[i] - Vertices[i-1]).module();
		distances.push_back(tmp);
		//printf("Distance %d: %f\n", i, tmp);
	}

	int j;
	float x, y;
	int profilePosition;
	int verticePosition;
	for (j = 0; j < (numVertices*(numberRev+1)); j++) {
		// COORDENADA X
		// un valor proporcional a la copia del perfil dónde hay que "pegar" la imágen. 
		// haciendo x = copia del Perfil/(numberRev - 1) 
		profilePosition = j/numVertices; // número del perfil dónde hay que calcular el valor de x
		//printf("%d. x-Position: %d\n", j, profilePosition);
		x = profilePosition/(float)(numberRev);
		//printf("x = %f\n", x);

		// COORDENADA Y
		// Conocidas las distancias se obtiene como 
		// y = distancia(y)/distancia(número de vertices del perfil - 1)
		verticePosition = j%numVertices; // número del vertice dentro de un perfil dónde hay que calcular el valor de y
		//printf("%d. y-Position: \%d %d\n", j, numVertices, verticePosition);
		y = distances[verticePosition] / distances[numVertices - 1];
		//printf("y = %f\n", y);

		// Añadir la coordenada al vector
		coordinate(x,y);
		_coordTexture[j] = coordinate;
	}
}





Image* O3DC::init_textura (void){

	Image* src = loadBMP("dia.bmp");
	
	//CImg<unsigned char> src("dia.bmp");
	createCoordTexture(19, 24);
	return src;
}

Image* O3DC::init_textura_temp (void){

	Image* src = loadBMP("nubes.bmp");
	createCoordTexture(19, 24);
	return src;
}

void O3DC::init_textura2 (Image* src){
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	

glTexImage2D (GL_TEXTURE_2D, 0, GL_RGB, src->width, src->height, 0, GL_RGB, GL_UNSIGNED_BYTE, src->pixels);

glEnable(GL_TEXTURE_2D);
}

void O3DC::drawluz0notext(_mode modo,_normalMode nMode,_material material){
	

	
	GLfloat Luz0[4]={12,12,-12,0};

	glLightfv(GL_LIGHT0,GL_POSITION,Luz0);
	
	
	
	GLfloat Oro_specular[4]={0.628281,0.555802,0.366065,1};
	GLfloat Oro_diffuse[4]={0.34615,0.60648,0.22648,1};
	GLfloat Oro_ambient[4]={0.24725,0.2245,0.0645,1};
	GLfloat Oro_bright=100;

	GLfloat Psilver_specular[4]={0.508273,0.508273,0.508273,1};
	GLfloat Psilver_diffuse[4]={0.50754,0.50754,0.50754,1};
	GLfloat Psilver_ambient[4]={0.19225,0.19225,0.19225,1};
	GLfloat Psilver_bright=25;

	
	GLfloat Pearl_specular[4]={0.296648,0.296648,0.296648,0.922};
	GLfloat Pearl_diffuse[4]={1.0,0.829,0.829,0.922};
	GLfloat Pearl_ambient[4]={0.25,0.20725,0.20725,0.922};
	GLfloat Pearl_bright=1;
	
			switch (material){
	
	case MATE1: 	
				
				glMaterialfv(GL_FRONT,GL_AMBIENT,(GLfloat *) &Pearl_ambient);
				glMaterialfv(GL_FRONT,GL_DIFFUSE,(GLfloat *) &Pearl_diffuse);
				glMaterialfv(GL_FRONT,GL_SPECULAR,(GLfloat *) &Pearl_specular);
				glMaterialf(GL_FRONT,GL_SHININESS,Pearl_bright);
				break;
	case MATE2: glMaterialfv(GL_FRONT,GL_AMBIENT,(GLfloat *) &Oro_ambient);
				glMaterialfv(GL_FRONT,GL_DIFFUSE,(GLfloat *) &Oro_diffuse);
				glMaterialfv(GL_FRONT,GL_SPECULAR,(GLfloat *) &Oro_specular);
				glMaterialf(GL_FRONT,GL_SHININESS,Oro_bright);
				break;
	case MATE3: glMaterialfv(GL_FRONT,GL_AMBIENT,(GLfloat *) &Psilver_ambient);
				glMaterialfv(GL_FRONT,GL_DIFFUSE,(GLfloat *) &Psilver_diffuse);
				glMaterialfv(GL_FRONT,GL_SPECULAR,(GLfloat *) &Psilver_specular);
				glMaterialf(GL_FRONT,GL_SHININESS,Psilver_bright);
				break;
	}
	
	switch (nMode){
		case CARAS: {
	
			glShadeModel(GL_FLAT);
			glEnable(GL_LIGHTING);
			glEnable(GL_LIGHT0);
			glBegin(GL_TRIANGLES);
			
			
			for (unsigned i=0;i<Triangles.size();i++){
				
				glNormal3f(Normales_caras[i].x, Normales_caras[i].y, Normales_caras[i].z);
				glVertex3f(Vertices[Triangles[i]._0].x, Vertices[Triangles[i]._0].y, Vertices[Triangles[i]._0].z);
				glVertex3f(Vertices[Triangles[i]._1].x, Vertices[Triangles[i]._1].y, Vertices[Triangles[i]._1].z);
				glVertex3f(Vertices[Triangles[i]._2].x, Vertices[Triangles[i]._2].y, Vertices[Triangles[i]._2].z);
			}
			glEnd();
		
		break;}
		case VERT:{
			
			glShadeModel(GL_SMOOTH);
			glEnable(GL_LIGHTING);
			glEnable(GL_LIGHT0);
			glBegin(GL_TRIANGLES);
			
			for (unsigned i=0;i<Triangles.size();i++){
			
				glNormal3f(Normales_vertices[Triangles[i]._0].x, Normales_vertices[Triangles[i]._0].y, Normales_vertices[Triangles[i]._0].z);
				glVertex3f(Vertices[Triangles[i]._0].x, Vertices[Triangles[i]._0].y, Vertices[Triangles[i]._0].z);
				glNormal3f(Normales_vertices[Triangles[i]._1].x, Normales_vertices[Triangles[i]._1].y, Normales_vertices[Triangles[i]._1].z);
				glVertex3f(Vertices[Triangles[i]._1].x, Vertices[Triangles[i]._1].y, Vertices[Triangles[i]._1].z);
				glNormal3f(Normales_vertices[Triangles[i]._2].x, Normales_vertices[Triangles[i]._2].y, Normales_vertices[Triangles[i]._2].z);
				glVertex3f(Vertices[Triangles[i]._2].x, Vertices[Triangles[i]._2].y, Vertices[Triangles[i]._2].z);
			}
			glEnd();
			break;
		}
	
	}
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}
			


void O3DC::drawluz1notext(_mode modo,_normalMode nMode,_material material,GLfloat Luz1[4]){
	
	GLfloat Ambiente[4]={1,1,1,1};
	GLfloat luz_difusa[4] = {0.6, 0.5, 0.3, 1.0};


	glLightfv(GL_LIGHT1,GL_POSITION,Luz1);
	glLightfv (GL_LIGHT1, GL_DIFFUSE, luz_difusa);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,Ambiente);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE);
	
	GLfloat Oro_specular[4]={0.628281,0.555802,0.366065,1};
	GLfloat Oro_diffuse[4]={0.34615,0.60648,0.22648,1};
	GLfloat Oro_ambient[4]={0.24725,0.2245,0.0645,1};
	GLfloat Oro_bright=100;

	GLfloat Psilver_specular[4]={0.508273,0.508273,0.508273,1};
	GLfloat Psilver_diffuse[4]={0.50754,0.50754,0.50754,1};
	GLfloat Psilver_ambient[4]={0.19225,0.19225,0.19225,1};
	GLfloat Psilver_bright=25;

	
	GLfloat Pearl_specular[4]={0.296648,0.296648,0.296648,0.922};
	GLfloat Pearl_diffuse[4]={1.0,0.829,0.829,0.922};
	GLfloat Pearl_ambient[4]={0.25,0.20725,0.20725,0.922};
	GLfloat Pearl_bright=1;

	switch (material){
	
		case MATE1: 	
				glMaterialfv(GL_FRONT,GL_AMBIENT,(GLfloat *) &Pearl_ambient);
				glMaterialfv(GL_FRONT,GL_DIFFUSE,(GLfloat *) &Pearl_diffuse);
				glMaterialfv(GL_FRONT,GL_SPECULAR,(GLfloat *) &Pearl_specular);
				glMaterialf(GL_FRONT,GL_SHININESS,Pearl_bright);
				break;
		case MATE2: 
				glMaterialfv(GL_FRONT,GL_AMBIENT,(GLfloat *) &Oro_ambient);
				glMaterialfv(GL_FRONT,GL_DIFFUSE,(GLfloat *) &Oro_diffuse);
				glMaterialfv(GL_FRONT,GL_SPECULAR,(GLfloat *) &Oro_specular);
				glMaterialf(GL_FRONT,GL_SHININESS,Oro_bright);
				break;
	case MATE3: glMaterialfv(GL_FRONT,GL_AMBIENT,(GLfloat *) &Psilver_ambient);
				glMaterialfv(GL_FRONT,GL_DIFFUSE,(GLfloat *) &Psilver_diffuse);
				glMaterialfv(GL_FRONT,GL_SPECULAR,(GLfloat *) &Psilver_specular);
				glMaterialf(GL_FRONT,GL_SHININESS,Psilver_bright);
				break;
	}

	
	switch (nMode){
		case CARAS: {
			
			glShadeModel(GL_FLAT);
			glEnable(GL_LIGHTING);
			glEnable(GL_LIGHT1);
			//init_textura2(textura);
			glBegin(GL_TRIANGLES);
			
			
			for (unsigned i=0;i<Triangles.size();i++){
				
				
				glNormal3f(Normales_caras[i].x, Normales_caras[i].y, Normales_caras[i].z);
				glVertex3f(Vertices[Triangles[i]._0].x, Vertices[Triangles[i]._0].y, Vertices[Triangles[i]._0].z);
				glVertex3f(Vertices[Triangles[i]._1].x, Vertices[Triangles[i]._1].y, Vertices[Triangles[i]._1].z);
				glVertex3f(Vertices[Triangles[i]._2].x, Vertices[Triangles[i]._2].y, Vertices[Triangles[i]._2].z);
			}
			glEnd();
			
		
		break;
		}
		case VERT:{
			glShadeModel(GL_SMOOTH);
			glEnable(GL_LIGHTING);
			glEnable(GL_LIGHT1);
			//init_textura2(textura);
			glBegin(GL_TRIANGLES);
			
			for (unsigned i=0;i<Triangles.size();i++){
			
				glNormal3f(Normales_vertices[Triangles[i]._0].x, Normales_vertices[Triangles[i]._0].y, Normales_vertices[Triangles[i]._0].z);
				glVertex3f(Vertices[Triangles[i]._0].x, Vertices[Triangles[i]._0].y, Vertices[Triangles[i]._0].z);
				glNormal3f(Normales_vertices[Triangles[i]._1].x, Normales_vertices[Triangles[i]._1].y, Normales_vertices[Triangles[i]._1].z);
				glVertex3f(Vertices[Triangles[i]._1].x, Vertices[Triangles[i]._1].y, Vertices[Triangles[i]._1].z);
				glNormal3f(Normales_vertices[Triangles[i]._2].x, Normales_vertices[Triangles[i]._2].y, Normales_vertices[Triangles[i]._2].z);
				glVertex3f(Vertices[Triangles[i]._2].x, Vertices[Triangles[i]._2].y, Vertices[Triangles[i]._2].z);
			}
			glEnd();
			break;
		}



	}
	glDisable(GL_LIGHT1);
	glDisable(GL_LIGHTING);

}


void O3DC::drawluznotext(_mode modo,_normalMode nMode,bool luz0,bool luz1,_material material,GLfloat Luz1[4]){
    
	if(luz0==true && luz1==false){
	drawluz0notext(SOLID,nMode,material);
	}else if(luz0==false && luz1==true){
	drawluz1notext(SOLID,nMode,material,Luz1);
	}else if(luz0==false && luz1==false){
	glDisable(GL_LIGHTING);
	draw(modo,AZUL);glEnable(GL_LIGHTING);
	}
}


void O3DC::drawluz0(_mode modo,_normalMode nMode,_material material,Image* textura){
	
	
	
	GLfloat Luz0[4]={12,12,-12,0};

	glLightfv(GL_LIGHT0,GL_POSITION,Luz0);
	
	
	
	GLfloat Oro_specular[4]={0.628281,0.555802,0.366065,1};
	GLfloat Oro_diffuse[4]={0.34615,0.60648,0.22648,1};
	GLfloat Oro_ambient[4]={0.24725,0.2245,0.0645,1};
	GLfloat Oro_bright=100;

	GLfloat Psilver_specular[4]={0.508273,0.508273,0.508273,1};
	GLfloat Psilver_diffuse[4]={0.50754,0.50754,0.50754,1};
	GLfloat Psilver_ambient[4]={0.19225,0.19225,0.19225,1};
	GLfloat Psilver_bright=25;

	
	GLfloat Pearl_specular[4]={0.296648,0.296648,0.296648,0.922};
	GLfloat Pearl_diffuse[4]={1.0,0.829,0.829,0.922};
	GLfloat Pearl_ambient[4]={0.25,0.20725,0.20725,0.922};
	GLfloat Pearl_bright=1;
	
			switch (material){
	
	case MATE1: 	
				
				glMaterialfv(GL_FRONT,GL_AMBIENT,(GLfloat *) &Pearl_ambient);
				glMaterialfv(GL_FRONT,GL_DIFFUSE,(GLfloat *) &Pearl_diffuse);
				glMaterialfv(GL_FRONT,GL_SPECULAR,(GLfloat *) &Pearl_specular);
				glMaterialf(GL_FRONT,GL_SHININESS,Pearl_bright);
				break;
	case MATE2: glMaterialfv(GL_FRONT,GL_AMBIENT,(GLfloat *) &Oro_ambient);
				glMaterialfv(GL_FRONT,GL_DIFFUSE,(GLfloat *) &Oro_diffuse);
				glMaterialfv(GL_FRONT,GL_SPECULAR,(GLfloat *) &Oro_specular);
				glMaterialf(GL_FRONT,GL_SHININESS,Oro_bright);
				break;
	case MATE3: glMaterialfv(GL_FRONT,GL_AMBIENT,(GLfloat *) &Psilver_ambient);
				glMaterialfv(GL_FRONT,GL_DIFFUSE,(GLfloat *) &Psilver_diffuse);
				glMaterialfv(GL_FRONT,GL_SPECULAR,(GLfloat *) &Psilver_specular);
				glMaterialf(GL_FRONT,GL_SHININESS,Psilver_bright);
				break;
	}
	
	switch (nMode){
		case CARAS: {
	
			glShadeModel(GL_FLAT);
			glEnable(GL_LIGHTING);
			glEnable(GL_LIGHT0);
			init_textura2(textura);
			glBegin(GL_TRIANGLES);
			
			
			for (unsigned i=0;i<Triangles.size();i++){
				
				glNormal3f(Normales_caras[i].x, Normales_caras[i].y, Normales_caras[i].z);
				glTexCoord2f(_coordTexture[Triangles[i]._0].x, _coordTexture[Triangles[i]._0].y);
				glVertex3f(Vertices[Triangles[i]._0].x, Vertices[Triangles[i]._0].y, Vertices[Triangles[i]._0].z);
				glTexCoord2f(_coordTexture[Triangles[i]._1].x, _coordTexture[Triangles[i]._1].y);
				glVertex3f(Vertices[Triangles[i]._1].x, Vertices[Triangles[i]._1].y, Vertices[Triangles[i]._1].z);
				glTexCoord2f(_coordTexture[Triangles[i]._2].x, _coordTexture[Triangles[i]._2].y);
				glVertex3f(Vertices[Triangles[i]._2].x, Vertices[Triangles[i]._2].y, Vertices[Triangles[i]._2].z);
			}
			glEnd();
		
		break;}
		case VERT:{
			
			glShadeModel(GL_SMOOTH);
			glEnable(GL_LIGHTING);
			glEnable(GL_LIGHT0);
			init_textura2(textura);
			glBegin(GL_TRIANGLES);
			
			for (unsigned i=0;i<Triangles.size();i++){
			
				glNormal3f(Normales_vertices[Triangles[i]._0].x, Normales_vertices[Triangles[i]._0].y, Normales_vertices[Triangles[i]._0].z);
				glTexCoord2f(_coordTexture[Triangles[i]._0].x, _coordTexture[Triangles[i]._0].y);
				glVertex3f(Vertices[Triangles[i]._0].x, Vertices[Triangles[i]._0].y, Vertices[Triangles[i]._0].z);
				glNormal3f(Normales_vertices[Triangles[i]._1].x, Normales_vertices[Triangles[i]._1].y, Normales_vertices[Triangles[i]._1].z);
				glTexCoord2f(_coordTexture[Triangles[i]._1].x, _coordTexture[Triangles[i]._1].y);
				glVertex3f(Vertices[Triangles[i]._1].x, Vertices[Triangles[i]._1].y, Vertices[Triangles[i]._1].z);
				glNormal3f(Normales_vertices[Triangles[i]._2].x, Normales_vertices[Triangles[i]._2].y, Normales_vertices[Triangles[i]._2].z);
				glTexCoord2f(_coordTexture[Triangles[i]._2].x, _coordTexture[Triangles[i]._2].y);
				glVertex3f(Vertices[Triangles[i]._2].x, Vertices[Triangles[i]._2].y, Vertices[Triangles[i]._2].z);
			}
			glEnd();
			break;
		}
	
	}
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
			
}



void O3DC::drawsky(_normalMode nMode,Image* textura,GLfloat Luz1[4]){
	
	
	GLfloat Ambiente[4]={1,1,1,1};
	GLfloat luz_difusa[4] = {1.0, 1.0, 1.0, 1.0};


	glLightfv(GL_LIGHT1,GL_POSITION,Luz1);
	glLightfv (GL_LIGHT1, GL_DIFFUSE, luz_difusa);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,Ambiente);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE);
	
	
	GLfloat Pearl_specular[4]={0.296648,0.296648,0.296648,0.922};
	GLfloat Pearl_diffuse[4]={1.0,0.829,0.829,0.922};
	GLfloat Pearl_ambient[4]={0.25,0.20725,0.20725,0.922};
	GLfloat Pearl_bright=11.264;

	
				glMaterialfv(GL_BACK,GL_AMBIENT,(GLfloat *) &Pearl_ambient);
				glMaterialfv(GL_BACK,GL_DIFFUSE,(GLfloat *) &Pearl_diffuse);
				glMaterialfv(GL_BACK,GL_SPECULAR,(GLfloat *) &Pearl_specular);
				glMaterialf(GL_BACK,GL_SHININESS,Pearl_bright);
				
	
	switch (nMode){
		case CARAS: {
			
			glShadeModel(GL_FLAT);
			glEnable(GL_LIGHTING);
			glEnable(GL_LIGHT1);
			init_textura2(textura);
			glBegin(GL_TRIANGLES);
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			
			
			for (unsigned i=0;i<Triangles.size();i++){
				
				
				glNormal3f(Normales_caras[i].x, Normales_caras[i].y, Normales_caras[i].z);
				glTexCoord2f(_coordTexture[Triangles[i]._0].x, _coordTexture[Triangles[i]._0].y);
				glVertex3f(Vertices[Triangles[i]._0].x, Vertices[Triangles[i]._0].y, Vertices[Triangles[i]._0].z);
				glTexCoord2f(_coordTexture[Triangles[i]._1].x, _coordTexture[Triangles[i]._1].y);
				glVertex3f(Vertices[Triangles[i]._1].x, Vertices[Triangles[i]._1].y, Vertices[Triangles[i]._1].z);
				glTexCoord2f(_coordTexture[Triangles[i]._2].x, _coordTexture[Triangles[i]._2].y);
				glVertex3f(Vertices[Triangles[i]._2].x, Vertices[Triangles[i]._2].y, Vertices[Triangles[i]._2].z);
			}
			glEnd();
			
		
		break;
		}
		case VERT:{
			glShadeModel(GL_SMOOTH);
			glEnable(GL_LIGHTING);
			glEnable(GL_LIGHT1);
			init_textura2(textura);
			glBegin(GL_TRIANGLES);
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			
			for (unsigned i=0;i<Triangles.size();i++){
			
				glNormal3f(Normales_vertices[Triangles[i]._0].x, Normales_vertices[Triangles[i]._0].y, Normales_vertices[Triangles[i]._0].z);
				glTexCoord2f(_coordTexture[Triangles[i]._0].x, _coordTexture[Triangles[i]._0].y);
				glVertex3f(Vertices[Triangles[i]._0].x, Vertices[Triangles[i]._0].y, Vertices[Triangles[i]._0].z);
				glNormal3f(Normales_vertices[Triangles[i]._1].x, Normales_vertices[Triangles[i]._1].y, Normales_vertices[Triangles[i]._1].z);
				glTexCoord2f(_coordTexture[Triangles[i]._1].x, _coordTexture[Triangles[i]._1].y);
				glVertex3f(Vertices[Triangles[i]._1].x, Vertices[Triangles[i]._1].y, Vertices[Triangles[i]._1].z);
				glNormal3f(Normales_vertices[Triangles[i]._2].x, Normales_vertices[Triangles[i]._2].y, Normales_vertices[Triangles[i]._2].z);
				glTexCoord2f(_coordTexture[Triangles[i]._2].x, _coordTexture[Triangles[i]._2].y);
				glVertex3f(Vertices[Triangles[i]._2].x, Vertices[Triangles[i]._2].y, Vertices[Triangles[i]._2].z);
			}
			glEnd();
			break;
		}



	}
	glDisable(GL_LIGHT1);
	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

}


void O3DC::drawluz1(_mode modo,_normalMode nMode,_material material,Image* textura,GLfloat Luz1[4]){
	
	
	GLfloat Ambiente[4]={1,1,1,1};
	GLfloat luz_difusa[4] = {1.0, 1.0, 1.0, 1.0};


	glLightfv(GL_LIGHT1,GL_POSITION,Luz1);
	glLightfv (GL_LIGHT1, GL_DIFFUSE, luz_difusa);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,Ambiente);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE);
	
	GLfloat Oro_specular[4]={0.628281,0.555802,0.366065,1};
	GLfloat Oro_diffuse[4]={0.34615,0.60648,0.22648,1};
	GLfloat Oro_ambient[4]={0.24725,0.2245,0.0645,1};
	GLfloat Oro_bright=100;

	GLfloat Psilver_specular[4]={0.508273,0.508273,0.508273,1};
	GLfloat Psilver_diffuse[4]={0.50754,0.50754,0.50754,1};
	GLfloat Psilver_ambient[4]={0.19225,0.19225,0.19225,1};
	GLfloat Psilver_bright=25;

	
	GLfloat Pearl_specular[4]={0.296648,0.296648,0.296648,0.922};
	GLfloat Pearl_diffuse[4]={1.0,0.829,0.829,0.922};
	GLfloat Pearl_ambient[4]={0.25,0.20725,0.20725,0.922};
	GLfloat Pearl_bright=1;

	switch (material){
	
		case MATE1: 	
				glMaterialfv(GL_FRONT,GL_AMBIENT,(GLfloat *) &Pearl_ambient);
				glMaterialfv(GL_FRONT,GL_DIFFUSE,(GLfloat *) &Pearl_diffuse);
				glMaterialfv(GL_FRONT,GL_SPECULAR,(GLfloat *) &Pearl_specular);
				glMaterialf(GL_FRONT,GL_SHININESS,Pearl_bright);
				break;
		case MATE2: 
				glMaterialfv(GL_FRONT,GL_AMBIENT,(GLfloat *) &Oro_ambient);
				glMaterialfv(GL_FRONT,GL_DIFFUSE,(GLfloat *) &Oro_diffuse);
				glMaterialfv(GL_FRONT,GL_SPECULAR,(GLfloat *) &Oro_specular);
				glMaterialf(GL_FRONT,GL_SHININESS,Oro_bright);
				break;
	case MATE3: glMaterialfv(GL_FRONT,GL_AMBIENT,(GLfloat *) &Psilver_ambient);
				glMaterialfv(GL_FRONT,GL_DIFFUSE,(GLfloat *) &Psilver_diffuse);
				glMaterialfv(GL_FRONT,GL_SPECULAR,(GLfloat *) &Psilver_specular);
				glMaterialf(GL_FRONT,GL_SHININESS,Psilver_bright);
				break;
	}

	
	switch (nMode){
		case CARAS: {
			
			glShadeModel(GL_FLAT);
			glEnable(GL_LIGHTING);
			glEnable(GL_LIGHT1);
			init_textura2(textura);
			glBegin(GL_TRIANGLES);
			
			
			for (unsigned i=0;i<Triangles.size();i++){
				
				
				glNormal3f(Normales_caras[i].x, Normales_caras[i].y, Normales_caras[i].z);
				glTexCoord2f(_coordTexture[Triangles[i]._0].x, _coordTexture[Triangles[i]._0].y);
				glVertex3f(Vertices[Triangles[i]._0].x, Vertices[Triangles[i]._0].y, Vertices[Triangles[i]._0].z);
				glTexCoord2f(_coordTexture[Triangles[i]._1].x, _coordTexture[Triangles[i]._1].y);
				glVertex3f(Vertices[Triangles[i]._1].x, Vertices[Triangles[i]._1].y, Vertices[Triangles[i]._1].z);
				glTexCoord2f(_coordTexture[Triangles[i]._2].x, _coordTexture[Triangles[i]._2].y);
				glVertex3f(Vertices[Triangles[i]._2].x, Vertices[Triangles[i]._2].y, Vertices[Triangles[i]._2].z);
			}
			glEnd();
			
		
		break;
		}
		case VERT:{
			glShadeModel(GL_SMOOTH);
			glEnable(GL_LIGHTING);
			glEnable(GL_LIGHT1);
			init_textura2(textura);
			glBegin(GL_TRIANGLES);
			
			for (unsigned i=0;i<Triangles.size();i++){
			
				glNormal3f(Normales_vertices[Triangles[i]._0].x, Normales_vertices[Triangles[i]._0].y, Normales_vertices[Triangles[i]._0].z);
				glTexCoord2f(_coordTexture[Triangles[i]._0].x, _coordTexture[Triangles[i]._0].y);
				glVertex3f(Vertices[Triangles[i]._0].x, Vertices[Triangles[i]._0].y, Vertices[Triangles[i]._0].z);
				glNormal3f(Normales_vertices[Triangles[i]._1].x, Normales_vertices[Triangles[i]._1].y, Normales_vertices[Triangles[i]._1].z);
				glTexCoord2f(_coordTexture[Triangles[i]._1].x, _coordTexture[Triangles[i]._1].y);
				glVertex3f(Vertices[Triangles[i]._1].x, Vertices[Triangles[i]._1].y, Vertices[Triangles[i]._1].z);
				glNormal3f(Normales_vertices[Triangles[i]._2].x, Normales_vertices[Triangles[i]._2].y, Normales_vertices[Triangles[i]._2].z);
				glTexCoord2f(_coordTexture[Triangles[i]._2].x, _coordTexture[Triangles[i]._2].y);
				glVertex3f(Vertices[Triangles[i]._2].x, Vertices[Triangles[i]._2].y, Vertices[Triangles[i]._2].z);
			}
			glEnd();
			break;
		}



	}
	glDisable(GL_LIGHT1);
	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	
}

void O3DC::drawluz(_mode modo,_normalMode nMode,bool luz0,bool luz1,_material material,Image* textura,GLfloat Luz1[4]){
    
	if(luz0==true && luz1==false){
	drawluz0(SOLID,nMode,material,textura);
	}else if(luz0==false && luz1==true){
	drawluz1(SOLID,nMode,material,textura,Luz1);
	}else if(luz0==false && luz1==false){
	glDisable(GL_LIGHTING);
	draw(modo,AZUL);glEnable(GL_LIGHTING);
	}
}


O3DC::O3DC(void){
	
	

}

O3DC::O3DC(char *nombre){

	vector<_vertex3f> vertices;
    vector<_vertex3i> caras;
	_file_ply fichero;
    
	fichero.open(nombre);

    vector<float>ply_vertices;
    vector<int>ply_caras;

    fichero.read(ply_vertices,ply_caras);

  
    for (int j = 0; j < ply_vertices.size(); j+=3)
    {
        _vertex3f vert;
        vert.x = ply_vertices[j] ;
        vert.y = ply_vertices[j+1] ;
        vert.z = ply_vertices[j+2] ;

        vertices.push_back(vert);

    }

    for (int j = 0; j < ply_caras.size(); j+=3)
    {

        _vertex3i triangulo;
        triangulo._0 = ply_caras[j] ;
        triangulo._1 = ply_caras[j+1] ;
        triangulo._2 = ply_caras[j+2] ;

        caras.push_back(triangulo);

    }

    setPoints(vertices);
    setTriangulos(caras);
	
	normal_faces();
	normal_points();

}





O3DC::~O3DC(void)
{
}
