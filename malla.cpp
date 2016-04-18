#include "malla.h"
#include "imageloader.h"


malla::malla(int n){

	//Vertices.resize(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			_vertex3f vert;
			vert.y = 3*j;
			vert.x = 3*i;
			vert.z = 0;

			Vertices.push_back(vert);
		}
	}
	for (int i = 0; i < n-1; i++){
		int primero1, primero2;
		primero1 = i * n;
		primero2 = primero1 + n;
		
		//Genero las caras
		for (int z = primero1 +1, k = primero2+1; z < primero2; z++, k++){
            Triangles.push_back(_vertex3i(z-1, k-1, k));
            Triangles.push_back(_vertex3i(z-1, k,   z));
        }
	}

	/*int ncaras=(n*n)-1;
	for (int z = 0, k = n; k < n-1; z++, k++){
		Triangles.push_back(_vertex3i(z, k, k+1));
		Triangles.push_back(_vertex3i(k+1, z+1,z));
	}*/
    
	CreateCoordTexture1(Vertices.size());

}

void malla::aplicatex(int mallai,int mallaancho,int texti,int textancho,Image* text){
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D (GL_TEXTURE_2D, 0, GL_RGB, text->width, text->height, 0, GL_RGB, GL_UNSIGNED_BYTE, text->pixels);
	glEnable(GL_TEXTURE_2D);
	
	glBegin(GL_QUADS);
		//glTexCoord2f(_coordTexture2[texti+textancho].x, _coordTexture2[texti].y);
		//glVertex3f(Vertices[mallai+textancho].x, Vertices[mallai].y, 0);

		//glTexCoord2f(_coordTexture2[texti+textancho].x, _coordTexture2[texti].y);
		//glVertex3f(Vertices[mallai+textancho].x, Vertices[mallai].y, 0);

		//glTexCoord2f(_coordTexture2[texti+textancho].x, _coordTexture2[texti+textancho].y);
		//glVertex3f(Vertices[mallai+textancho].x, Vertices[mallai+textancho].y, 0);

		//glTexCoord2f(_coordTexture2[texti].x, _coordTexture2[texti+textancho].y);
		//glVertex3f(Vertices[mallai].x, Vertices[mallai+textancho].y, 0);

	glEnd();
	
	glDisable(GL_TEXTURE_2D);
}


void malla::CreateCoordTexture1(int numVertices) {
	
	int ancho=sqrt(numVertices);
	float dist=1/(float(ancho)-1);
	_vertex2f pos(0,0);
	for(int i=0;i<ancho;i++){
			for(int j=0;j<ancho;j++){
				_vertex2f vert;
				vert.y = pos.y;
				vert.x = pos.x;
				pos.y=vert.y+dist;
				_coordTexture2.push_back(vert);
			}
			pos.x=pos.x+dist;
			pos.y=0;

	}
	
}






malla::~malla(void)
{
}
