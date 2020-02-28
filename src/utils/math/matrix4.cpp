#include "../include/matrix3.h"
#include "../include/matrix4.h"

using namespace MarshMath;

Matrix4 MarshMath::Matrix4::Transpose() {
    Matrix4 result;

	result.m[0] = m[0];
	result.m[1] = m[4];
	result.m[2] = m[8];
	result.m[3] = m[12];

	result.m[4] = m[1];
	result.m[5] = m[5];
	result.m[6] = m[9];
	result.m[7] = m[13];

	result.m[8] = m[2];
	result.m[9] = m[6];
	result.m[10] = m[10];
	result.m[11] = m[14];

	result.m[12] = m[3];
	result.m[13] = m[7];
	result.m[14] = m[11];
	result.m[15] = m[15];

	return result;
}

Matrix4 MarshMath::Matrix4::InverseOrthogonalMatrix(Matrix3 ma, Vector3 va) {
	// A^(-1) = A^(T)b - A^(T)t (sii A ortogonal y su determinante no es 0)

	Matrix4 result;

	Matrix3 trans_ma = ma.Transpose();
	Vector3 vect_t = Matrix3::Transform(ma, va);

	result.m[0] = trans_ma.ax.x;
	result.m[1] = trans_ma.ax.y;
	result.m[2] = trans_ma.ax.z;
	result.m[3] = 0.0f;

	result.m[4] = trans_ma.ay.x;
	result.m[5] = trans_ma.ay.y;
	result.m[6] = trans_ma.ay.z;
	result.m[7] = 0.0f;

	result.m[8] = trans_ma.az.x;
	result.m[9] = trans_ma.az.y;
	result.m[10] = trans_ma.az.z;
	result.m[11] = 0.0f;

	result.m[12] = -vect_t.x;
	result.m[13] = -vect_t.y;
	result.m[14] = -vect_t.z;
	result.m[15] = 1.0f;

	return result;
}