#ifndef RENDERER_H
#define RENDERER_H

#include "common.h"

class Renderer {
public:
    Renderer() {};
    ~Renderer() {};

    void Init();
    void ClearBackBuffer(const float r, const float g, const float b);
    void ClearDepthBuffer();
    void SetMatrices(const MarshMath::Matrix4& model, const MarshMath::Matrix4& view, const MarshMath::Matrix4& projection);

    // VBO
	unsigned int CreateBuffer();
	void FreeBuffer(unsigned int buffer);
	void BindVertexBuffer(unsigned int buffer);
	void BindIndexBuffer(unsigned int buffer);
	void SetVertexBufferData(const void* data, unsigned int dataSize);
	void SetIndexBufferData(const void* data, unsigned int dataSize);
	void DrawBuffer(unsigned int numIndices, int coordsOffset, int colorsOffset, unsigned int stride);
};

#endif