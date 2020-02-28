#include "../include/renderer.h"

void Renderer::Init() {
    //glEnable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_SCISSOR_TEST);
	//glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);
	glDepthFunc(GL_LEQUAL);
}

void Renderer::ClearBackBuffer(const float r, const float g, const float b) {
    glClearColor(r, g, b, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::ClearDepthBuffer() {
    glClear(GL_DEPTH_BUFFER_BIT);
}

void Renderer::SetMatrices(const MarshMath::Matrix4& model, const MarshMath::Matrix4& view, const MarshMath::Matrix4& projection) {

}