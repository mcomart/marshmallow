#ifndef QUATERNION_H
#define QUATERNION_H

#include "mathcommon.h"
#include "vector3.h"

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
    };
}
#endif