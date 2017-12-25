//
// Game.cpp
// The game class defines an instance of an OpenGL Game
// Created by David Harabagiu on 14.12.2017
//

#include "Game.hpp"

void Game::Run()
{
	while (!window.ShouldClose())
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glViewport(0, 0, this->window.Width(), this->window.Height());

		UpdateEntities();
		RenderScene();
		window.Update();
	}
}

void Game::RenderScene()
{
	for (Entity& e : entities)
	{
		e.Draw(graphics);
	}
}

void Game::UpdateEntities()
{
	for (Entity& e : entities)
	{
		e.Update();
	}

	player.Update();
}