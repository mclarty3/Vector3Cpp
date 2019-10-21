#pragma once
#include <functional>
#include "Vector3.h"

class Charge {

	Vector3 position; // The position of the center of the charge
	float charge; // The total charge in coulombs
	float radius; // Radius of shapes that have it (loops, rings, disks, spheres)
	static constexpr float k = 9e9; // Coulomb's constant, 1 / (4pi * epsilonNaught)
	static constexpr float epsilonNaught = 8.854188e-12; // Constant of vacuum permittivity 
	
public:

	// Function that returns an electric field vector at any point
	std::function<Vector3(Vector3 testPoint)> getEFieldAtPoint;
	// Function that returns the potential at a certain point
	std::function<float(Vector3 testPoint)> getPotentialAtPoint; 

	Charge(Vector3 pos, float charge, float radius, std::function<Vector3(Vector3)> getChargeFunc,
		   std::function<float(Vector3)> getPotentialFunc);
	Charge() { position = Vector3::zero; charge = 0; radius = 0; }

	static Charge Monopole(Vector3 pos, float q);
	/*
	static Charge Dipole(Vector3 pos1, Vector3 pos2, float q, float q2 = 0);
	static Charge Dipole(Vector3 pos, Vector3 dipoleMoment);

	static Charge Line(float q, Vector3 midpointPos, Vector3 velocity, float length);
	static Charge Line(Vector3 midpointPos, Vector3 velocity, float chargeDensisty, float length);
	static Charge InfiniteLine(Vector3 pos, Vector3 velocity, float chargeDensity);

	static Charge Loop(Vector3 centerPos, Vector3 radius, float chargeDensity);
	static Charge Loop(float charge, Vector3 centerPos, Vector3 radius);

	static Charge Disk(Vector3 centerPos, Vector3 radius, float chargeDensity);
	static Charge Disk(float charge, Vector3 centerPos, Vector3 radius);*/

	static Charge HollowSphere(float charge, Vector3 centerPos, float radius);
	static Charge HollowSphere(Vector3 centerPos, float radius, float chargeDensity);

	static Charge SolidSphere(float charge, Vector3 centerPos, float radius);
	static Charge SolidSphere(Vector3 centerPos, float radius, float chargeDensity);
};