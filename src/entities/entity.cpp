#include "../include/entity.h"

Quaternion Entity::GetQuaternionFromEuler() {
    //Vamos obteniendo un cuaternión por cada eje
	Vector3 ejeX, ejeY, ejeZ;
	Quaternion quatX, quatY, quatZ, quat_res;

	ejeX.x = 1.0f;
	ejeX.y = 0.0f;
	ejeX.z = 0.0f;

	ejeY.x = 0.0f;
	ejeY.y = 1.0f;
	ejeY.z = 0.0f;

	ejeZ.x = 0.0f;
	ejeZ.y = 0.0f;
	ejeZ.z = -1.0f;

	quatX = Quaternion::QuaternionFromAngleAndAxis(eulerRotation.pitch, ejeX);
	quatY = Quaternion::QuaternionFromAngleAndAxis(eulerRotation.yaw, ejeY);
	quatZ = Quaternion::QuaternionFromAngleAndAxis(eulerRotation.roll, ejeZ);

	Quaternion quatXY = Quaternion::Multiply(quatX, quatY);
	quat_res = Quaternion::Multiply(quatXY, quatZ);

	return quat_res;
}

void Entity::SetEulerAngles(float pitch, float yaw, float roll) {
	eulerRotation.pitch = pitch;
	eulerRotation.yaw = yaw;
	eulerRotation.roll = roll;
}

Vector3 Entity::GetPosition() const {
    return position;
}

Quaternion Entity::GetRotation() const {
    return rotation;
}

Vector3 Entity::GetScale() const {
    return scale;
}

