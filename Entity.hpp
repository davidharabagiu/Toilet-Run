//
// Entity.hpp
// Contains the class definition for a game entity.
// Created by David Harabagiu on 23.12.2017
//

#pragma once

#include "Model3D.hpp"
#include "Graphics.hpp"

class Graphics;

class Entity
{

public:
	
	Entity(gps::Model3D& model);

	virtual void Update()
	{
	}

	void Draw(Graphics& g);

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
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;

};