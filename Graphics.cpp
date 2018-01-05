#include "Graphics.hpp"

Graphics::Graphics(int windowWidth, int windowHeight) :
	shader("shaders/shader.vert", "shaders/shader.frag"),
	depthShader("shaders/depthShader.vert", "shaders/depthShader.frag"),
	light(shader, depthShader)
{
	shader.UseShaderProgram();

	modelLoc = glGetUniformLocation(shader.GetShaderProgram(), "model");
	viewLoc = glGetUniformLocation(shader.GetShaderProgram(), "view");
	projectionLoc = glGetUniformLocation(shader.GetShaderProgram(), "projection");
	normalMatrixLoc = glGetUniformLocation(shader.GetShaderProgram(), "normalMatrix");
	
	glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)windowWidth / (float)windowHeight, 0.1f, 1000.0f);
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

	glEnable(GL_CULL_FACE);
}

void Graphics::SetCameraPosition(glm::vec3 position)
{
	camera.SetPosition(position);
	glm::mat4 view = camera.getViewMatrix();
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
}

void Graphics::SetCameraRotation(GLfloat xRotation, GLfloat yRotation)
{
	camera.SetRotation(xRotation, yRotation);
	glm::mat4 view = camera.getViewMatrix();
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
}

void Graphics::Draw(gps::Model3D model, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
{
	glm::mat4 tr = glm::mat4(1.0f);
	tr = glm::translate(tr, position);
	tr = glm::rotate(tr, rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
	tr = glm::rotate(tr, rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
	tr = glm::rotate(tr, rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
	tr = glm::scale(tr, scale);
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(tr));
	glm::mat3 normalMatrix = glm::mat3(glm::inverseTranspose(camera.getViewMatrix() * tr));
	glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
	model.Draw(shader);
}

void Graphics::AddLightSource(glm::vec3 position, glm::vec3 color)
{
	light.AddLightSource(position, color);
	light.SendToShader();
}

void Graphics::UseNormalShader()
{
	shader.UseShaderProgram();
}

void Graphics::UseDepthShader()
{
	depthShader.UseShaderProgram();
}

void Graphics::RenderShadows(std::vector<Entity>& entities)
{
	light.RenderDepthMaps(camera.Target(), entities, *this);
}