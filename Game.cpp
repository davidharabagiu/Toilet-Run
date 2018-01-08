//
// Game.cpp
// The game class defines an instance of an OpenGL Game
// Created by David Harabagiu on 14.12.2017
//

#include "Game.hpp"

void Game::Run()
{
	GLboolean wasLPressed = GL_FALSE;

	while (!window.ShouldClose())
	{
		if (Input::IsKeyPressed(GLFW_KEY_L))
		{
			if (wasLPressed == GL_FALSE)
			{
				graphics.ToggleLightViewMode();
			}
			wasLPressed = GL_TRUE;
		}
		else
		{
			wasLPressed = GL_FALSE;
		}

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		UpdateEntities();
		graphics.RenderShadows(entities);
		glViewport(0, 0, this->window.Width(), this->window.Height());
		RenderScene();
		window.Update();
	}
}

void Game::RenderScene()
{
	graphics.UseNormalShader();

	for (Entity& e : entities)
	{
		e.Draw(graphics);
	}
}

void Game::UpdateEntities()
{
	static double lastTimeStamp = 0;
	double currentTimeStamp = glfwGetTime();
	double deltaTime = currentTimeStamp - lastTimeStamp;
	lastTimeStamp = currentTimeStamp;

	for (Entity& e : entities)
	{
		e.Update(deltaTime);
	}

	player.Update(deltaTime);
}

static double drand48()
{
	return rand() / (RAND_MAX + 1.0);
}

