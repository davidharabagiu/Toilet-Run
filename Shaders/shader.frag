#version 410 core
#define MAX_POINT_LIGHTS 9

struct PointLight
{
	vec3 position;
	vec3 color;
};

in vec2 passTexture;
in vec3 normal;
in vec4 fragPosEye;
in vec4 fragPosLightSpaces[MAX_POINT_LIGHTS];

uniform sampler2D diffuseTexture;
uniform sampler2D shadowMaps[MAX_POINT_LIGHTS];
uniform mat3 normalMatrix;
uniform PointLight pointLights[MAX_POINT_LIGHTS];
uniform int nrPointLights;
uniform mat4 view;
uniform bool shadowsOn = true;
uniform int roomId;

out vec4 fragmentColor;

float ambientStrength = 0.4f;
float specularStrength = 0.01f;
float shininess = 0.5f;
float constant = 2.5f;
float linear = 0.00425f;
float quadratic = 0.00375f;

float ShadowCalculation(vec4 fragPosLightSpace, sampler2D shadowMap)
{
	vec3 projCoords = fragPosLightSpace.xyz / fragPosLightSpace.w;
	if (projCoords.z > 1.0f)
	{
		return 0.0f;
	}
	projCoords = projCoords * 0.5f + 0.5f;
	float closestDepth = texture(shadowMap, projCoords.xy).r;
	float currentDepth = projCoords.z;
	float shadow = (currentDepth - 0.05f) > closestDepth ? 1.0f : 0.0f;

	return shadow;
}

vec3 CalcPointLight(vec4 lightPosEye, vec4 fragPosLightSpace, sampler2D shadowMap, vec3 color, int id)
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

	float shadow = 0.0f;

	if (id == roomId)
	{
		shadow = ShadowCalculation(fragPosLightSpace, shadowMap);
	}
	
	return (ambient + (1.0 - shadow) * (diffuse + specular)) * att;
}

void main() 
{
	vec4 diffuseColor = texture(diffuseTexture, passTexture);

	vec3 totalLight = vec3(0.0f);
	for (int i = 0; i < nrPointLights; i++)
	{
		vec4 lightPosEye = view * vec4(pointLights[i].position, 1.0f);
		totalLight += CalcPointLight(lightPosEye, fragPosLightSpaces[i], shadowMaps[i], pointLights[i].color, i);
	}

    fragmentColor = min(diffuseColor * vec4(totalLight, 1.0f), 1.0f);
}
