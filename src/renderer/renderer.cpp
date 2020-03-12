#include "../include/renderer.h"

void Renderer::Init() {
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
}

void Renderer::ClearBackBuffer(const float r, const float g, const float b) {
    glClearColor(r, g, b, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::ClearDepthBuffer() {
    glClear(GL_DEPTH_BUFFER_BIT);
}

void Renderer::SetMatrices(const MarshMath::Matrix4& model, const MarshMath::Matrix4& view, const MarshMath::Matrix4& projection) {
	glMatrixMode(GL_PROJECTION);
	//Cargar los datos de la matriz proyección
	//glLoadMatrixf(projection.m);
	glMatrixMode(GL_MODELVIEW);
	//Cargar los datos de vista*modelo
	//glLoadMatrixf(Multiply(view, model).m);
}

unsigned int Renderer::CreateBuffer() {
	unsigned int buffer;
	glGenBuffers(1, &buffer);
	return buffer;
}

void Renderer::FreeBuffer(unsigned int buffer) {
	glDeleteBuffers(1, &buffer);
}

void Renderer::BindVertexBuffer(unsigned int buffer) {
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
}

void Renderer::BindIndexBuffer(unsigned int buffer) {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer);
}

void Renderer::SetVertexBufferData(const void* data, unsigned int dataSize) {
	glBufferData(GL_ARRAY_BUFFER, dataSize, data, GL_DYNAMIC_DRAW);
}

void Renderer::SetIndexBufferData(const void *data, unsigned int dataSize) {
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, dataSize, data, GL_STATIC_DRAW);
}

void Renderer::DrawBuffer(unsigned int numIndices, int coordsOffset, int colorsOffset, unsigned int stride) {
	//glVertexPointer(2, GL_FLOAT, stride, (const void*)coordsOffset);
	//glColorPointer(3, GL_FLOAT, stride, (const void*)colorsOffset);
	glDrawElements(GL_TRIANGLES, numIndices, GL_UNSIGNED_SHORT, NULL);
}