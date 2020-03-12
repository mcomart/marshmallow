#include "../include/vector3.h"

namespace MarshMath {
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

	float Vector3::Magnitude()
	{
		float result;
		result = sqrt(x*x + y*y + z*z);
		return result;
	}

	Vector3 Vector3::Normalize()
	{
		Vector3 result;
		result.x = x / Magnitude();
		result.y = y / Magnitude();
		result.z = z / Magnitude();
		return result;
	}
}
