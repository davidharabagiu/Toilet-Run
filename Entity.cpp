//
// Entity.cpp
// Contains the class definition for a game entity.
// Created by David Harabagiu on 23.12.2017
//

#include "Entity.hpp"

Entity::Entity(gps::Model3D& model)
	: model {model}
{
	SetPosition(glm::vec3(0.0f, 0.0f, 0.0f));
	SetRotation(glm::vec3(0.0f, 0.0f, 0.0f));
	SetScale(glm::vec3(1.0f, 1.0f, 1.0f));
}

void Entity::Draw(Graphics& g)
{
	g.Draw(model, position, rotation, scale);
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
