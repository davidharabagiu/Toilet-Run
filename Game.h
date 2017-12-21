//
// Game.h
// The game class defines an instance of an OpenGL Game
// Created by David Harabagiu on 21.12.2017
//

#pragma once

#include <iostream>
#include "OpenGLInclude.h"

#define DEFAULT_WINDOW_WIDTH 1280
#define DEFAULT_WINDOW_HEIGHT 720

class Game
{
public:
	Game(int WindowWidth, int WindowHeight, char* WindowTitle, GLFWwindowsizefun WindowResizeCallback) : 
		windowWidth(WindowWidth),
		windowHeight(WindowHeight),
		windowTitle(WindowTitle),
		windowResizeCallback(WindowResizeCallback)
	{
		InitGame();
	}

	Game(char* WindowTitle, GLFWwindowsizefun WindowResizeCallback) :
		Game(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, WindowTitle, WindowResizeCallback)
	{
	}

	int GetWindowWidth()
	{
		return windowWidth;
	}

	void SetWindowWidth(int Width)
	{
		windowWidth = Width;
	}

	int GetWindowHeight()
	{
		return windowHeight;
	}

	void SetWindowHeight(int Height)
	{
		windowHeight = Height;
	}

	void Run();

private:

	void InitGame()
	{
		InitWindow();
		InitOpenGL();
	}

	void InitWindow();
	void InitOpenGL();
	void RenderScene();

	int windowWidth;
	int windowHeight;
	char* windowTitle;
	GLFWwindow* window;
	GLFWwindowsizefun windowResizeCallback;
};
