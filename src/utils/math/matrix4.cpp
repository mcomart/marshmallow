#include "../include/matrix3.h"
#include "../include/matrix4.h"

namespace MarshMath {
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
}
