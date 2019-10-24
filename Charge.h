#pragma once
#include <functional>
#include "Vector3.h"

class Charge {
	static constexpr float k = 9e9; // Coulomb's constant, 1 / (4pi * epsilonNaught)
	static constexpr float epsilonNaught = 8.854188e-12; // Constant of vacuum permittivity 

	Vector3 position; // The position of the center of the charge
	float charge; // The total charge in coulombs
	float radius; // Radius of shapes that have it (loops, rings, disks, spheres)
	std::string chargeString; // Keeps the name of the type of charge for printing
	
public:

	// Function that returns an electric field vector due to this charge at any point
	std::function<Vector3(Vector3 testPoint)> GetEFieldAtPoint;
	// Function that returns the potential due to this charge at a certain point
	std::function<float(Vector3 testPoint)> GetPotentialAtPoint; 

	Vector3 GetPosition() { return position; }
	void SetPosition(Vector3 newPos) { position = newPos; }

	float GetCharge() { return charge; }
	void SetCharge(float newCharge) { charge = newCharge; }

	// Prints the position, charge magnitude, and type of charge
	void Print();

	// Constructors
	Charge(Vector3 pos, float charge, float radius, std::function<Vector3(Vector3)> getChargeFunc,
		   std::function<float(Vector3)> getPotentialFunc, std::string nameOfCharge);
	Charge() { position = Vector3::zero; charge = 0; radius = 0; chargeString = "Undetermined"; }

	// Creates a point charge at position pos with charge q
	static Charge Monopole(Vector3 pos, float q);

	// Creates a dipole with charges at positions negativePos and positivePos and with charges q and -q
	static Charge Dipole(Vector3 negativePos, Vector3 positivePos, float q);
	// Creates a dipole with midpoint pos and moment dipoleMoment
	static Charge Dipole(Vector3 pos, Vector3 dipoleMoment);

	/*
	static Charge Line(float q, Vector3 midpointPos, Vector3 velocity, float length);
	static Charge Line(Vector3 midpointPos, Vector3 velocity, float chargeDensisty, float length);
	static Charge InfiniteLine(Vector3 pos, Vector3 velocity, float chargeDensity);

	static Charge Loop(Vector3 centerPos, Vector3 radius, float chargeDensity);
	static Charge Loop(float charge, Vector3 centerPos, Vector3 radius);

	static Charge Disk(Vector3 centerPos, Vector3 radius, float chargeDensity);
	static Charge Disk(float charge, Vector3 centerPos, Vector3 radius);*/

	// Creates a spherical shell at centerPos with specified radius and charge
	static Charge HollowSphere(float charge, Vector3 centerPos, float radius);
	// Creates a spherical shell at centerPos with specified radius and surface charge density
	static Charge HollowSphere(Vector3 centerPos, float radius, float chargeDensity);

	// Creates a solid sphere at centerPos with specified radius and charge
	static Charge SolidSphere(float charge, Vector3 centerPos, float radius);
	// Creates a solid sphere at centerPos with specified radius and volume charge density
	static Charge SolidSphere(Vector3 centerPos, float radius, float chargeDensity);
};