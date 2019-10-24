#pragma once

#include "Charge.h"
#include "Vector3.h"

class ChargeSystem
{
	int maxSize;		// Maximum number of charges that can be stored in the system
	Charge* charges;	// Dynamic array holding all charges in the system
	int currentCharges; // Number of charges currently in the system

public:

	ChargeSystem(int maxCharges, Charge chargesToAdd[] = {}, int numCharges = 0);

	int GetMaxCharges() { return maxSize; }
	int GetNumCharges() { return currentCharges; }

	// Returns the charge at the specified index in the system
	Charge GetCharge(int index);

	// Takes a charge as a parameter and adds it to the system, space permitting
	void AddCharge(const Charge &charge);
	// Takes an array of charges and its size as parameters and adds the charges to the system, space permitting
	void AddCharges(Charge chargesToAdd[], int numCharges);

	// Removes the charge at the specified index from the system
	void RemoveCharge(int index);

	// Prints the type, charge magnitude, and position of each charge in the system
	void PrintCharges();

	// Returns the total electric field due to the system at the specified point in R3
	Vector3 GetTotalElectricField(const Vector3 &testPoint);
	// Returns the total potential due to the system at the specified point in R3
	float GetTotalPotential(const Vector3 &testPoint);
};

