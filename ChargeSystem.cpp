#include "pch.h"
#include "ChargeSystem.h"
#include <iostream>

ChargeSystem::ChargeSystem(int maxCharges, Charge chargesToAdd[], int numCharges)
{
	maxSize = maxCharges;
	charges = new Charge[maxCharges];
	currentCharges = 0;

	if (numCharges > 0) {
		for (int i = 0; i < numCharges; i++) {
			AddCharge(chargesToAdd[i]);
		}
	}
}

Charge ChargeSystem::GetCharge(int index)
{
	if (index < currentCharges) {
		return charges[index];
	}
	else {
		std::cout << "Index is out of range!" << std::endl;
	}
}

void ChargeSystem::AddCharge(const Charge &charge)
{
	if (currentCharges < maxSize) {
		charges[currentCharges] = charge;
		currentCharges++;
	}
	else {
		std::cout << "System is full!" << std::endl;
	}
}

void ChargeSystem::AddCharges(Charge chargesToAdd[], int numCharges)
{
	if (numCharges + currentCharges <= maxSize) {
		for (int i = 0; i < numCharges; i++) {
			AddCharge(chargesToAdd[i]);
		}
	}
	else {
		std::cout << "Not enough space for these charges!" << std::endl;
	}
}

void ChargeSystem::RemoveCharge(int index)
{
	if (index >= 0 && index < currentCharges) {
		for (int i = index; i < currentCharges - 1; i++) {
			charges[i] = charges[i + 1];
		}
		currentCharges--;
	}
	else {
		std::cout << "Index out of range!" << std::endl;
	}
}

void ChargeSystem::PrintCharges()
{
	for (int i = 0; i < currentCharges; i++) {
		charges[i].Print();
	}
}

Vector3 ChargeSystem::GetTotalElectricField(const Vector3 &testPoint)
{
	Vector3 totalEField;
	for (int i = 0; i < currentCharges; i++) {
		totalEField = totalEField + charges[i].GetEFieldAtPoint(testPoint);
	}
	return totalEField;
}

float ChargeSystem::GetTotalPotential(const Vector3 &testPoint)
{
	float totalPotential = 0;
	for (int i = 0; i < currentCharges; i++) {
		totalPotential += charges[i].GetPotentialAtPoint(testPoint);
	}
	return totalPotential;
}