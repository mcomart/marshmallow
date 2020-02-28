#ifndef ENTITY_H
#define ENTITY_H

#include "utils/math/marshmath.h"

class Entity {
public:
    Vector3     position;
    Quaternion  rotation;
    Vector3     scale;
public:
    virtual void Simulate();
    virtual void Render() const;
};
#endif