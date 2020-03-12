#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "../include/entity.h"

class RigidBody : public Entity {
public:
    /* Constant quantities */
    double mass;
    Matrix3 IBody;
    Matrix3 IBodyInv;

    /* State variables */
    Vector3 x;
    Matrix3 R;
    Vector3 P;
    Vector3 L;

    /* Derived quantities (auxiliary) */
    Matrix3 Iinv;
    Vector3 v;
    Vector3 omega;

    /* Computed quantities */
    Vector3 force;
    Vector3 torque;
public:
    void Simulate();
    void Render();
};
#endif