#include "../include/camera.h"

Camera::Camera() {
    aperture = 45.0f;

	position.x = 0.0f;
	position.y = 0.0f;
	position.z = 20.0f;

    up = GetUpVector();
}

Vector3 Camera::GetUpVector() {
    return rotation.GetMatrix3().ay;
}

void Camera::SetFrustum(double near, double far) {
    double scale = tan(aperture * 0.5 * PI / 180) * near;
    double aspect = screenwidth / screenheight;

    frustum.near = near;
    frustum.far = far;
    frustum.right = aspect * scale;
    frustum.left = -frustum.right;
    frustum.top = scale;
    frustum.bottom = -frustum.top;
}

Matrix4 Camera::GetLookAt(Vector3 target) {
    Matrix4 ret;

	Vector3 ejeZ, ejeY, ejeX;

	//Eje Z -> "forward" --> es "camera.direction"
	ejeZ.x = target.x - position.x;
	ejeZ.y = target.y - position.y;
	ejeZ.z = target.z - position.z;

	ejeZ = ejeZ.Normalize();

	//Eje X -> "side"
	ejeX = CrossProduct(up, ejeZ);

	ejeX = ejeX.Normalize();

	//Eje Y -> "up"
	ejeY = CrossProduct(ejeZ, ejeX);

	ejeY = ejeY.Normalize();

	Matrix3 lookAtRotation;

	lookAtRotation.ax = ejeX;
	lookAtRotation.ay = ejeY;
	lookAtRotation.az.x = -ejeZ.x;
	lookAtRotation.az.y = -ejeZ.y;
	lookAtRotation.az.z = -ejeZ.z;

	ret = InverseOrthogonalMatrix(lookAtRotation, position);

	return ret;
}

Matrix4 Camera::GetPerspectiveMatrix() {
    Matrix4 ret;
	
	//Col 1
	ret.m[0] = (2 * frustum.near) / (frustum.right - frustum.left);
	ret.m[4] = 0.0f;
	ret.m[8] = 0.0f;
	ret.m[12] = 0.0f;

	//Col 2
	ret.m[1] = 0.0f;
	ret.m[5] = (2 * frustum.near) / (frustum.top - frustum.bottom);
	ret.m[9] = 0.0f;
	ret.m[13] = 0.0f;

	//Col 3
	ret.m[2] = (frustum.right + frustum.left) / (frustum.right - frustum.left);
	ret.m[6] = (frustum.top + frustum.bottom) / (frustum.top - frustum.bottom);
	ret.m[10] = (frustum.near + frustum.far) / (frustum.near - frustum.far);
	ret.m[14] = -1.0f;

    //Col 4
	ret.m[3] = 0.0f;
	ret.m[7] = 0.0f;
	ret.m[11] = (2 * frustum.near * frustum.far) / (frustum.near - frustum.far);
	ret.m[15] = 0.0f;

    return ret;
}