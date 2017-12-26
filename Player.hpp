#pragma once

#include "Graphics.hpp"
#define SPEED 0.05f

class Player
{
	enum MOVE_DIRECTION { MOVE_FORWARD, MOVE_BACKWARD, MOVE_RIGHT, MOVE_LEFT };

public:

	Player(Graphics& graphics);
	void Update();

private:

	Graphics& graphics;
	glm::vec3 position;
	GLfloat rotationX;
	GLfloat rotationY;
	GLfloat distanceWalked;
	void Move(MOVE_DIRECTION direction, float speed);
	void Rotate(float pitch, float yaw);

};