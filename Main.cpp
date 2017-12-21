//
// Main.cpp
// Main class. Contains the entry point of the application.
// Created by David Harabagiu on 21.12.2017
//

#include "Game.h"

void WindowResizeCallback(GLFWwindow*, int, int);

Game game("Toilet Run Dev Test", WindowResizeCallback);

int main(int argc, char **argv)
{
	game.Run();
	return 0;
}

void WindowResizeCallback(GLFWwindow* Window, int Width, int Height)
{
	std::cout << "Window resized to width " << Width << " and height " << Height << "\n";
	game.SetWindowWidth(Width);
	game.SetWindowHeight(Height);

	/*projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	projectionLoc = glGetUniformLocation(myCustomShader.shaderProgram, "projection");
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));*/
}