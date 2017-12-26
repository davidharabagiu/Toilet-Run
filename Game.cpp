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

void Game::CreateRoom(glm::vec3 pos)
{
	Entity floor(models["floor"]);
	floor.SetPosition(pos);
	floor.SetScale(glm::vec3(15.0f, 0.1f, 15.0f));
	AddEntity(floor);

	Entity wall11(models["wall"]);
	wall11.SetScale(glm::vec3(0.1f, 2.0f, 15.0f));
	wall11.SetPosition(glm::vec3(-15.0f, 8.0f, 0.0f) + pos);
	AddEntity(wall11);

	Entity wall12(models["wall"]);
	wall12.SetScale(glm::vec3(0.1f, 3.0f, 6.0f));
	wall12.SetPosition(glm::vec3(-15.0f, 3.0f, 9.0f) + pos);
	AddEntity(wall12);

	Entity wall13(models["wall"]);
	wall13.SetScale(glm::vec3(0.1f, 3.0f, 6.0f));
	wall13.SetPosition(glm::vec3(-15.0f, 3.0f, -9.0f) + pos);
	AddEntity(wall13);

	Entity wall21(models["wall"]);
	wall21.SetScale(glm::vec3(0.1f, 2.0f, 15.0f));
	wall21.SetPosition(glm::vec3(15.0f, 8.0f, 0.0f) + pos);
	AddEntity(wall21);

	Entity wall22(models["wall"]);
	wall22.SetScale(glm::vec3(0.1f, 3.0f, 6.0f));
	wall22.SetPosition(glm::vec3(15.0f, 3.0f, 9.0f) + pos);
	AddEntity(wall22);

	Entity wall23(models["wall"]);
	wall23.SetScale(glm::vec3(0.1f, 3.0f, 6.0f));
	wall23.SetPosition(glm::vec3(15.0f, 3.0f, -9.0f) + pos);
	AddEntity(wall23);

	Entity wall31(models["wall"]);
	wall31.SetScale(glm::vec3(15.0f, 2.0f, 0.1f));
	wall31.SetPosition(glm::vec3(0.0f, 8.0f, -15.0f) + pos);
	AddEntity(wall31);

	Entity wall32(models["wall"]);
	wall12.SetScale(glm::vec3(6.0f, 3.0f, 0.1f));
	wall12.SetPosition(glm::vec3(9.0f, 3.0f, -15.0f) + pos);
	AddEntity(wall12);

	Entity wall33(models["wall"]);
	wall13.SetScale(glm::vec3(6.0f, 3.0f, 0.1f));
	wall13.SetPosition(glm::vec3(-9.0f, 3.0f, -15.0f) + pos);
	AddEntity(wall13);

	Entity wall41(models["wall"]);
	wall41.SetScale(glm::vec3(15.0f, 2.0f, 0.1f));
	wall41.SetPosition(glm::vec3(0.0f, 8.0f, 15.0f) + pos);
	AddEntity(wall41);

	Entity wall42(models["wall"]);
	wall12.SetScale(glm::vec3(6.0f, 3.0f, 0.1f));
	wall12.SetPosition(glm::vec3(9.0f, 3.0f, 15.0f) + pos);
	AddEntity(wall12);

	Entity wall43(models["wall"]);
	wall13.SetScale(glm::vec3(6.0f, 3.0f, 0.1f));
	wall13.SetPosition(glm::vec3(-9.0f, 3.0f, 15.0f) + pos);
	AddEntity(wall13);

	Entity roof(models["wall"]);
	roof.SetScale(glm::vec3(15.0f, 0.1f, 15.0f));
	roof.SetPosition(glm::vec3(0.0f, 10.0f, 0.0f) + pos);
	AddEntity(roof);

	Entity toilet(models["toilet"]);
	toilet.SetScale(glm::vec3(0.01f, 0.01f, 0.01f));
	toilet.SetRotation(glm::vec3(glm::radians(-90.0f), 0.0f, 0.0f));
	toilet.SetPosition(pos);
	AddEntity(toilet);
}