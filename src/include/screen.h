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

    // Temporizador
	float ElapsedTime() const { return elapsedTime; }
private:
    GLFWwindow* screenWindow;
    int screenWidth;
    int screenHeight;

    float elapsedTime;
    float lastElapsedTime;

    void Close();
    int GetDesktopWidth() const;
	int GetDesktopHeight() const;
};

#endif