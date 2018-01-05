#include "Player.hpp"
#include "Input.hpp"
#include "Graphics.hpp"

Player::Player(Graphics& graphics)
	: graphics {graphics}
{
	this->position = glm::vec3(0, 4.0f, 0);
	this->rotationX = 0;
	this->rotationY = 0;

	graphics.SetCameraPosition(position);
	graphics.SetCameraRotation(rotationX, rotationY);
}

void Player::Update(double deltaTime)
{
	bool movingForward = false;
	bool movingBackward = false;
	bool movingLeft = false;
	bool movingRight = false;

	if (Input::IsKeyPressed(GLFW_KEY_W))
	{
		movingForward = true;
	}
	if (Input::IsKeyPressed(GLFW_KEY_A))
	{
		movingLeft = true;
	}
	if (Input::IsKeyPressed(GLFW_KEY_S))
	{
		movingBackward = true;
	}
	if (Input::IsKeyPressed(GLFW_KEY_D))
	{
		movingRight = true;
	}

	if (movingForward)
	{
		Move(MOVE_FORWARD, SPEED * deltaTime);
	}
	if (movingBackward)
	{
		Move(MOVE_BACKWARD, SPEED * deltaTime);
	}
	if (movingLeft)
	{
		Move(MOVE_LEFT, SPEED * deltaTime);
	}
	if (movingRight)
	{
		Move(MOVE_RIGHT, SPEED * deltaTime);
	}

	static double lastxpos = -1;
	static double lastypos = -1;

	if (lastxpos == -1 || lastypos == -1)
	{
		lastxpos = Input::GetCursorX();
		lastypos = Input::GetCursorY();
		return;
	}

	Rotate((lastypos - Input::GetCursorY()) / 250.0f, (lastxpos - Input::GetCursorX()) / 250.0f);
	lastxpos = Input::GetCursorX();
	lastypos = Input::GetCursorY();
}

void Player::Move(MOVE_DIRECTION direction, float speed)
{
	if (direction == MOVE_FORWARD)
	{
		position.z += glm::cos(rotationY) * speed;
		position.x += glm::sin(rotationY) * speed;
	}
	else if (direction == MOVE_BACKWARD)
	{
		position.z -= glm::cos(rotationY) * speed;
		position.x -= glm::sin(rotationY) * speed;
	}
	else if (direction == MOVE_LEFT)
	{
		position.z -= glm::sin(rotationY) * speed;
		position.x += glm::cos(rotationY) * speed;
	}
	else if (direction == MOVE_RIGHT)
	{
		position.z += glm::sin(rotationY) * speed;
		position.x -= glm::cos(rotationY) * speed;
	}

	distanceWalked += speed;
	GLfloat bobbingDeltaY = glm::sin(distanceWalked * 1.5f) / 10.0f;

	graphics.SetCameraPosition(position + glm::vec3(0.0f, bobbingDeltaY, 0.0f));
}

void Player::Rotate(float pitch, float yaw)
{
	float newXRotation = rotationX + pitch;
	if (newXRotation <= MAX_X_ROTATION && newXRotation >= MIN_X_ROTATION)
	{
		rotationX = newXRotation;
	}

	rotationY += yaw;

	graphics.SetCameraRotation(rotationX, rotationY);
}