#pragma once

#include "glm\glm\glm.hpp"
#include "glm\glm\gtc\type_ptr.hpp"
#include "DepthMap.hpp"
#include <vector>
#include <string>
#include <cstdlib>

class Shader;
class Entity;
class Graphics;

struct PointLight
{
	glm::vec3 Position;
	glm::vec3 Color;
	DepthMap ShadowMap;
};

class Light
{

public:

	Light(Shader& shader, Shader& depthShader);
	void AddLightSource(glm::vec3 lightPosition, glm::vec3 lightColor);
	void SendToShader();
	void RenderDepthMaps(glm::vec3 cameraTarget, std::vector<Entity>& entities, Graphics& graphics);

private:

	std::vector<PointLight> lightSources;
	Shader& shader;
	Shader& depthShader;
	GLint nrPointLightLoc;

};