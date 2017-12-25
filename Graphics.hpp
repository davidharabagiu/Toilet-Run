#pragma once

#include "Shader.hpp"
#include "Camera.hpp"
#include "Entity.hpp"
#include "Model3D.hpp"
#include "glm\glm\gtc\type_ptr.hpp"

class Graphics
{

public:

	Graphics(int windowWidth, int windowHeight);
	void Draw(gps::Model3D model, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);
	void SetCameraPosition(glm::vec3 position);
	void SetCameraRotation(GLfloat xRotation, GLfloat yRotation);

private:

	Shader shader;
	gps::Camera camera;
	GLuint projectionLoc;
	GLuint viewLoc;
	GLuint modelLoc;

};