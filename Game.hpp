//
// Game.h
// The game class defines an instance of an OpenGL Game
// Created by David Harabagiu on 21.12.2017
//

#pragma once

#include "Window.hpp"
#include "Input.hpp"
#include "Shader.hpp"

class Game
{

public:

	Game(int WindowWidth, int WindowHeight, char* WindowTitle)
		:
		window(WindowWidth, WindowHeight, WindowTitle),
		shader("shaders/shader.vert", "shaders/shader.frag")
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
	Shader shader;
	void RenderScene();

};
