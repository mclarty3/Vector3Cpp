#include "pch.h" 
#include "Charge.h"

Charge::Charge(Vector3 pos, float q, float r, std::function<Vector3(Vector3 testPoint)> eFieldFunc)
{
	position = pos;
	charge = q;
	radius = r;
	getFieldAtPoint = eFieldFunc;
}

Charge Charge::Monopole(Vector3 pos, float q)
{
	std::function<Vector3(Vector3 test)> eFieldFunc = [pos, q](Vector3 test) 
	{ 
		Vector3 dist = test - pos;
		float forceMagnitude = (k * q) / dist.magnitudeSquared();
		return forceMagnitude * dist.normalized();
	};
	return Charge(pos, q, 0, eFieldFunc);
}

//TO-DO: Make this so that it calculates the force for both charges individually and adds them (way easier)
/* I don't like the way this is done, because it won't work in three dimensions unless the 
   test point is in the plane perpendicular to the dipole moment*/
Charge Charge::Dipole(Vector3 pos1, Vector3 pos2, float q, float q2)
{
	// Defaults to dipole with equal but opposite charges
	if (q2 == 0) {
		q2 = -q;
	}
	else {
		q2 = q; // Fix this
	}

	Vector3 dipoleMoment = (pos2 - pos1) * q;
	Vector3 midPoint = Vector3::Midpoint(pos1, pos2);
	float a = 0.5 * (pos2 - pos1).magnitude();
	std::function<Vector3(Vector3 testPoint)> eFieldFunc = [dipoleMoment, midPoint, a, q](Vector3 testPoint)
	{
		float xDistance = (testPoint - midPoint).x;
		float yDistance = (testPoint - midPoint).y;
		float xMag = (k * q) * ((xDistance / pow(pow(yDistance, 2) + pow(xDistance, 2), 1.5f)) - (xDistance / pow(pow(yDistance - 2 * a, 2) + pow(xDistance, 2), 1.5f)));
		float yMag = (k * q) * ((yDistance / pow(pow(yDistance, 2) + pow(xDistance, 2), 1.5f)) - ((yDistance - 2 * a) / pow(pow(yDistance - 2 * a, 2) + pow(xDistance, 2), 1.5f)));
		return Vector3(xMag, yMag, 0);
	};
	return Charge(midPoint, q + q2, 0, eFieldFunc);
}

Charge Charge::Dipole(Vector3 pos, Vector3 dipoleMoment)
{
	return Charge();
}

Charge Charge::Line(float q, Vector3 midpointPos, Vector3 velocity, float length)
{
	return Charge();
}

Charge Charge::Line(Vector3 midpointPos, Vector3 velocity, float chargeDensisty, float length)
{
	return Charge();
}

Charge Charge::InfiniteLine(Vector3 pos, Vector3 velocity, float chargeDensity)
{
	return Charge();
}

Charge Charge::Loop(Vector3 centerPos, Vector3 radius, float chargeDensity)
{
	return Charge();
}

Charge Charge::Loop(float charge, Vector3 centerPos, Vector3 radius)
{
	return Charge();
}

Charge Charge::Disk(Vector3 centerPos, Vector3 radius, float chargeDensity)
{
	return Charge();
}

Charge Charge::Disk(float charge, Vector3 centerPos, Vector3 radius)
{
	return Charge();
}

Charge Charge::Sphere(float charge, Vector3 centerPos, Vector3 radius)
{
	return Charge();
}

Charge Charge::Sphere(Vector3 centerPos, Vector3 radius, float chargeDensity)
{
	return Charge();
}
