//
// Game.cpp
// The game class defines an instance of an OpenGL Game
// Created by David Harabagiu on 14.12.2017
//

#include "Game.h"

void Game::Run()
{
	while (!window.ShouldClose())
	{
		RenderScene();
		window.Update();
	}
}

void Game::RenderScene()
{
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
