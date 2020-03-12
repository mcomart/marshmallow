#ifndef MATRIX3_H
#define MATRIX3_H

#include "mathcommon.h"
#include "vector3.h"

namespace MarshMath {
    class Matrix3 {
    public:
        Vector3 ax;
        Vector3 ay;
        Vector3 az;
    public:
        inline Matrix3()
            : ax(0.0f, 0.0f, 0.0f), ay(0.0f, 0.0f, 0.0f), az(0.0f, 0.0f, 0.0f) {};
        inline Matrix3(const Vector3 vx, const Vector3 vy, const Vector3 vz) {
            ax = vx;
            ay = vy;
            az = vz;
        };
        inline ~Matrix3() {};

        static Matrix3 GetIdentityMatrix();
        
        Matrix3 Transpose();
    };
}
#endif