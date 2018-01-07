#pragma once

#include "glm\glm\gtc\type_ptr.hpp"
#include "glm\glm\gtc\matrix_inverse.hpp"
#include "glm\glm\gtc\constants.hpp"
#include <vector>
#include "Shader.hpp"
#include "Light.hpp"
#include "Camera.hpp"
#include "Model3D.hpp"

class Entity;

class Graphics
{

public:

	Graphics(int windowWidth, int windowHeight);
	void Draw(gps::Model3D model, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);
	void SetCameraPosition(glm::vec3 position);
	void SetCameraRotation(GLfloat xRotation, GLfloat yRotation);
	void AddLightSource(glm::vec3 position, glm::vec3 target, glm::vec3 color);
	void UseNormalShader();
	void UseDepthShader();
	void RenderShadows(std::vector<Entity>& entities);

private:

	Shader shader;
	Shader depthShader;
	Light light;
	gps::Camera camera;
	GLuint projectionLoc;
	GLuint viewLoc;
	GLuint modelLoc;
	GLuint normalMatrixLoc;

};