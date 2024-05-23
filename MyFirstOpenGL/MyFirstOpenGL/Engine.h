#pragma once
#include "Model.h"


class Engine
{
public:
	//Singleton to call from everywhere
	static Engine& getInstance() { static Engine instance; return instance; }
	Engine();

	//Functions utils
	Model* LoadOBJModel(int IDProgram, const std::string& filePath, const char* texturefilePath, const std::string& matFilePath,GLenum textureUnit, ModelType type);
	void Init();
	void Update(GLFWwindow* window);
	void InputTransforms(GLFWwindow* window);
	void mouse_callback(GLFWwindow* window, double xpos, double ypos);


	//Getters
	float getDeltaTime() const { return deltaTime; }
	bool getKeyWPressed() const { return keyWPressed; }
	bool getKeyAPressed() const { return keyAPressed; }
	bool getKeySPressed() const { return keySPressed; }
	bool getKeyDPressed() const { return keyDPressed; }

	float getYaw() const { return yaw; }
	float getPitch() const { return pitch; }
	float getLastX() const { return lastX; }
	float getLastY() const { return lastY; }
	bool getFirstMouse() const { return firstMouse; }

	void setYaw(float _yaw)  { yaw = _yaw; }
	void setPitch(float _pitch)  { pitch = _pitch; }
	void setLastX(float _lastX)  { lastX = _lastX; }
	void setLastY(float _lastY)  {  lastY = _lastY; }
	void setFirstMouse(bool _firstMouse)  {  firstMouse = _firstMouse; }
	
private:
	//Input variables
	bool keyWPressed;
	bool keyAPressed;
	bool keySPressed;
	bool keyDPressed;

	float yaw;
	float pitch;
	float lastX;
	float lastY;
	bool firstMouse;
	//Time variables
	float deltaTime;
	 float lastFrameTime;
	Engine(const Engine&) = delete;
	Engine& operator=(const Engine&) = delete;
};

