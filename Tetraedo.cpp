#include "Tetraedo.h"


Tetraedo::Tetraedo(void)
{
	#define PI (3.141592653589793)
	float radianti = 60 * PI / 180;
	float l=1;
	float h=l*sin(radianti);
	unsigned char polygon;

	Vertices.resize(4);
	Vertices[0]=_vertex3f(-(l/2), -(h/2), -(h/2));
	Vertices[1]=_vertex3f(  l/2 , -(h/2), -(h/2));
	Vertices[2]=_vertex3f(   0  , -(h/2),   h/2 );
	Vertices[3]=_vertex3f(   0  ,   h/2 ,    0  );

	Edges.resize(6);
	Edges[0]=_vertex2i(0,1);
	Edges[1]=_vertex2i(0,2);
	Edges[2]=_vertex2i(0,3);
	Edges[3]=_vertex2i(1,2);
	Edges[4]=_vertex2i(1,3);
	Edges[5]=_vertex2i(2,3);

	Triangles.resize(4);
	Triangles[0]=_vertex3i(2,1,0);
	Triangles[1]=_vertex3i(2,1,3);
	Triangles[2]=_vertex3i(0,2,3);
	Triangles[3]=_vertex3i(1,0,3);

}


Tetraedo::~Tetraedo(void)
{
}
