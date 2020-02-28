#ifdef _WIN32
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif
#include "../include/marshmallow/marshmallow.h"
#define FULLSCREEN true

Screen mainScreen;
Renderer renderer;

int main() {
    
    bool canInit = mainScreen.Init("Marshmallow Simulator", FULLSCREEN);
    if (!canInit) {
        return 1;
    }

    renderer.Init();
    while (!mainScreen.ShouldClose() && !mainScreen.KeyPressed(GLFW_KEY_ESCAPE)) {
        renderer.ClearBackBuffer(1.0f, 1.0f, 1.0f);
        renderer.ClearDepthBuffer();
        mainScreen.Refresh();
    }

    return 0;
}