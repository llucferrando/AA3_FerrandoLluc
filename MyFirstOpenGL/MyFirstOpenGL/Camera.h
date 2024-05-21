
#pragma once
#include "GameObject.h"

enum CameraState { Orbit = 0, FocusTroll1 = 1, FocusTroll2 = 2, FocusTroll3 = 3 };
class Camera : public GameObject
{
public:
	static Camera& getInstance() { static Camera instance; return instance; }
	Camera();


	//Getters
	float getfFov() const { return _fFov; }
	float getAspectRatio() const { return _aspectRatio; }
	float getfNear() const { return _fNear; }
	float getfFar() const { return _fFar; }
	float getXPos() const { return _position.x; }
	float getYPos() const { return _position.y; }

	
	glm::mat4 getViewMatrix() const { return _viewMatrix; }
	

	//Setters
	void setfFov(float fFov) { _fFov = fFov; }
	void setaspectRatio(float aspectRatio) { _aspectRatio = aspectRatio; }
	void setfNear(float fNear) { _fNear = fNear; }
	void set_fFar(float fFar) { _fFar = fFar; }
	void setOrbit(CameraState state) { myCameraState = state; }
	void setXPos(float xPos) { _position.x = xPos; }
	void setYPos(float yPos) { _position.y = yPos; }
	void setVectorFront(glm::vec3 vFront) { _vectorFront = vFront; }


	

	void Update(GLFWwindow* window);
	void LookAt();
	void InputsLogic(GLFWwindow* window);
	void mouse_callback(GLFWwindow* window, double xpos, double ypos);
	glm::mat4 MatrixView(glm::mat4 viewMat);

private:
	Camera(const Camera&) = delete;
	void operator=(const Camera&) = delete;

	float _yaw;
	float _pitch;
	float _lastX;
	float _lastY;
	bool _firstMouse;

	float _fFov;
	float _aspectRatio;
	float _fNear;
	float _fFar;
	
	


	
	glm::mat4 _viewMatrix;
	CameraState myCameraState;
	
};


