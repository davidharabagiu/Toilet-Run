#include "DepthMap.hpp"
#include "Graphics.hpp"
#include "Entity.hpp"

DepthMap::DepthMap(GLint index, Shader& shader, Shader& depthShader, glm::vec3 lightPosition)
	: depthShader(depthShader), lightPosition(lightPosition)
{
	glGenFramebuffers(1, &fbo);
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, SHADOW_WIDTH, SHADOW_HEIGHT, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glBindFramebuffer(GL_FRAMEBUFFER, fbo);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, texture, 0);
	glDrawBuffer(GL_NONE);
	glReadBuffer(GL_NONE);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	lightProjection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, 1.0f, 7.5f);
	lightSpaceMatrixLoc = glGetUniformLocation(depthShader.GetShaderProgram(), "lightSpaceMatrix");

	std::string lightSpaceMatrixUniformName = "lightSpaceMatrices[";
	std::string shadowMapUniformName = "shadowMaps[";
	lightSpaceMatrixUniformName += std::to_string(index) + "]";
	shadowMapUniformName += std::to_string(index) + "]";

	lightSpaceMatrixLoc2 = glGetUniformLocation(shader.GetShaderProgram(), lightSpaceMatrixUniformName.c_str());
	shadowMapLoc = glGetUniformLocation(shader.GetShaderProgram(), shadowMapUniformName.c_str());
	samplerId = GL_TEXTURE1 + index;
}

void DepthMap::Render(glm::vec3 cameraTarget, std::vector<Entity>& entities, Graphics& graphics)
{
	glm::mat4 lightView = glm::lookAt(lightPosition, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 lightSpaceMatrix = lightProjection * lightView;
	depthShader.UseShaderProgram();

	glViewport(0, 0, SHADOW_WIDTH, SHADOW_HEIGHT);
	glBindFramebuffer(GL_FRAMEBUFFER, fbo);
	glClear(GL_DEPTH_BUFFER_BIT);
	glUniformMatrix4fv(lightSpaceMatrixLoc, 1, GL_FALSE, glm::value_ptr(lightSpaceMatrix));

	for (Entity e : entities)
	{
		e.Draw(graphics);
	}

	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	graphics.UseNormalShader();
	glUniformMatrix4fv(lightSpaceMatrixLoc2, 1, GL_FALSE, glm::value_ptr(lightSpaceMatrix));

	glActiveTexture(samplerId);
	glBindTexture(GL_TEXTURE_2D, texture);
	//glBindTexture(GL_TEXTURE)
}