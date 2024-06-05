#include "TimeManager.h"


TimeManager::TimeManager() : deltaTime(0)
{
	lastFrameTime = static_cast<float>(glfwGetTime());
	_elapsedTime = 0;
}

void TimeManager::HandleTime()
{
	float currentFrameTime = static_cast<float>(glfwGetTime());
	deltaTime = currentFrameTime - lastFrameTime;
	lastFrameTime = currentFrameTime;
	_elapsedTime += deltaTime;
}
