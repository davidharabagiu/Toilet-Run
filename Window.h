#pragma once

#include <iostream>
#include "OpenGLInclude.h"

#define DEFAULT_WINDOW_WIDTH 1280
#define DEFAULT_WINDOW_HEIGHT 720
#define DEFAULT_WINDOW_TITLE "Game"

class Window
{

public:

	Window(int Width, int Height, char* Title);

	Window(char *Title)
		: Window(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, Title)
	{
	}

	Window()
		: Window(DEFAULT_WINDOW_TITLE)
	{
	}

	void Update()
	{
		glfwPollEvents();
		glfwSwapBuffers(glWindow);
	}

	bool ShouldClose()
	{
		return glfwWindowShouldClose(glWindow);
	}

private:

	GLFWwindow* glWindow;

};