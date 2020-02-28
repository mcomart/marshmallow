#ifndef SCREEN_H
#define SCREEN_H

#include "common.h"

class Screen {
public:
    Screen() { screenWindow = nullptr; };
    ~Screen();

    bool Init(const string& title, bool fullscreen);
	bool ShouldClose() const;
    bool KeyPressed(int key) const;
	void Refresh();
	int GetWidth() const { return screenWidth; }
	int GetHeight() const { return screenHeight; }
private:
    GLFWwindow* screenWindow;
    int screenWidth;
    int screenHeight;

    void Close();
    int GetDesktopWidth() const;
	int GetDesktopHeight() const;
};

#endif