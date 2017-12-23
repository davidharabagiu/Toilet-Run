//
// Game.h
// The game class defines an instance of an OpenGL Game
// Created by David Harabagiu on 21.12.2017
//

#pragma once

#include "Window.h"
#include "Input.h"

class Game
{

public:

	Game(int WindowWidth, int WindowHeight, char* WindowTitle)
		: window(WindowWidth, WindowHeight, WindowTitle)
	{
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
