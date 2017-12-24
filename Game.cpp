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
		e.Draw();
	}
}

void Game::UpdateEntities()
{
	for (Entity& e : entities)
	{
		e.Update();
	}

	camera.update();

	//glm::mat4 view = glm::lookAt(glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

	glm::mat4 view = camera.getViewMatrix();
	glUniformMatrix4fv(viewMatrixLoc, 1, GL_FALSE, glm::value_ptr(view));
}