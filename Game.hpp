//
// Game.h
// The game class defines an instance of an OpenGL Game
// Created by David Harabagiu on 21.12.2017
//

#pragma once

#include "Window.hpp"
#include "Input.hpp"
#include "Shader.hpp"
#include "Entity.hpp"
#include "Camera.hpp"
#include "glm/glm/gtc/matrix_transform.hpp"
#include "glm/glm/gtc/type_ptr.hpp"
#include <vector>

class Game
{

public:

	Game(int WindowWidth, int WindowHeight, char* WindowTitle)
		:
		window(WindowWidth, WindowHeight, WindowTitle),
		shader("shaders/shader.vert", "shaders/shader.frag")
	{
		shader.UseShaderProgram();

		viewMatrixLoc = glGetUniformLocation(shader.GetShaderProgram(), "view");
		projectionMatrixLoc = glGetUniformLocation(shader.GetShaderProgram(), "projection");
		projectionMatrix = glm::perspective(glm::radians(45.0f), (float)window.Width() / (float)window.Height(), 0.1f, 1000.0f);
		glUniformMatrix4fv(projectionMatrixLoc, 1, GL_FALSE, glm::value_ptr(projectionMatrix));

		AddEntity(Entity(gps::Model3D("Objects/nanosuit/nanosuit.obj", "Objects/nanosuit/"), shader));
		AddEntity(Entity(gps::Model3D("Objects/Farmhouse.obj", "Objects/"), shader));
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
	Shader shader;
	gps::Camera camera;
	std::vector<Entity> entities;
	GLuint viewMatrixLoc;
	GLuint projectionMatrixLoc;
	glm::mat4 projectionMatrix;

	void UpdateEntities();
	void RenderScene();

};
