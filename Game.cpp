//
// Game.cpp
// The game class defines an instance of an OpenGL Game
// Created by David Harabagiu on 14.12.2017
//

#include <iostream>
#include "Game.h"

void Game::Run()
{
	while (!glfwWindowShouldClose(window))
	{
		RenderScene();
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
}

void Game::InitWindow()
{
	if (!glfwInit()) {
		std::cerr << "ERROR: could not start GLFW3\n";
		return;
	}

	window = glfwCreateWindow(windowWidth, windowHeight, windowTitle, NULL, NULL);
	if (!window) {
		std::cerr << "ERROR: could not open window with GLFW3\n";
		glfwTerminate();
		return;
	}

	glfwSetWindowSizeCallback(window, windowResizeCallback);
	glfwMakeContextCurrent(window);

	glfwWindowHint(GLFW_SAMPLES, 4);

	// start GLEW extension handler
	glewExperimental = GL_TRUE;
	glewInit();

	// get version info
	const GLubyte* renderer = glGetString(GL_RENDERER); // get renderer string
	const GLubyte* version = glGetString(GL_VERSION); // version as a string
	std::cout << "Renderer: " << renderer << "\n";
	std::cout << "OpenGL version supported: " << version << "\n";
}

void Game::InitOpenGL()
{
	glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
	glViewport(0, 0, windowWidth, windowHeight);
	glEnable(GL_DEPTH_TEST);
}

void Game::RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
