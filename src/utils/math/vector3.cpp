#include "../include/vector3.h"

using namespace MarshMath;

Vector3 Vector3::Add(const Vector3 a, const Vector3 b)
{
	Vector3 result;
	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	return result;
}

Vector3 Vector3::Substract(const Vector3 a, const Vector3 b)
{
	Vector3 result;
	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	return result;
}

Vector3 Vector3::Multiply(const Vector3 a, const Vector3 b)
{
	Vector3 result;
	result.x = a.x*b.x;
	result.y = a.y*b.y;
	result.z = a.z*b.z;
	return result;
}

Vector3 Vector3::MultiplyWithScalar(const float scalar, const Vector3 a)
{
	Vector3 result;
	result.x = a.x*scalar;
	result.y = a.y*scalar;
	result.z = a.z*scalar;
	return result;
}

float Vector3::Magnitude(const Vector3 a)
{
	float result;
	result = sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
	return result;
}

Vector3 Vector3::Normalize(const Vector3 a)
{
	Vector3 result;
	result.x = a.x / Magnitude(a);
	result.y = a.y / Magnitude(a);
	result.z = a.z / Magnitude(a);
	return result;
}

Vector3 Vector3::CrossProduct(Vector3 a, Vector3 b)
{
	Vector3 result;
	result.x = a.y * b.z - b.y * a.z;
	result.y = a.z * b.x - b.z * a.x;
	result.z = a.x * b.y - b.x * a.y;
	return result;
}

float Vector3::DotProduct(Vector3 a, Vector3 b)
{
	float result;
	result = a.x * b.x + a.y * b.y + a.z * b.z;
	return result;
}