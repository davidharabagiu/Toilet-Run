#version 410 core
#define MAX_POINT_LIGHTS 10

struct PointLight
{
	vec3 position;
	vec3 color;
};

in vec2 passTexture;
in vec3 normal;
in vec4 fragPosEye;

uniform sampler2D diffuseTexture;
uniform mat3 normalMatrix;
uniform PointLight pointLights[MAX_POINT_LIGHTS];
uniform int nrPointLights;
uniform mat4 view;

out vec4 fragmentColor;

float ambientStrength = 4.0f;
float specularStrength = 0.5f;
float shininess = 32.0f;
float constant = 1.0f;
float linear = 0.00225f;
float quadratic = 0.00375f;

vec3 CalcPointLight(vec4 lightPosEye, vec3 color)
{
	vec3 cameraPosEye = vec3(0.0f);
	vec3 normalEye = normalize(normalMatrix * normal);
	vec3 lightDirN = normalize(lightPosEye.xyz - fragPosEye.xyz);
	vec3 viewDirN = normalize(cameraPosEye - fragPosEye.xyz);
	vec3 ambient = ambientStrength * color;
	vec3 diffuse = max(dot(normalEye, lightDirN), 0.0f) * color;
	vec3 halfVector = normalize(lightDirN + viewDirN);
	vec3 reflection = reflect(-lightDirN, normalEye);
	float specCoeff = pow(max(dot(normalEye, halfVector), 0.0f), shininess);
	vec3 specular = specularStrength * specCoeff * color;

	float distance = length(lightPosEye.xyz - fragPosEye.xyz);
	float att = 1.0f / (constant + linear * distance + quadratic * distance * distance);

	return (ambient + diffuse + specular) * att;
}

void main() 
{
	vec4 diffuseColor = texture(diffuseTexture, passTexture);

	vec3 totalLight = vec3(0.0f);
	for (int i = 0; i < nrPointLights; i++)
	{
		vec4 lightPosEye = view * vec4(pointLights[i].position, 1.0f);
		totalLight += CalcPointLight(lightPosEye, pointLights[i].color);
	}

    fragmentColor = min(diffuseTexture * vec4(totalLight, 1.0f), 1.0f);
}
