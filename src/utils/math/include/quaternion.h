#ifndef QUATERNION_H
#define QUATERNION_H

#include "mathcommon.h"
#include "vector3.h"
#include "matrix3.h"
#include "matrix4.h"

namespace MarshMath {
    class Quaternion {
    public:
        Vector3 ijk;
        float s;
    public:
        inline Quaternion()
            : ijk(0.0f, 0.0f, 0.0f), s(0.0f) {};
        inline Quaternion(const Vector3 va, const float cs) 
            : ijk(va), s(cs) {};
        inline ~Quaternion() {};

        static Quaternion QuaternionFromAngleAndAxis(float angle, Vector3 axis);
        static Quaternion QuaternionVectorFromTo(Vector3 from, Vector3 to);
        static Quaternion Multiply(Quaternion a, Quaternion b);

        Quaternion Conjugate();
        Vector3 RotateVector(Vector3 va);
        Matrix3 GetMatrix3();
        Matrix4 GetMatrix4();
    };
}
#endif