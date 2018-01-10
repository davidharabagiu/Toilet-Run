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
#include <memory>

class Game
{

public:

	Game(int WindowWidth, int WindowHeight, char* WindowTitle)
		:
		window(WindowWidth, WindowHeight, WindowTitle),
		graphics(WindowWidth, WindowHeight),
		player(graphics, -15.0f, ROOMS_X * 30.0f - 15, -15.0f, ROOMS_Z * 30.0f - 15)
	{
		models["floor"] = gps::Model3D("Objects/floor/floor.obj1", "Objects/floor/");
		models["wall"] = gps::Model3D("Objects/wall/wall.obj1", "Objects/wall/");
		models["toilet"] = gps::Model3D("Objects/toilet/m4d_v2_001.obj1", "Objects/toilet/");
		models["lamp"] = gps::Model3D("Objects/lamp/lamp.obj1", "Objects/lamp/");
		models["handdryer"] = gps::Model3D("Objects/handdryer/handdryer.obj1", "Objects/handdryer/");
		models["sink"] = gps::Model3D("Objects/sink/untitled.obj1", "Objects/sink/");
		models["soap"] = gps::Model3D("Objects/soap/soap.obj1", "Objects/soap/");
		models["shit"] = gps::Model3D("Objects/shit/untitled.obj1", "Objects/shit/");

		graphics.SetSkybox("Skybox/");

		for (int i = 0; i < ROOMS_X; ++i)
		{
			for (int j = 0; j < ROOMS_Z; ++j)
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

	const int ROOMS_X = 3;
	const int ROOMS_Z = 2;

	Window window;
	Graphics graphics;
	std::vector<Entity> entities;
	std::map<std::string, gps::Model3D> models;
	Player player;

	void UpdateEntities();
	void RenderScene();
	void SpawnShit(glm::vec3 pos);
	void TogglePolygonMode();

};
