#ifdef _WIN32
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif
#include "../include/marshmallow/marshmallow.h"
#define FULLSCREEN false

Screen mainScreen;
Camera camera;
Renderer renderer;
vector<RigidBody> bodies;

int main() {
    
    bool canInit = mainScreen.Init("Marshmallow Simulator", FULLSCREEN);
    if (!canInit) {
        return 1;
    }

    camera.SetScreenHeight(mainScreen.GetHeight());
    camera.SetScreenWidth(mainScreen.GetWidth());
    camera.SetFrustum(0.1, 100.0);

    // A dummy triangle
	float vertices[] = {
		-0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 
		0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f, 1.0f
	};
	unsigned int indices[] = { 0, 1, 2 };

    // HACK: Dummy entity just to get a rotation matrix --> TODO: everything drawable must be an Entity!!!
    Entity dummyEntity;

    renderer.Init();

	unsigned int buffer_vertex = renderer.CreateBuffer();
	renderer.BindVertexBuffer(buffer_vertex);
	renderer.SetVertexBufferData(vertices, sizeof(vertices));
	
	unsigned int buffer_indices = renderer.CreateBuffer();
	renderer.BindIndexBuffer(buffer_indices); 
	renderer.SetIndexBufferData(indices, sizeof(indices));

    Matrix4 projection = camera.GetPerspectiveMatrix();
    
    // Dummy target -> center
    Matrix4 view = camera.GetLookAt(Vector3());

    Quaternion dummyRotation;
    float angleY = 0;
    while (!mainScreen.ShouldClose() && !mainScreen.KeyPressed(GLFW_KEY_ESCAPE)) {
        renderer.ClearBackBuffer(1.0f, 0.5f, 0.5f);
        renderer.ClearDepthBuffer();
            // 1. Get model matrix
            angleY += 30 * mainScreen.ElapsedTime();
            dummyEntity.SetEulerAngles(0.0f, angleY, 0.0f);
            dummyRotation = dummyEntity.GetQuaternionFromEuler();
            Matrix4 model = dummyRotation.GetMatrix4();
            // 2. Set it in the renderer
            renderer.SetMatrices(model, view, projection);
            // 3. Set parameters of DrawBuffer with new geometry and draw
            renderer.DrawBuffer(3, 0, 2 * sizeof(float), 5 * sizeof(float));
        mainScreen.Refresh();
    }

    return 0;
}