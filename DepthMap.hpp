#pragma once

#include "OpenGLInclude.h"
#include "glm\glm\glm.hpp"
#include "glm\glm\gtc\matrix_transform.hpp"
#include "glm\glm\gtc\type_ptr.hpp"
#include <vector>

class Graphics;
class Entity;
class Shader;

class DepthMap
{

public:

	DepthMap(GLint index, Shader& shader, Shader& depthShader, glm::vec3 lightPosition);
	void Render(glm::vec3 cameraTarget, std::vector<Entity>& entities, Graphics& graphics);

private:

	const GLuint SHADOW_WIDTH = 128;
	const GLuint SHADOW_HEIGHT = 128;
	GLuint fbo;
	GLuint texture;
	glm::mat4 lightProjection;
	glm::vec3 lightPosition;
	Shader& depthShader;
	GLuint lightSpaceMatrixLoc;
	GLuint lightSpaceMatrixLoc2;
	GLuint shadowMapLoc;
	GLenum samplerId;

};