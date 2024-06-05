#pragma once
#include "Component.h"
#include "GameObject.h"

class Light : public Component
{
public:
	Light(GameObject * owner, glm::vec3 pos, glm::vec3 dir);
	const std::type_index GetType() override;
	glm::vec3 GetLightPos() { return _transform->_position; }
	glm::vec3 GetLightDir() { return _transform->_direction; }


private:
	GameObject * _owner;
	Transform* _transform;

};

