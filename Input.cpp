//
// Input.cpp
// Contains functions for getting keyboard and mouse input from the user.
// Created by David Harabagiu on 21.12.2017
//

#include "Input.h"
#include <map>

namespace Input
{
	static std::map<int, bool> keyStates;
	static std::map<int, bool> mouseButtonStates;
	static double cursorX;
	static double cursorY;

	static void KeyboardCallback(GLFWwindow* Window, int Key, int Scancode, int Action, int Mods)
	{
		if (Action == GLFW_PRESS)
		{
			keyStates[Key] = true;
		}
		else if (Action == GLFW_RELEASE)
		{
			keyStates[Key] = false;
		}
	}

	static void CursorPositionCallback(GLFWwindow* Window, double XPos, double YPos)
	{
		cursorX = XPos;
		cursorY = YPos;
	}

	static void MouseButtonCallback(GLFWwindow* Window, int Button, int Action, int Mods)
	{
		if (Action == GLFW_PRESS)
		{
			keyStates[Button] = true;
		}
		else if (Action == GLFW_RELEASE)
		{
			keyStates[Button] = false;
		}
	}

	bool IsKeyPressed(int Key)
	{
		if (keyStates.count(Key))
		{
			return keyStates[Key];
		}

		return false;
	}

	bool IsMouseButtonPressed(int Button)
	{
		if (mouseButtonStates.count(Button))
		{
			return mouseButtonStates[Button];
		}

		return false;
	}

	double GetCursorX()
	{
		return cursorX;
	}

	double GetCursorY()
	{
		return cursorY;
	}

	void RegisterCallbacks(GLFWwindow* Window)
	{
		glfwSetKeyCallback(Window, KeyboardCallback);
		glfwSetCursorPosCallback(Window, CursorPositionCallback);
		glfwSetMouseButtonCallback(Window, MouseButtonCallback);
	}

	void DisableCursor(GLFWwindow* Window)
	{
		glfwSetInputMode(Window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}

	void EnableCursor(GLFWwindow* Window)
	{
		glfwSetInputMode(Window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	}

}

