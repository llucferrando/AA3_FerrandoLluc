#include "DayNightCycleManager.h"
#include "Engine.h"

DayNightCycleManager::DayNightCycleManager()
{
	_colours.push_back(glm::vec3(104, 209, 202));
	_colours.push_back(glm::vec3(170, 221, 188));
	_colours.push_back(glm::vec3(235, 232, 137));
	_colours.push_back(glm::vec3(255, 223, 104));
	_colours.push_back(glm::vec3(252, 222, 100));
	_colours.push_back(glm::vec3(252, 224, 102));
	_colours.push_back(glm::vec3(253, 203, 96));
	_colours.push_back(glm::vec3(248, 163, 90));
	_colours.push_back(glm::vec3(239, 134, 109));
	_colours.push_back(glm::vec3(245, 69, 31));
	_colours.push_back(glm::vec3(107, 53, 131));
	_colours.push_back(glm::vec3(68, 31, 122));
	_colours.push_back(glm::vec3(54, 32, 115));
	_colours.push_back(glm::vec3(34, 42, 110));
	_colours.push_back(glm::vec3(0, 34, 86));
	_colours.push_back(glm::vec3(1, 20, 37));
	_colours.push_back(glm::vec3(0, 21, 38));
	_colours.push_back(glm::vec3(0, 21, 38));
	_colours.push_back(glm::vec3(1, 26, 48));
	_colours.push_back(glm::vec3(1, 24, 55));
	_colours.push_back(glm::vec3(0, 30, 56));
	_colours.push_back(glm::vec3(5, 49, 76));
	_colours.push_back(glm::vec3(9, 84, 117));
	_colours.push_back(glm::vec3(26, 139, 169));

}

