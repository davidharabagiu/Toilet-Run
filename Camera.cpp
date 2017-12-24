//
// Camera.cpp
//
// Created by David Harabagiu aka Smecherus Maximus
// If you steal my work I will find you and I will kill you
//

#include "Camera.hpp"

namespace gps
{
	Camera::Camera()
	{
		this->cameraPosition = glm::vec3(0.0f, 0.0f, 0.0f);
		this->xRotation = 0;
		this->yRotation = 0;
		updateCameraTarget();
	}

	Camera::Camera(glm::vec3 cameraPosition)
	{
		this->cameraPosition = cameraPosition;
		this->xRotation = 0;
		this->yRotation = 0;
		updateCameraTarget();
	}

	Camera::Camera(glm::vec3 cameraPosition, float xRotation, float yRotation)
	{
		this->cameraPosition = cameraPosition;
		this->xRotation = xRotation;
		this->yRotation = yRotation;
		updateCameraTarget();
	}

	glm::mat4 Camera::getViewMatrix()
	{
		static glm::vec3 up(0.0f, 1.0f, 0.0f);
		return glm::lookAt(cameraPosition, cameraTarget, up);
	}

	void Camera::move(MOVE_DIRECTION direction, float speed)
	{
		if (direction == MOVE_FORWARD)
		{
			cameraPosition.z += glm::cos(yRotation) * speed;
			cameraPosition.x += glm::sin(yRotation) * speed;
			cameraTarget.z += glm::cos(yRotation) * speed;
			cameraTarget.x += glm::sin(yRotation) * speed;
		}
		else if (direction == MOVE_BACKWARD)
		{
			cameraPosition.z -= glm::cos(yRotation) * speed;
			cameraPosition.x -= glm::sin(yRotation) * speed;
			cameraTarget.z -= glm::cos(yRotation) * speed;
			cameraTarget.x -= glm::sin(yRotation) * speed;
		}
		else if (direction == MOVE_LEFT)
		{
			cameraPosition.z -= glm::sin(yRotation) * speed;
			cameraPosition.x += glm::cos(yRotation) * speed;
			cameraTarget.z -= glm::sin(yRotation) * speed;
			cameraTarget.x += glm::cos(yRotation) * speed;
		}
		else if (direction == MOVE_RIGHT)
		{
			cameraPosition.z += glm::sin(yRotation) * speed;
			cameraPosition.x -= glm::cos(yRotation) * speed;
			cameraTarget.z += glm::sin(yRotation) * speed;
			cameraTarget.x -= glm::cos(yRotation) * speed;
		}
	}

	void Camera::updateCameraTarget()
	{
		cameraTarget.x = cameraPosition.x + glm::sin(yRotation);
		cameraTarget.y = cameraPosition.y + glm::sin(xRotation);
		cameraTarget.z = cameraPosition.z + glm::cos(yRotation) * glm::cos(xRotation);
	}

	void Camera::rotate(float pitch, float yaw)
	{
		float newXRotation = xRotation + pitch;
		if (newXRotation <= MAX_X_ROTATION && newXRotation >= MIN_X_ROTATION)
		{
			xRotation = newXRotation;
		}

		yRotation = yRotation + yaw;

		updateCameraTarget();
	}

	void Camera::update()
	{
		if (Input::IsKeyPressed(GLFW_KEY_W))
		{
			movingForward = true;
		}
		else
		{
			movingForward = false;
		}
		if (Input::IsKeyPressed(GLFW_KEY_A))
		{
			movingLeft = true;
		}
		else
		{
			movingLeft = false;
		}
		if (Input::IsKeyPressed(GLFW_KEY_S))
		{
			movingBackward = true;
		}
		else
		{
			movingBackward = false;
		}
		if (Input::IsKeyPressed(GLFW_KEY_D))
		{
			movingRight = true;
		}
		else
		{
			movingRight = false;
		}

		if (movingForward)
		{
			move(gps::MOVE_FORWARD, SPEED);
		}
		if (movingBackward)
		{
			move(gps::MOVE_BACKWARD, SPEED);
		}
		if (movingLeft)
		{
			move(gps::MOVE_LEFT, SPEED);
		}
		if (movingRight)
		{
			move(gps::MOVE_RIGHT, SPEED);
		}

		static double lastxpos = -1;
		static double lastypos = -1;

		if (lastxpos == -1 || lastypos == -1)
		{
			lastxpos = Input::GetCursorX();
			lastypos = Input::GetCursorY();
			return;
		}

		rotate((lastypos - Input::GetCursorY()) / 250.0f, (lastxpos - Input::GetCursorX()) / 250.0f);
		lastxpos = Input::GetCursorX();
		lastypos = Input::GetCursorY();
	}
}