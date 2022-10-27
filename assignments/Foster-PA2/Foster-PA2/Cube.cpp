#include "Cube.h"
void Cube::createVertices()
{	//6 floats, 2 vertex per indiex, [0] pos [1] col
	Vertices = {
				//8 vertices 
				{{1.0f, -1.0f, -1.0f}, {0.0f, 0.0f, 0.0f}},
				{{1.0f, -1.0f, 1.0f}, {1.0f, 0.0f, 0.0f}},
				{{-1.0f, -1.0f, 1.0f}, {0.0f, 1.0f, 0.0f}},
				{{-1.0f, -1.0f, -1.0f}, {0.0f, 0.0f, 1.0f}},

				{ {1.0f, 1.0f, -1.0f}, {1.0f, 1.0f, 0.0f}},
				{ {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f, 1.0f}},
				{ {-1.0f, 1.0f, 1.0f}, {0.0f, 1.0f, 1.0f}},
				{{-1.0f, 1.0f, -1.0f}, {1.0f, 1.0f, 1.0f}}
	};
	//6 faces, 2 triangles per
	Indices =  
	{
	  2,3,4,
	  8,7,6,
	  1,5,6,
	  2,6,7,
	  7,8,4,
	  1,4,8,
	  1,2,4,
	  5,8,6,
	  2,1,6,
	  3,2,7,
	  3,7,4,
	  5,1,8

	};
	for (unsigned int i = 0; i < Indices.size(); i++)
	{
		Indices[i] = Indices[i] - 1;
	}
}
void Cube::Update(long long dt)
{
	model *= glm::rotate(glm::mat4(1.0f), angle * dt, glm::vec3(0, 1.0f, .0f));
}