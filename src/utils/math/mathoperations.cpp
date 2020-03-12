#include "../include/mathoperations.h"

namespace MarshMath {    
    float DotProduct(Vector3 a, Vector3 b) {
	    float result;
	    result = a.x * b.x + a.y * b.y + a.z * b.z;
	    return result;
    }

    Vector3 CrossProduct(Vector3 a, Vector3 b) {
	    Vector3 result;
	    result.x = a.y * b.z - b.y * a.z;
	    result.y = a.z * b.x - b.z * a.x;
	    result.z = a.x * b.y - b.x * a.y;
	    return result;
    }

    Vector3 MultiplyMatrixVector(Matrix3 ma, Vector3 va) {
	    //result = ma*va

	    Matrix3 trans = ma.Transpose();

	    Vector3 result;

	    result.x = trans.ax.x*va.x + trans.ax.y*va.y + trans.ax.z*va.z;
	    result.y = trans.ay.x*va.x + trans.ay.y*va.y + trans.ay.z*va.z;
	    result.z = trans.ay.x*va.x + trans.ay.y*va.y + trans.ay.z*va.z;

	    return result;
    }

    Matrix4 InverseOrthogonalMatrix(Matrix3 ma, Vector3 va) {
        // A^(-1) = A^(T)b - A^(T)t (sii A ortogonal y su determinante no es 0)

        Matrix4 result;

        Matrix3 trans_ma = ma.Transpose();
        Vector3 vect_t = MultiplyMatrixVector(ma, va);

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

    Matrix4 Multiply(Matrix4 ma, Matrix4 mb) {
        Matrix4 result;

        result.m[0] = ma.m[0] * mb.m[0] + ma.m[1] * mb.m[4] + ma.m[2] * mb.m[8] + ma.m[3] * mb.m[12];
        result.m[1] = ma.m[0] * mb.m[1] + ma.m[1] * mb.m[5] + ma.m[2] * mb.m[9] + ma.m[3] * mb.m[13];
        result.m[2] = ma.m[0] * mb.m[2] + ma.m[1] * mb.m[6] + ma.m[2] * mb.m[10] + ma.m[3] * mb.m[14];
        result.m[3] = ma.m[0] * mb.m[3] + ma.m[1] * mb.m[7] + ma.m[2] * mb.m[11] + ma.m[3] * mb.m[15];

        result.m[4] = ma.m[4] * mb.m[0] + ma.m[5] * mb.m[4] + ma.m[6] * mb.m[8] + ma.m[7] * mb.m[12];
        result.m[5] = ma.m[4] * mb.m[1] + ma.m[5] * mb.m[5] + ma.m[6] * mb.m[9] + ma.m[7] * mb.m[13];
        result.m[6] = ma.m[4] * mb.m[2] + ma.m[5] * mb.m[6] + ma.m[6] * mb.m[10] + ma.m[7] * mb.m[14];
        result.m[7] = ma.m[4] * mb.m[3] + ma.m[5] * mb.m[7] + ma.m[6] * mb.m[11] + ma.m[7] * mb.m[15];

        result.m[8] = ma.m[8] * mb.m[0] + ma.m[9] * mb.m[4] + ma.m[10] * mb.m[8] + ma.m[11] * mb.m[12];
        result.m[9] = ma.m[8] * mb.m[1] + ma.m[9] * mb.m[5] + ma.m[10] * mb.m[9] + ma.m[11] * mb.m[13];
        result.m[10] = ma.m[8] * mb.m[2] + ma.m[9] * mb.m[6] + ma.m[10] * mb.m[10] + ma.m[11] * mb.m[14];
        result.m[11] = ma.m[8] * mb.m[3] + ma.m[9] * mb.m[7] + ma.m[10] * mb.m[11] + ma.m[11] * mb.m[15];

        result.m[12] = ma.m[12] * mb.m[0] + ma.m[13] * mb.m[4] + ma.m[14] * mb.m[8] + ma.m[15] * mb.m[12];
        result.m[13] = ma.m[12] * mb.m[1] + ma.m[13] * mb.m[5] + ma.m[14] * mb.m[9] + ma.m[15] * mb.m[13];
        result.m[14] = ma.m[12] * mb.m[2] + ma.m[13] * mb.m[6] + ma.m[14] * mb.m[10] + ma.m[15] * mb.m[14];
        result.m[15] = ma.m[12] * mb.m[3] + ma.m[13] * mb.m[7] + ma.m[14] * mb.m[11] + ma.m[15] * mb.m[15];

        return result;
    }
}
