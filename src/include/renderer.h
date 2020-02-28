#ifndef RENDERER_H
#define RENDERER_H

#include "common.h"

class Renderer {
public:
    Renderer();
    ~Renderer();

    void Init();
    void ClearBackBuffer(const float r, const float g, const float b);
    void ClearDepthBuffer();
    void SetMatrices(const MarshMath::Matrix4& model, const MarshMath::Matrix4& view, const MarshMath::Matrix4& projection);
};

#endif