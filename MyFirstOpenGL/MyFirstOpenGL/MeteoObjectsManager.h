#pragma once
#include "MeshRenderer.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <gtc/type_ptr.hpp>
#include <gtc/matrix_transform.hpp>


class MeteoObjectsManager
{
public:
	MeteoObjectsManager();

	void Update();
	void RenderObjects(glm::mat4 view);
	glm::vec3 GetSunPos() { return _sunTransform->_position; }
	glm::vec3 GetMoonPos() { return _moonTransform->_position; }

private:
	void InitObjects();
	GameObject* _sun;
	GameObject* _moon;
	Transform* _sunTransform;
	Transform* _moonTransform;
	float _timeElapsed;

};

