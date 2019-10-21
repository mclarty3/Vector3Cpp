#include "pch.h" 
#include "Charge.h"
#include <iostream>

#define PI 3.14159265358979

Charge::Charge(Vector3 pos, float q, float r, std::function<Vector3(Vector3 testPoint)> eFieldFunc,
               std::function<float(Vector3)> potentialFunc)
{
	position = pos;
	charge = q;
	radius = r;
	getEFieldAtPoint = eFieldFunc;
	getPotentialAtPoint = potentialFunc;
}

Charge Charge::Monopole(Vector3 pos, float q)
{
	std::function<Vector3(Vector3)> eFieldFunc = [pos, q](Vector3 testPoint) 
	{ 
		Vector3 dist = testPoint - pos;
		float forceMagnitude = (k * q) / dist.magnitudeSquared();
		return forceMagnitude * dist.normalized();
	};

	std::function<float(Vector3)> potentFunc = [pos, q](Vector3 testPoint)
	{
		Vector3 dist = testPoint - pos;
		return (k * q) / dist.magnitude();
	};
	return Charge(pos, q, 0, eFieldFunc, potentFunc);
}

/* I'm gonna hold off on these for this commit, I really want to figure out a general way to
   calculate electric fields for these shapes in 3D regardless of orientation. Maybe I'll need
   calculus, who knows!

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
	//std::function<Vector3(Vector3 testPoint)> eFieldFunc = []
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
*/

Charge Charge::HollowSphere(float charge, Vector3 centerPos, float radius)
{
	std::function<Vector3(Vector3)> eFieldFunc = [centerPos, radius, charge](Vector3 testPoint)
	{
		if ((testPoint - centerPos).magnitude() < radius) {
			return Vector3::zero;
		}
		Vector3 dist = testPoint - centerPos;
		return ((k * charge) / dist.magnitudeSquared()) * dist.normalized();
	};
	std::function<float(Vector3)> potentFunc = [centerPos, radius, charge](Vector3 testPoint)
	{
		if ((testPoint - centerPos).magnitude() < radius) {
			testPoint.Clamp(radius); // Sets the magnitude of the test point to the radius of the sphere
		}
		Vector3 dist = testPoint - centerPos;
		return ((k * charge) / dist.magnitude());
	};
	return Charge(centerPos, charge, radius, eFieldFunc, potentFunc);
}

Charge Charge::HollowSphere(Vector3 centerPos, float radius, float chargeDensity)
{
	float charge = chargeDensity * ((4 / 3) * PI * pow(radius, 3));
	return Charge::HollowSphere(charge, centerPos, radius);
}

Charge Charge::SolidSphere(float charge, Vector3 centerPos, float radius)
{
	float chargeDensity = charge / ((4 / 3) * PI * pow(radius, 3));
	return Charge::SolidSphere(centerPos, radius, chargeDensity);
}

Charge Charge::SolidSphere(Vector3 centerPos, float radius, float chargeDensity)
{
	float charge = 0;
	std::function<Vector3(Vector3)> eFieldFunc = [centerPos, radius, chargeDensity, &charge](Vector3 testPoint)
	{
		Vector3 dist = testPoint - centerPos;
		Vector3 force;
		if (dist.magnitude() < radius) // Inside sphere
		{
			force = ((chargeDensity * radius) / (3 * epsilonNaught)) * dist.normalized();
		}
		else {
			charge = chargeDensity * ((4 / 3) * PI * pow(radius, 3));
			force = ((((k * charge) / dist.magnitudeSquared())) * radius) * dist.normalized();
		}
		return force;
	};
	std::function<float(Vector3)> potentFunc = [centerPos, radius, chargeDensity, charge](Vector3 testPoint)
	{
		Vector3 dist = testPoint - centerPos;
		float potential;
		if (dist.magnitude() < radius) { // Inside sphere
			potential = ((k * charge) / (2 * radius)) * (3 - (dist.magnitudeSquared() / pow(radius, 2)));
		}
		else { // Outside sphere
			potential = (k * charge) / dist.magnitude();
		}
		return potential;
	};
	return Charge(centerPos, charge, radius, eFieldFunc, potentFunc);
}
