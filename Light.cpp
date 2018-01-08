#include "Light.hpp"
#include "Shader.hpp"

Light::Light(Shader& shader, Shader& depthShader)
	: shader(shader), depthShader(depthShader)
{
	nrPointLightLoc = glGetUniformLocation(shader.GetShaderProgram(), "nrPointLights");
	SendToShader();
}

void Light::AddLightSource(glm::vec3 lightPosition, glm::vec3 lightTarget, glm::vec3 lightColor, GLint id)
{
	lightSources.push_back(PointLight{ lightPosition, lightTarget, lightColor, DepthMap(id, shader, depthShader, lightPosition) });
}

void Light::RenderDepthMaps(std::vector<Entity>& entities, Graphics& graphics)
{
	for (PointLight& l : lightSources)
	{
		l.ShadowMap.Render(l.Target, entities, graphics);
	}
}

void Light::SendToShader()
{
	shader.UseShaderProgram();

	for (int i = 0; i < lightSources.size(); ++i)
	{
		std::string uniformName = "pointLights[";
		uniformName += std::to_string(i);
		uniformName += "]";

		std::string uniformPositionName = uniformName + ".position";
		std::string uniformColorName = uniformName + ".color";

		GLuint uniformPosition = glGetUniformLocation(shader.GetShaderProgram(), uniformPositionName.c_str());
		GLuint uniformColor = glGetUniformLocation(shader.GetShaderProgram(), uniformColorName.c_str());

		glUniform3fv(uniformPosition, 1, glm::value_ptr(lightSources[i].Position));
		glUniform3fv(uniformColor, 1, glm::value_ptr(lightSources[i].Color));
	}

	glUniform1i(nrPointLightLoc, lightSources.size());
}