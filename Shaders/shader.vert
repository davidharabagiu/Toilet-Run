#version 410 core
#define MAX_POINT_LIGHTS 6

layout(location=0) in vec3 vertexPosition;
layout(location=1) in vec3 vertexNormal;
layout(location=2) in vec2 textureCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform mat4 lightSpaceMatrices[MAX_POINT_LIGHTS];
uniform int nrPointLights;

out vec2 passTexture;
out vec3 normal;
out vec4 fragPosEye;
out vec4 fragPosLightSpaces[MAX_POINT_LIGHTS];

void main() 
{
	fragPosEye = view * model * vec4(vertexPosition, 1.0f);
	passTexture = textureCoords;
	normal = vertexNormal;

	for (int i = 0; i < nrPointLights; ++i)
	{
		fragPosLightSpaces[i] = lightSpaceMatrices[i] * model * vec4(vertexPosition, 1.0f);
	}

	gl_Position = projection * fragPosEye;
}
