//
// Entity.hpp
// Contains the class definition for a game entity.
// Created by David Harabagiu on 23.12.2017
//

#pragma once

#include "Model3D.hpp"
#include "Shader.hpp"
#include "glm/glm/gtc/matrix_transform.hpp"
#include "glm/glm/gtc/type_ptr.hpp"

class Entity
{

public:
	
	Entity(gps::Model3D& model, Shader& shader);

	virtual void Update()
	{
	}

	void Draw();

	glm::vec3 Position()
	{
		return position;
	}

	glm::vec3 Rotation()
	{
		return rotation;
	}

	glm::vec3 Scale()
	{
		return scale;
	}

	void SetPosition(glm::vec3& NewPosition);
	void SetRotation(glm::vec3& NewRotation);
	void SetScale(glm::vec3& NewScale);
	
private:

	gps::Model3D model;
	Shader& shader;
	glm::mat4 modelTransform;
	glm::mat4 translationMatrix;
	glm::mat4 rotationMatrix;
	glm::mat4 scaleMatrix;
	GLuint modelTransformLoc;
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;

	void UpdateTransformMatrix();

};