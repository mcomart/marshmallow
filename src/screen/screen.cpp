#include "screen.h"

int Screen::GetDesktopWidth() const {
    return glfwGetVideoMode(glfwGetPrimaryMonitor())->width;
}

int Screen::GetDesktopHeight() const {
    return glfwGetVideoMode(glfwGetPrimaryMonitor())->height;
}

bool Screen::Init(const string& title, bool fullscreen) {
    if (!glfwInit()) {
        // TODO: log
        return false;
    }

    glewInit();
    //GLenum err = glewInit();
    /*if (GLEW_OK != err) {
        return false;
    }*/

    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	glfwWindowHint(GLFW_SAMPLES, 8);

    screenWidth = GetDesktopWidth();
    screenHeight = GetDesktopHeight();
    screenWindow = glfwCreateWindow(screenWidth, screenHeight, title.c_str(), fullscreen ? glfwGetPrimaryMonitor() : nullptr, nullptr);
    if (screenWindow == nullptr)
    {
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(screenWindow);
    return true;
}

bool Screen::KeyPressed(int key) const {
    return glfwGetKey(screenWindow, key) == GLFW_PRESS;
}

void Screen::Refresh() {
    glfwSwapBuffers(screenWindow);
	glfwPollEvents();
}

bool Screen::ShouldClose() const {
    return glfwWindowShouldClose(screenWindow) == GL_TRUE;
}

void Screen::Close() {
    screenWindow = nullptr;
}

Screen::~Screen() {
    Close();
    glfwTerminate();
}