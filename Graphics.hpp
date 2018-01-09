#pragma once

#include "glm\glm\gtc\type_ptr.hpp"
#include "glm\glm\gtc\matrix_inverse.hpp"
#include "glm\glm\gtc\constants.hpp"
#include <vector>
#include "Shader.hpp"
#include "Light.hpp"
#include "Camera.hpp"
#include "Model3D.hpp"
#include "SkyBox.hpp"

class Entity;

class Graphics
{

public:

	Graphics(int windowWidth, int windowHeight);
	void Draw(gps::Model3D model, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, GLint id);
	void SetCameraPosition(glm::vec3 position);
	void SetCameraRotation(GLfloat xRotation, GLfloat yRotation);
	void AddLightSource(glm::vec3 position, glm::vec3 target, glm::vec3 color, GLint id);
	void UseNormalShader();
	void UseDepthShader();
	void ToggleLightViewMode();
	void RenderShadows(std::vector<Entity>& entities);
	void SetSkybox(std::string path);
	void DrawSkybox();

	~Graphics()
	{
		if (skyBox != nullptr)
		{
			delete skyBox;
		}
	}

private:

	Shader shader;
	Shader depthShader;
	Shader skyboxShader;
	Light light;
	gps::Camera camera;
	GLuint projectionLoc;
	GLuint viewLoc;
	GLuint modelLoc;
	GLuint normalMatrixLoc;
	GLboolean lightViewMode;
	glm::mat4 projection;
	GLuint roomIdLoc;
	gps::SkyBox* skyBox;

};