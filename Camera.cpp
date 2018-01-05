//
// Camera.cpp
//
// Created by David Harabagiu aka Smecherus Maximus
// If you steal my work I will find you and I will kill you
//

#include "Camera.hpp"
#include "Input.hpp"

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

	void Camera::updateCameraTarget()
	{
		cameraTarget.x = cameraPosition.x + glm::sin(yRotation);
		cameraTarget.y = cameraPosition.y + glm::sin(xRotation);
		cameraTarget.z = cameraPosition.z + glm::cos(yRotation) * glm::cos(xRotation);
	}

	void Camera::SetPosition(glm::vec3 position)
	{
		this->cameraPosition = position;
		updateCameraTarget();
	}

	void Camera::SetRotation(GLfloat newXRotation, GLfloat newYRotation)
	{
		this->xRotation = newXRotation;
		this->yRotation = newYRotation;
		updateCameraTarget();
	}

	glm::vec3 Camera::Target()
	{
		return cameraTarget;
	}
}