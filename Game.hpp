//
// Game.h
// The game class defines an instance of an OpenGL Game
// Created by David Harabagiu on 21.12.2017
//

#pragma once

#include "Window.hpp"
#include "Input.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include <vector>

class Game
{

public:

	Game(int WindowWidth, int WindowHeight, char* WindowTitle)
		:
		window(WindowWidth, WindowHeight, WindowTitle),
		graphics(WindowWidth, WindowHeight),
		player(graphics)
	{
		AddEntity(Entity(gps::Model3D("Objects/nanosuit/nanosuit.obj", "Objects/nanosuit/")));
		AddEntity(Entity(gps::Model3D("Objects/Farmhouse.obj", "Objects/")));
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

private:

	Window window;
	Graphics graphics;
	std::vector<Entity> entities;
	Player player;

	void UpdateEntities();
	void RenderScene();

};
