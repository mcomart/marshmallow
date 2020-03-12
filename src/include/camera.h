#ifndef CAMERA_H
#define CAMERA_H

#include "common.h"
#include "entity.h"

typedef struct {
    double left;
    double right;
    double bottom;
    double top;
    double near;
    double far;
} Frustum;

class Camera : public Entity {
public:
    double aperture;    //degrees
    int screenwidth;
    int screenheight;
public:
    Camera();
    // Camera(const double aperture, const int screenwidth, const int screenheight);
    ~Camera() {};

    void SetAperture(double aperture) { this->aperture = aperture; };;
    void SetScreenWidth(int screenwidth) { this->screenwidth = screenwidth; };
    void SetScreenHeight(int screenheight) { this->screenheight = screenheight; };;
    void SetFrustum(double near, double far);
    Matrix4 GetLookAt(Vector3 target);
    Matrix4 GetPerspectiveMatrix();
    
private:
    Vector3 up;
    Frustum frustum;
    
    Vector3 GetUpVector();
};
    

#endif