#ifndef MATRIX4_H
#define MATRIX4_H

#include "mathcommon.h"
#include "vector3.h"

namespace MarshMath {
    // OpenGL friendly
    class Matrix4 {
    public:
        float m[16];
    public:
        inline Matrix4() {
            for (int i = 0; i < 16; i++) {
                m[i] = 0.0f;
            }
        }
        inline Matrix4(const Vector3 vx, const Vector3 vy, const Vector3 vz, const Vector3 t) {
            // vector x
            m[0] = vx.x;
            m[4] = vx.y;
            m[8] = vx.z;
            m[12] = 0.0f;

            // vector y
            m[1] = vy.x;
            m[5] = vy.y;
            m[9] = vy.z;
            m[13] = 0.0f;

            // vector z
            m[2] = vz.x;
            m[6] = vz.y;
            m[10] = vz.z;
            m[14] = 0.0f;

            // last column
            m[3] = t.x;
            m[7] = t.y;
            m[11] = t.z;
            m[15] = 1.0f;
        };
        inline ~Matrix4(){};

        static Matrix4 InverseOrthogonalMatrix(Matrix3 ma, Vector3 va);

        // float* GetArray() { return &m[0]; };
        Matrix4 Transpose();
    };
}
#endif