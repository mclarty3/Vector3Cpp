#pragma once

#include "Vector3.h"

class VectorField
{
private:
	

public:
	VectorField();
	~VectorField();

	Vector3 GetVectAt(float x, float y, float z);
};
// TO-DO: Find a way to parse through a string and determine the vector field function
F(x,y,z) = <3x + y, 4, z / 3>
		 = x<3, 0, 0> + y<1, 0, 0> + z<0, 0, (1/3)> + <0, 4, 0>