//
// Game.h
// The game class defines an instance of an OpenGL Game
// Created by David Harabagiu on 21.12.2017
//

#pragma once

#include "Window.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include "Graphics.hpp"
#include <vector>
#include <map>
#include <string>
#include <cstdlib>

class Game
{

public:

	Game(int WindowWidth, int WindowHeight, char* WindowTitle)
		:
		window(WindowWidth, WindowHeight, WindowTitle),
		graphics(WindowWidth, WindowHeight),
		player(graphics)
	{
		models["floor"] = gps::Model3D("Objects/floor/floor.obj1", "Objects/floor/");
		models["wall"] = gps::Model3D("Objects/wall/wall.obj1", "Objects/wall/");
		models["toilet"] = gps::Model3D("Objects/toilet/toilet.obj1", "Objects/toilet/");
		models["lamp"] = gps::Model3D("Objects/lamp/lamp.obj1", "Objects/lamp/");

		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				CreateRoom(glm::vec3(30.0f * i, 0.0f, 30.0f * j));
			}
		}
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

	void AddEntity(Entity& e)
	{
		entities.push_back(e);
	}

	void CreateRoom(glm::vec3 pos);

private:

	Window window;
	Graphics graphics;
	std::vector<Entity> entities;
	std::map<std::string, gps::Model3D> models;
	Player player;

	void UpdateEntities();
	void RenderScene();

};
