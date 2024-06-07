#pragma once
#include "MeshRenderer.h"
#include "ColorPalette.h"
#include "Light.h"



class MeteoObjectsManager
{
public:
	MeteoObjectsManager();

	void Update();
	void RenderObjects(glm::mat4 view);
	glm::vec3 GetSunPos() { return _sunTransform->_position; }
	glm::vec3 GetMoonPos() { return _moonTransform->_position; }
	void ObjectsMovement();

private:
	void InitObjects();
	GameObject* _sun;
	GameObject* _moon;
	Transform* _sunTransform;
	Transform* _moonTransform;
	ColorPalette* _cycleManager;

	float _timeElapsed;

};

