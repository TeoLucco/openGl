#include "O3DS.h"
#include "O3DC.h"


void O3DS::draw_points(){

glPointSize(4);


glBegin(GL_POINTS);
	
glColor3f(1,0,0);	
	
for(int i=0;i<Vertices.size();i++){
		glVertex3f(Vertices[i].x,Vertices[i].y,Vertices[i].z);
}

glEnd();
}


void O3DS::draw_points(_color color){

glPointSize(4);


glBegin(GL_POINTS);
	
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
	
for(int i=0;i<Vertices.size();i++){
		glVertex3f(Vertices[i].x,Vertices[i].y,Vertices[i].z);
}

glEnd();
}

void O3DS::setPoints(vector<_vertex3f> Vertices2){
	Vertices.resize(Vertices2.size());
	Vertices=Vertices2;

}






vector<_vertex3f> O3DS::getVertices(){
	return Vertices;
}

O3DS::O3DS(void)
{
}


O3DS::~O3DS(void)
{
}
