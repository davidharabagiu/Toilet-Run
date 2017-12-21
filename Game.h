//
// Game.h
// The game class defines an instance of an OpenGL Game
// Created by David Harabagiu on 21.12.2017
//

#pragma once

#include <iostream>
#include "OpenGLInclude.h"
#include "Window.h"

class Game
{

public:

	Game(int WindowWidth, int WindowHeight, char* WindowTitle)
		: window(WindowWidth, WindowHeight, WindowTitle)
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	}

	Game(char* WindowTitle) :
		Game(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, WindowTitle)
	{
	}

	Game() :
		Game(DEFAULT_WINDOW_TITLE)
	{
	}

	void Run();

private:

	Window window;
	void RenderScene();

};
