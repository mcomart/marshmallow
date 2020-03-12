#ifndef MATHOPERATIONS_H
#define MATHOPERATIONS_H

#include "vector3.h"
#include "matrix3.h"
#include "matrix4.h"
#include "mathcommon.h"

namespace MarshMath {    
    float DotProduct(Vector3 a, Vector3 b);
    Vector3 CrossProduct(Vector3 a, Vector3 b);
    Vector3 MultiplyMatrixVector(Matrix3 ma, Vector3 va);
    Matrix4 InverseOrthogonalMatrix(Matrix3 ma, Vector3 va);
    Matrix4 Multiply(Matrix4 ma, Matrix4 mb);
}

#endif