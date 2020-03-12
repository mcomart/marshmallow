#ifndef ENTITY_H
#define ENTITY_H

#include "../utils/math/include/marshmath.h"

typedef struct {
	float yaw;					// Rotation around the Y axis.
	float pitch;				// Rotation around the X axis.
	float roll;					// Rotation around the Z axis.
} Euler;

class Entity {
public:
    Entity() : scale(1.0f, 1.0f, 1.0f) { 
        eulerRotation.yaw = 0.0f;
        eulerRotation.pitch = 0.0f;
        eulerRotation.roll = 0.0f;

        rotation = GetQuaternionFromEuler();
    };
    ~Entity() {};

    void SetEulerAngles(float pitch, float yaw, float roll);

    Quaternion GetQuaternionFromEuler();

    Vector3 GetPosition() const;
    Quaternion GetRotation() const;
    Vector3 GetScale() const; 

    void Update();
    // virtual void Render() const;
protected:
    Vector3     position;
    Euler       eulerRotation;
    Quaternion  rotation;
    Vector3     scale;
};
#endif