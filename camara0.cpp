#include "camara0.h"
#include "vertex.h"
#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include <vector>

void camara0::switch_projection(GLfloat Window_width,GLfloat WindowWidth,GLfloat Window_heightRatio,GLfloat Window_wideRatio,GLfloat Front_plane,GLfloat Back_plane,bool camara1){

	if(camara1==true){
		
		glFrustum(Window_width,Window_width,Window_heightRatio,Window_wideRatio,Front_plane,Back_plane);
	}else{

		glOrtho(Window_width,Window_width,Window_heightRatio,Window_wideRatio,Front_plane,Back_plane);

	}

}

camara0::camara0(void)
{
}


camara0::~camara0(void)
{
}
