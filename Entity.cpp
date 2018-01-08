//
// Entity.cpp
// Contains the class definition for a game entity.
// Created by David Harabagiu on 23.12.2017
//

#include "Entity.hpp"
#include "Graphics.hpp"

Entity::Entity(gps::Model3D& model, GLint roomId)
	: model {model}, roomId {roomId}
{
	SetPosition(glm::vec3(0.0f, 0.0f, 0.0f));
	SetRotation(glm::vec3(0.0f, 0.0f, 0.0f));
	SetScale(glm::vec3(1.0f, 1.0f, 1.0f));
	rotationSpeed = glm::vec3(0.0f);
	velocity = glm::vec3(0.0f);
}

void Entity::Draw(Graphics& g)
{
	g.Draw(model, position, rotation, scale, roomId);
}

void Entity::Draw(Shader& s)
{
	model.Draw(s);
}

void Entity::SetPosition(glm::vec3& NewPosition)
{
	position = NewPosition;
}

void Entity::SetRotation(glm::vec3& NewRotation)
{
	rotation = NewRotation;
}

void Entity::SetScale(glm::vec3& NewScale)
{
	scale = NewScale;
}

glm::mat4 Entity::ModelMatrix()
{
	glm::mat4 tr = glm::mat4(1.0f);
	tr = glm::translate(tr, position);
	tr = glm::rotate(tr, rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
	tr = glm::rotate(tr, rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
	tr = glm::rotate(tr, rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
	tr = glm::scale(tr, scale);
	return tr;
}

void Entity::Update(float deltaTime)
{
	if (rotationSpeed.y != 0.0f)
	{
		int a = 1;
	}
	position += velocity * deltaTime;
	rotation += rotationSpeed * deltaTime;
	glm::vec3 cacat = rotationSpeed * deltaTime;
}
