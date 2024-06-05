#pragma once
#include "MeshRenderer.h"
#include "DayNightCycleManager.h"
#include "Light.h"



class MeteoObjectsManager
{
public:
	MeteoObjectsManager();

	void Update();
	void RenderObjects(glm::mat4 view);
	glm::vec3 GetSunPos() { return _sunTransform->_position; }
	glm::vec3 GetMoonPos() { return _moonTransform->_position; }
	glm::vec3 GetInterpolatedColor() { return _interpolatedColor; }

private:
	void InitObjects();
	GameObject* _sun;
	GameObject* _moon;
	Transform* _sunTransform;
	Transform* _moonTransform;
	DayNightCycleManager* _cycleManager;
	glm::vec3 _interpolatedColor;
	float _timeElapsed;

};

