#include "../include/matrix3.h"

namespace MarshMath {
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

	Matrix3 Matrix3::GetIdentityMatrix() {
		Matrix3 identity;

		identity.ax.x = 1.0f;
		identity.ay.y = 1.0f;
		identity.az.z = 1.0f;

		return identity;
	}
}
