#pragma once
#include <GLFW/glfw3.h>
class TimeManager
{
public:
	TimeManager();
	void HandleTime();

	float getDeltaTime() { return deltaTime; };
	float GetElapsedTime() { return _elapsedTime; };

private:
	float deltaTime;
	float lastFrameTime;
	float _elapsedTime;
};

