//
// Window.h
// The window class handles the creation of a open gl window
// Created by David Harabagiu on 21.12.2017
//

#pragma once

#include <iostream>
#include "OpenGLInclude.h"
#include "Input.hpp"

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

	void Update();

	bool ShouldClose()
	{
		return glfwWindowShouldClose(glWindow) == GL_TRUE;
	}

private:

	GLFWwindow* glWindow;

};