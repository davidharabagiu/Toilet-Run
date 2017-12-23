//
// Input.h
// Contains functions for getting keyboard and mouse input from the user.
// Created by David Harabagiu on 21.12.2017
//

#pragma once

#include "OpenGLInclude.h"

namespace Input
{
	bool IsKeyPressed(int Key);
	bool IsMouseButtonPressed(int Button);
	double GetCursorX();
	double GetCursorY();
	void RegisterCallbacks(GLFWwindow* Window);
	void DisableCursor(GLFWwindow* Window);
	void EnableCursor(GLFWwindow* Window);
}