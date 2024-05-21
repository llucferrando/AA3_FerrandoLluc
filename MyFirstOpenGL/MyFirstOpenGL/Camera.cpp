#include "Camera.h"
#include "Engine.h"

Camera::Camera() : _fFov(45.0f), _aspectRatio(1.0), _fNear(0.1), _fFar(100.0)
{
	_position = { 0.f,1.5f,-5.f };
	_rotation = { 0.f,0.f,0.f };
	_localVectorUp = { 0.f,1.f,0.f };
	_vectorFront = { 0.f,0.f,1.f };


}

void Camera::Update(GLFWwindow* window)
{
	
	//Inputs logic function, we do the keyoard and mouse updates
	InputsLogic(window);
	//Function that does the camera view function 
	LookAt();
	
}

void Camera::LookAt()
{
	_viewMatrix = glm::lookAt(_position, _position + _vectorFront, _localVectorUp);
	MatrixView(_viewMatrix);
}

void Camera::InputsLogic(GLFWwindow* window)
{
	const float _speed = 0.05f;
	_speed* Engine::getInstance().getDeltaTime();

	if (Engine::getInstance().getKeyWPressed())
	{
		_position.z += _speed;
	}
	if (Engine::getInstance().getKeySPressed())
	{
		_position.z -= _speed;
	}
	if (Engine::getInstance().getKeyAPressed())
	{
		_position -= glm::normalize(glm::cross(_vectorFront, _localVectorUp)) * _speed;
	}
	if (Engine::getInstance().getKeyDPressed())
	{
		_position += glm::normalize(glm::cross(_vectorFront, _localVectorUp)) * _speed;
	}

	//Mouse inputs
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPosCallback(window, [](GLFWwindow* window, double xpos, double ypos) {
		Camera::getInstance().mouse_callback(window, xpos, ypos);
		});

}
void Camera:: mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	
	if (_firstMouse)
	{
		_lastX = xpos;
		_lastY = ypos;
		_firstMouse = false;
	}

	float xoffset = xpos - _lastX;
	float yoffset = _lastY - ypos;
	_lastX = xpos;
	_lastY = ypos;

	float sensitivity = 0.1f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	_yaw += xoffset;
	_pitch += yoffset;

	if (_pitch > 89.0f)
		_pitch = 89.0f;
	if (_pitch < -89.0f)
		_pitch = -89.0f;

	glm::vec3 direction;
	direction.x = cos(glm::radians(_yaw)) * cos(glm::radians(_pitch));
	direction.y = sin(glm::radians(_pitch));
	direction.z = sin(glm::radians(_yaw)) * cos(glm::radians(_pitch));
	_vectorFront = glm::normalize(direction);
}

glm::mat4 Camera::MatrixView(glm::mat4 viewMat)
{
	return viewMat;
}
