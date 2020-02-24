#include "matrix3.h"

using namespace MarshMath;

Matrix3 Matrix3::Transpose()
{
	Matrix3 result;

	result.ax.x = ax.x;
	result.ax.y = ay.x;
	result.ax.z = az.x;

	result.ay.x = ax.y;
	result.ay.y = ay.y;
	result.ay.z = az.y;

	result.az.x = ax.z;
	result.az.y = ay.z;
	result.az.z = az.z;

	return result;
}

Vector3 Matrix3::Transform(Matrix3 ma, Vector3 va)
{
	//result = ma*va

	Matrix3 trans = ma.Transpose();

	Vector3 result;

	result.x = trans.ax.x*va.x + trans.ax.y*va.y + trans.ax.z*va.z;
	result.y = trans.ay.x*va.x + trans.ay.y*va.y + trans.ay.z*va.z;
	result.z = trans.ay.x*va.x + trans.ay.y*va.y + trans.ay.z*va.z;

	return result;
}