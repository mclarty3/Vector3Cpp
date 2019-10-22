#pragma once

#include "Charge.h"
#include "Vector3.h"

class ChargeSystem
{
	int maxSize;
	Charge* charges;
	int currentCharges;

public:

	ChargeSystem(int maxCharges, Charge chargesToAdd[] = {}, int numCharges = 0);

	Charge GetCharge(int index);

	void AddCharge(const Charge &charge);
	void AddCharges(Charge chargesToAdd[], int numCharges);

	void RemoveCharge(int index);

	Vector3 GetTotalElectricField(const Vector3 &testPoint);
	float GetTotalPotential(const Vector3 &testPoint);
};

