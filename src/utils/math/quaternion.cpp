#include "../include/quaternion.h"
#include "../include/mathoperations.h"

namespace MarshMath {
	Quaternion Quaternion::QuaternionFromAngleAndAxis(float angle, Vector3 axis) {
    	Quaternion quat;
		Vector3 axisi;
		axisi = axis.Normalize();

		float s = sin((DTOR * angle) / 2.0f);

		quat.ijk.x = axisi.x * s;
		quat.ijk.y = axisi.y * s;
		quat.ijk.z = axisi.z * s;
		quat.s = cos((DTOR * angle) / 2.0f);

		return quat;
}

	Quaternion Quaternion::QuaternionVectorFromTo(Vector3 from, Vector3 to) {
		Quaternion quat;

		float normaFrom_x_normaTo = (float)(sqrt(DotProduct(from, from) * DotProduct(to, to)));
		float parte_real = normaFrom_x_normaTo + DotProduct(from, to);

		Vector3 w;

		if (parte_real < 1.e-6f * normaFrom_x_normaTo)
		{
			//Si u y v pertenecen a la misma dirección pero poseen sentidos opuestos,
			//hay que girar 180 grados alrededor de un eje arbitrario.
			parte_real = 0.0f;

			if (abs(from.x) > abs(from.z))
			{
				w.x = -from.y;
				w.y = from.x;
				w.z = 0.0f;

				w = w.Normalize();
			}
			else
			{
				w.x = 0.0f;
				w.y = -from.z;
				w.z = from.y;

				w = w.Normalize();
			}
		}
		else
		{
			w = CrossProduct(from, to);
		}

		quat.ijk.x = w.x;
		quat.ijk.y = w.y;
		quat.ijk.z = w.z;

		quat.s = parte_real;

		return quat;
	}

	Quaternion Quaternion::Multiply(Quaternion a, Quaternion b)
	{
		//Multiplicar a*b aplica la rotación del cuaternión b al cuaternión a

		Quaternion quat;

		quat.ijk.x = a.s * b.ijk.x + a.ijk.x * b.s + a.ijk.y * b.ijk.z - a.ijk.z * b.ijk.y;
		quat.ijk.y = a.s * b.ijk.y + a.ijk.y * b.s + a.ijk.z * b.ijk.x - a.ijk.x * b.ijk.z;
		quat.ijk.z = a.s * b.ijk.z + a.ijk.z * b.s + a.ijk.x * b.ijk.y - a.ijk.y * b.ijk.x;
		quat.s = a.s * b.s - a.ijk.x * b.ijk.x - a.ijk.y * b.ijk.y - a.ijk.z * b.ijk.z;

		return quat;
	}

	Quaternion Quaternion::Conjugate() {
		//El conjugado de un cuaternión es su inverso
		Quaternion quat;

		quat.ijk.x = -ijk.x;
		quat.ijk.y = -ijk.y;
		quat.ijk.z = -ijk.z;

		quat.s = s;

		return quat;
	}

	Vector3 Quaternion::RotateVector(Vector3 va)
	{
		//Multiplicar un cuaternión q con un vector v aplica la rotación del cuaternión q al vector v
		Vector3 vec;

		Quaternion q_vector;
		q_vector.ijk.x = va.x;
		q_vector.ijk.y = va.y;
		q_vector.ijk.z = va.z;
		q_vector.s = 0.0f;

		Quaternion q_res;

		q_res = Multiply(Multiply(*this, q_vector), Conjugate());

		vec.x = q_res.ijk.x;
		vec.y = q_res.ijk.y;
		vec.z = q_res.ijk.z;

		return vec;
	}

	Matrix3 Quaternion::GetMatrix3() {
		Matrix3 ret;

		// Eje x:
		Vector3 x;
		x.x = 1.0f - 2.0f*pow(ijk.y, 2) - 2.0f*pow(ijk.z, 2);
		x.y = 2.0f*ijk.x*ijk.y - 2.0f*ijk.z*s;
		x.z = 2.0f*ijk.x*ijk.z + 2.0f*ijk.y*s;

		ret.ax = x;

		// Eje y:
		Vector3 y;
		y.x = 2.0f*ijk.x*ijk.y + 2.0f*ijk.z*s;
		y.y = 1.0f - 2.0f*pow(ijk.x, 2) - 2.0f*pow(ijk.z, 2);
		y.z = 2.0f*ijk.y*ijk.z - 2.0f*ijk.x*s;

		ret.ay = y;

		// Eje z
		Vector3 z;
		z.x = 2.0f*ijk.x*ijk.z - 2.0f*ijk.y*s;
		z.y = 2.0f*ijk.y*ijk.z + 2.0f*ijk.x*s;
		z.z = 1.0f - 2.0f*pow(ijk.x, 2) - 2.0f*pow(ijk.y, 2);

		ret.az = z;

		return ret;
	}

	Matrix4 Quaternion::GetMatrix4() {
		//Trabajamos con las matrices en columnas, a la manera de OpenGL
		Matrix4 ret;
		
		//Col 1
		ret.m[0] = 1.0f - 2.0f*pow(ijk.y, 2) - 2.0f*pow(ijk.z, 2);
		ret.m[4] = 2.0f*ijk.x*ijk.y - 2.0f*ijk.z*s;
		ret.m[8] = 2.0f*ijk.x*ijk.z + 2.0f*ijk.y*s;
		ret.m[12] = 0.0f;

		//Col 2
		ret.m[1] = 2.0f*ijk.x*ijk.y + 2.0f*ijk.z*s;
		ret.m[5] = 1.0f - 2.0f*pow(ijk.x, 2) - 2.0f*pow(ijk.z, 2);
		ret.m[9] = 2.0f*ijk.y*ijk.z - 2.0f*ijk.x*s;
		ret.m[13] = 0.0f;

		//Col 3
		ret.m[2] = 2.0f*ijk.x*ijk.z - 2.0f*ijk.y*s;
		ret.m[6] = 2.0f*ijk.y*ijk.z + 2.0f*ijk.x*s;
		ret.m[10] = 1.0f - 2.0f*pow(ijk.x, 2) - 2.0f*pow(ijk.y, 2);
		ret.m[14] = 0.0f;

		ret.m[3] = 0.0f;
		ret.m[7] = 0.0f;
		ret.m[11] = 0.0f;
		ret.m[15] = 1.0f;
		
		return ret;
	}
}

