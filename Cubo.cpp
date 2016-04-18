#include "Cubo.h"


Cubo::Cubo(void)
{
	Vertices.resize(8);
	Vertices[0]=_vertex3f(0.5,0.5,0.5);
	Vertices[1]=_vertex3f(0.5,0.5,-0.5);
	Vertices[2]=_vertex3f(0.5,-0.5,0.5);
	Vertices[3]=_vertex3f(0.5,-0.5,-0.5);
	Vertices[4]=_vertex3f(-0.5,0.5,0.5);
	Vertices[5]=_vertex3f(-0.5,0.5,-0.5);
	Vertices[6]=_vertex3f(-0.5,-0.5,-0.5);
    Vertices[7]=_vertex3f(-0.5,-0.5,0.5);

	Edges.resize(12);
	Edges[0]=_vertex2i(0,1);
	Edges[1]=_vertex2i(0,2);
	Edges[2]=_vertex2i(0,4);
	Edges[3]=_vertex2i(1,3);
	Edges[4]=_vertex2i(1,5);
	Edges[5]=_vertex2i(2,3);
	Edges[6]=_vertex2i(2,7);
	Edges[7]=_vertex2i(3,6);
	Edges[8]=_vertex2i(4,5);
	Edges[9]=_vertex2i(5,6);
	Edges[10]=_vertex2i(6,7);
	Edges[11]=_vertex2i(4,7);

	Triangles.resize(12);
	Triangles[0]=_vertex3i(5,1,0);
	Triangles[1]=_vertex3i(0,4,5);
	Triangles[2]=_vertex3i(0,1,3);
	Triangles[3]=_vertex3i(3,2,0);
	Triangles[4]=_vertex3i(4,0,2);
	Triangles[5]=_vertex3i(2,7,4);
	Triangles[6]=_vertex3i(6,3,1);
	Triangles[7]=_vertex3i(1,5,6);
	Triangles[8]=_vertex3i(6,5,4);
	Triangles[9]=_vertex3i(4,7,6);
	Triangles[10]=_vertex3i(3,6,7);
	Triangles[11]=_vertex3i(7,2,3);

	
	normal_faces();
	normal_points();

}


Cubo::~Cubo(void)
{
}
