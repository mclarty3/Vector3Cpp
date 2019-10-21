// main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include "Vector3.h"
#include "Charge.h"
#include <iostream>

int main()
{
	// An example of what a system electric field calculator could look like!
	// Gonna finish up the other charge distributions and add potential next 
	Charge point = Charge::Monopole(Vector3(3, 0, 0), 10);
	Charge solidSphere = Charge::SolidSphere(-10, Vector3(-3, 0, 0), 1);
	Charge hollowSphere = Charge::HollowSphere(Vector3(0, 3, 0), 0.5, 0.25);
	Charge system[] = { point, solidSphere, hollowSphere };
	Vector3 totalForce;
	for (int i = 0; i < 3; i++) {
		totalForce = totalForce + system[i].getFieldAtPoint(Vector3(0, 0, 2));
	}
	std::cout << totalForce << std::endl;
}

