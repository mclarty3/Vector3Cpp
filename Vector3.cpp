#include "pch.h" 
#include "Vector3.h" 

Vector3 Vector3::forward = Vector3(0, 0, 1); 
Vector3 Vector3::backward = Vector3(0, 0, -1); 
Vector3 Vector3::left = Vector3(-1, 0, 0); 
Vector3 Vector3::right = Vector3(1, 0, 0); 
Vector3 Vector3::up = Vector3(0, 1, 0); 
Vector3 Vector3::down = Vector3(0, -1, 0); 
Vector3 Vector3::zero = Vector3(0, 0, 0);
Vector3 Vector3::infinity = Vector3(INFINITY, INFINITY, INFINITY);

Vector3::Vector3(Vector3 direction, float length)
{
	Vector3 velocity = direction.normalized();
	x = velocity.x * length;
	y = velocity.y * length;
	z = velocity.z * length;
}

float Vector3::Dot(const Vector3 v1, const Vector3 v2) 
{ 
	return (v1.x * v2.x) + (v1.y + v2.y) + (v1.z + v2.z); 
}

Vector3 Vector3::Cross(const Vector3 v1, const Vector3 v2)
{ 
	return Vector3((v1.y * v2.z) - (v1.z * v2.y), (v1.z * v2.x) - (v1.x * v2.z), (v1.x * v2.y) - (v1.y * v2.x)); 
}

float Vector3::Angle(const Vector3 v1, const Vector3 v2)
{ 
	return acos(Dot(v1, v2) / (v1.magnitude() * v2.magnitude())); 
}

float Vector3::Distance(const Vector3 v1, const Vector3 v2)
{ 
	Vector3 dist = v1 - v2; 
	return dist.magnitude(); 
}

Vector3 Vector3::Midpoint(const Vector3 v1, const Vector3 v2)
{
	Vector3 midpoint = 0.5f * (v2 - v1);
	return v1 + midpoint;
}

Vector3 Vector3::Project(const Vector3 a, const Vector3 b)
{ 
	return a * (Dot(a, b) / a.magnitudeSquared()); 
}

Vector3 Vector3::Reflect(const Vector3 a, const Vector3 b)
{ 
	return a - (2 * Dot(a, b.normalized()) * b.normalized()); 
}

float Vector3::magnitude() const
{ 
	return sqrt(abs(Dot(*this, *this))); 
	
}

float Vector3::magnitudeSquared() const 
{ 
	return abs(Dot(*this, *this)); 
}

Vector3 Vector3::normalized() const
{ 
	return *this / this->magnitude();
}

void Vector3::Normalize() 
{ 
	*this = *this / this->magnitude();
}

void Vector3::Clamp(float n)
{
	*this = this->normalized() * n;
}

std::ostream & operator<<(std::ostream & os, const Vector3 & v)
{
	os << "<" << v.x << ", " << v.y << ", " << v.z << ">"; return os;
}

