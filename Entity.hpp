//
// Entity.hpp
// Contains the class definition for a game entity.
// Created by David Harabagiu on 23.12.2017
//

#pragma once

#include "Model3D.hpp"

class Graphics;

class Entity
{

public:
	
	Entity(gps::Model3D& model, GLint roomId);

	void Update(float deltaTime);

	void Draw(Graphics& g);
	void Draw(Shader& s);

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

	void SetVelocity(glm::vec3 velocity)
	{
		this->velocity = velocity;
	}

	void SetRotationSpeed(glm::vec3 rotationSpeed)
	{
		this->rotationSpeed = rotationSpeed;
	}

	glm::mat4 ModelMatrix();
	void SetPosition(glm::vec3& NewPosition);
	void SetRotation(glm::vec3& NewRotation);
	void SetScale(glm::vec3& NewScale);
	
private:

	gps::Model3D& model;
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
	GLint roomId;
	glm::vec3 velocity;
	glm::vec3 rotationSpeed;

};