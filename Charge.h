#pragma once
#include "Vector3.h"

class Charge {

public:
	
	Charge Monopole(Vector3 position, float charge);

	Charge Dipole(Vector3 position, Vector3 dist, float charge, float charge2 = 0);
	Charge Dipole(Vector3 position1, Vector3 position2, float charge, float charge2 = 0);
	Charge Diploe(Vector3 position, Vector3 dipoleMoment);

	Charge Line(Vector3 midpointPos, Vector3 velocity, float charge);
	Charge Line(Vector3 velocity, float chargeDensisty, float length);
};