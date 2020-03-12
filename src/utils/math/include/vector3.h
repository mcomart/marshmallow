#ifndef VECTOR3_H
#define VECTOR3_H

#include "mathcommon.h"

namespace MarshMath {
    class Vector3 {
    public:
        float x;
        float y;
        float z;
    public:
        inline Vector3()
            : x(0.0f), y(0.0f), z(0.0f){};
        inline Vector3(const float cx, const float cy, const float cz) 
            : x(cx), y(cy), z(cz) {};
        inline ~Vector3() {};

        Vector3 Add(const Vector3 a, const Vector3 b);
        Vector3 Substract(const Vector3 a, const Vector3 b);
        Vector3 Multiply(const Vector3 a, const Vector3 b);
        Vector3 MultiplyWithScalar(const float scalar, const Vector3 a);
        Vector3 CrossProduct(const Vector3 a, const Vector3 b);

        float Magnitude();
        Vector3 Normalize();
    };
}
#endif