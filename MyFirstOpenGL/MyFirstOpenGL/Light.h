#pragma once
#include "Component.h"

class Light : public Component
{
	Light();


private:
	glm::vec3 _direction;
	float _angle;
	//GameObject* _owner;
	//Transform* _transform;
};

