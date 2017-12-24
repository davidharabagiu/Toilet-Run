//
// Entity.cpp
// Contains the class definition for a game entity.
// Created by David Harabagiu on 23.12.2017
//

#include "Entity.hpp"

Entity::Entity(gps::Model3D& model, Shader& shader)
	: model {model}, shader{shader}
{
	this->modelTransformLoc = glGetUniformLocation(shader.GetShaderProgram(), "model");
	SetPosition(glm::vec3(0.0f, 0.0f, 0.0f));
	SetRotation(glm::vec3(0.0f, 0.0f, 0.0f));
	SetScale(glm::vec3(1.0f, 1.0f, 1.0f));
}

void Entity::Draw()
{
	glUniformMatrix4fv(modelTransformLoc, 1, GL_FALSE, glm::value_ptr(modelTransform));
	model.Draw(shader);
}

void Entity::SetPosition(glm::vec3& NewPosition)
{
	position = NewPosition;
	UpdateTransformMatrix();
}

void Entity::SetRotation(glm::vec3& NewRotation)
{
	rotation = NewRotation;
	UpdateTransformMatrix();
}

void Entity::SetScale(glm::vec3& NewScale)
{
	scale = NewScale;
	UpdateTransformMatrix();
}

void Entity::UpdateTransformMatrix()
{
	glm::mat4 tr = glm::mat4(1.0f);
	tr = glm::translate(tr, this->position);
	tr = glm::rotate(tr, rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
	tr = glm::rotate(tr, rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
	tr = glm::rotate(tr, rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
	tr = glm::scale(tr, scale);
	this->modelTransform = tr;
}