void Game::CreateRoom(glm::vec3 pos)
{
	static int roomId = 0;

	Entity floor(models["floor"], roomId);
	floor.SetPosition(pos);
	floor.SetScale(glm::vec3(15.0f, 0.1f, 15.0f));
	AddEntity(floor);

	Entity wall11(models["wall"], -1);
	wall11.SetScale(glm::vec3(0.1f, 2.0f, 15.0f));
	wall11.SetPosition(glm::vec3(-15.0f, 8.0f, 0.0f) + pos);
	AddEntity(wall11);

	Entity wall12(models["wall"], -1);
	wall12.SetScale(glm::vec3(0.1f, 3.0f, 6.0f));
	wall12.SetPosition(glm::vec3(-15.0f, 3.0f, 9.0f) + pos);
	AddEntity(wall12);

	Entity wall13(models["wall"], -1);
	wall13.SetScale(glm::vec3(0.1f, 3.0f, 6.0f));
	wall13.SetPosition(glm::vec3(-15.0f, 3.0f, -9.0f) + pos);
	AddEntity(wall13);

	Entity wall21(models["wall"], -1);
	wall21.SetScale(glm::vec3(0.1f, 2.0f, 15.0f));
	wall21.SetPosition(glm::vec3(15.0f, 8.0f, 0.0f) + pos);
	AddEntity(wall21);

	Entity wall22(models["wall"], -1);
	wall22.SetScale(glm::vec3(0.1f, 3.0f, 6.0f));
	wall22.SetPosition(glm::vec3(15.0f, 3.0f, 9.0f) + pos);
	AddEntity(wall22);

	Entity wall23(models["wall"], -1);
	wall23.SetScale(glm::vec3(0.1f, 3.0f, 6.0f));
	wall23.SetPosition(glm::vec3(15.0f, 3.0f, -9.0f) + pos);
	AddEntity(wall23);

	Entity wall31(models["wall"], -1);
	wall31.SetScale(glm::vec3(15.0f, 2.0f, 0.1f));
	wall31.SetPosition(glm::vec3(0.0f, 8.0f, -15.0f) + pos);
	AddEntity(wall31);

	Entity wall32(models["wall"], -1);
	wall12.SetScale(glm::vec3(6.0f, 3.0f, 0.1f));
	wall12.SetPosition(glm::vec3(9.0f, 3.0f, -15.0f) + pos);
	AddEntity(wall12);

	Entity wall33(models["wall"], -1);
	wall13.SetScale(glm::vec3(6.0f, 3.0f, 0.1f));
	wall13.SetPosition(glm::vec3(-9.0f, 3.0f, -15.0f) + pos);
	AddEntity(wall13);

	Entity wall41(models["wall"], -1);
	wall41.SetScale(glm::vec3(15.0f, 2.0f, 0.1f));
	wall41.SetPosition(glm::vec3(0.0f, 8.0f, 15.0f) + pos);
	AddEntity(wall41);

	Entity wall42(models["wall"], -1);
	wall12.SetScale(glm::vec3(6.0f, 3.0f, 0.1f));
	wall12.SetPosition(glm::vec3(9.0f, 3.0f, 15.0f) + pos);
	AddEntity(wall12);

	Entity wall43(models["wall"], -1);
	wall13.SetScale(glm::vec3(6.0f, 3.0f, 0.1f));
	wall13.SetPosition(glm::vec3(-9.0f, 3.0f, 15.0f) + pos);
	AddEntity(wall13);

	Entity roof(models["wall"], -1);
	roof.SetScale(glm::vec3(15.0f, 0.1f, 15.0f));
	roof.SetPosition(glm::vec3(0.0f, 10.0f, 0.0f) + pos);
	AddEntity(roof);

	Entity lamp(models["lamp"], -1);
	lamp.SetScale(glm::vec3(0.05f, 0.05f, 0.05f));
	lamp.SetPosition(glm::vec3(0.0, 10.1f, 0.0f) + pos);
	AddEntity(lamp);

	int numberOfToilets = rand() % 3 + 1;
	int numberOfHanddryers = rand() % 3 + 1;
	int numberOfSinks = rand() % 1 + 1;

	for (int i = 0; i < numberOfToilets; ++i)
	{
		int xPositive = rand() % 2;
		float xWall = (xPositive ? 1.0f : -1.0f) * 14.0f;
		float zWall = ((rand() % 2) ? 1.0f : -1.0f) * (14.0f - drand48() * 5.0f);
		float zRotation = 0.0f;

		if (xPositive)
		{
			zRotation = glm::radians(180.0f);
		}

		if (rand() % 2 == 0)
		{
			float temp = xWall;
			xWall = zWall;
			zWall = temp;
			zRotation -= glm::radians(90.0f);
		}

		Entity toilet(models["toilet"], roomId);
		toilet.SetScale(glm::vec3(0.005f, 0.005f, 0.005f));
		toilet.SetRotation(glm::vec3(glm::radians(-90.0f), 0.0f, zRotation));
		toilet.SetPosition(glm::vec3(xWall, 0, zWall) + pos);
		AddEntity(toilet);
	}

	for (int i = 0; i < numberOfHanddryers; ++i)
	{
		int xPositive = rand() % 2;
		float xWall = (xPositive ? 1.0f : -1.0f) * 13.5f;
		float zWall = ((rand() % 2) ? 1.0f : -1.0f) * (13.5f - drand48() * 5.0f);
		float zRotation = 0.0f;

		if (xPositive)
		{
			zRotation = glm::radians(180.0f);
		}

		if (rand() % 2 == 0)
		{
			float temp = xWall;
			xWall = zWall;
			zWall = temp;
			zRotation -= glm::radians(90.0f);
		}

		Entity handdryer(models["handdryer"], roomId);
		handdryer.SetPosition(pos + glm::vec3(xWall, 1.0f + drand48() * 2.0f, zWall));
		handdryer.SetRotation(glm::vec3(glm::radians(-90.0f), 0.0f, zRotation));
		handdryer.SetScale(glm::vec3(3.0f, 3.0f, 3.0f));
		AddEntity(handdryer);
	}

	for (int i = 0; i < numberOfSinks; ++i)
	{
		int xPositive = rand() % 2;
		float xWall = (xPositive ? 1.0f : -1.0f) * 14.0f;
		float zWall = ((rand() % 2) ? 1.0f : -1.0f) * (14.0f - drand48() * 5.0f);
		float yRotation = glm::radians(90.0f);

		if (xPositive)
		{
			yRotation += glm::radians(180.0f);
		}

		if (rand() % 2 == 0)
		{
			float temp = xWall;
			xWall = zWall;
			zWall = temp;
			yRotation -= glm::radians(90.0f);
		}

		Entity sink(models["sink"], roomId);
		sink.SetPosition(pos + glm::vec3(xWall, 1.0f, zWall));
		sink.SetRotation(glm::vec3(0.0f, yRotation, 0.0f));
		sink.SetScale(glm::vec3(0.1f, 0.1f, 0.1f));
		AddEntity(sink);
	}

	int numberOfSoaps = rand() % 5 + 1;
	for (int i = 0; i < numberOfSoaps; ++i)
	{
		float x = (drand48() - 0.5f) * 26;
		float y = drand48() * 10;
		float z = (drand48() - 0.5f) * 26;
		Entity soap(models["soap"], roomId);
		soap.SetPosition(pos + glm::vec3(x, y, z));
		soap.SetRotation(glm::vec3(0.0f, glm::radians(45.0f), glm::radians(45.0f)));
		soap.SetScale(glm::vec3(2.0f, 2.0f, 2.0f));
		soap.SetRotationSpeed(glm::vec3(0.0f, glm::radians(40.0f), 0.0f));
		AddEntity(soap);
	}

	


	float r, g, b;
	int c = rand() % 3;
	if (c == 0)
	{
		r = drand48();
		g = drand48();
		b = drand48() * (2.0f - r - g);
	}
	else if (c == 1)
	{
		g = drand48();
		r = drand48();
		b = drand48() * (2.0f - g - r);
	}
	else if (c == 2)
	{
		b = drand48();
		r = drand48();
		g = drand48() * (2.0f - b - r);
	}

	graphics.AddLightSource(pos + glm::vec3(0.0f, 9.0f, 0.0f), pos + glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(r, g, b), roomId);

	++roomId;
}
