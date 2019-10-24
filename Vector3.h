#pragma once 

#include <math.h> 
#include <iostream> 

class Vector3 {

public:
	static Vector3 forward;	 // <0, 0, 1>
	static Vector3 backward; // <0, 0, -1> 
	static Vector3 left;	 // <-1, 0, 0>
	static Vector3 right;	 // <1, 0, 0>
	static Vector3 up;	     // <0, 1, 0>
	static Vector3 down;	 // <0, -1, 0>
	static Vector3 zero;     // <0, 0, 0>
	static Vector3 infinity; // <inf, inf, inf>

	// Returns dot product of v1 and v2
	static float Dot(const Vector3 v1, const Vector3 v2); 
	// Returns cross product of v1 and v2
	static Vector3 Cross(const Vector3 v1, const Vector3 v2);
	// Returns angle between v1 and v2
	static float Angle(Vector3 v1, const Vector3 v2);
	// Returns distance between tips of v1 and v2
	static float Distance(const Vector3 v1, const Vector3 v2);
	// Returns midpoint between v1 and v2
	static Vector3 Midpoint(const Vector3 v1, const Vector3 v2);
	// Returns projection of v1 onto v2
	static Vector3 Project(const Vector3 v1, const Vector3 v2);
	// Returns reflection of v1 onto v2
	static Vector3 Reflect(const Vector3 v1, const Vector3 v2);

	Vector3 operator*(float n) const { return Vector3(n * x, n * y, n * z); } 
	friend Vector3 operator*(float n, const Vector3 vect) { return Vector3(n * vect.x, n * vect.y, n * vect.z); } 
	Vector3 operator/(float n) const { return Vector3(x / n, y / n, z / n); } 
	Vector3 operator+(const Vector3 other) const { return Vector3(x + other.x, y + other.y, z + other.z); } 
	Vector3 operator-(const Vector3 other) const { return Vector3(x - other.x, y - other.y, z - other.z); } 
	void operator=(const Vector3 v2) { x = v2.x; y = v2.y; z = v2.z; } 
	bool operator==(const Vector3 other) const { return (x == other.x) && (y == other.y) && (z == other.z); } 
	bool operator!=(const Vector3 other) const { return !(*this == other); } 
	friend std::ostream& operator<<(std::ostream& os, const Vector3 &v);

	float x; 
	float y; 
	float z;

	Vector3() { x = 0; y = 0; z = 0; }
	Vector3(float x_value, float y_value, float z_value) { x = x_value; y = y_value; z = z_value; }
	Vector3(Vector3 direction, float length);

	// Returns magnitude of vector
	float magnitude() const; 
	// Returns magnitude squared of vector
	float magnitudeSquared() const; 
	// Returns normalized version of vector
	Vector3 normalized() const; 
	// Normalizes vector
	void Normalize();
	// Clamps vector to magnitude of n
	void Clamp(float n);
};