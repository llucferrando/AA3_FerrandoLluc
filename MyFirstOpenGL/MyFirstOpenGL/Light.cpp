#include "Light.h"



Light::Light(GameObject* owner, glm::vec3 pos, glm::vec3 dir) 
{
	_owner = owner;
	_transform = _owner->GetComponent<Transform>();
	_transform->_position = pos;
	_transform->_direction = dir;
}

const std::type_index Light::GetType()
{
	return typeid(Light);
}
