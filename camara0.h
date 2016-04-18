#include "vertex.h"
#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include <vector>


#pragma once
class camara0
{
public:
	void switch_projection(GLfloat Window_width,GLfloat WindowWidth,GLfloat Window_heightRatio,GLfloat Window_wideRatio,GLfloat Front_plane,GLfloat Back_plane,bool camara1);
	camara0(void);
	~camara0(void);
};

