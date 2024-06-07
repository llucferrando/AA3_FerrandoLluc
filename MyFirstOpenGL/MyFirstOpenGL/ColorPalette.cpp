#include "ColorPalette.h"
#include "Engine.h"

ColorPalette::ColorPalette()
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

void ColorPalette::CycleDayNight()
{
	
	float  cycleDuration = 40.f;

	float segmentDuration = cycleDuration / _colours.size();
	float segmentRatio = fmod(Engine::getInstance().getTimeManager()->GetElapsedTime(), segmentDuration) / segmentDuration;

	int currentSegment = static_cast<int>(fmod(Engine::getInstance().getTimeManager()->GetElapsedTime(), cycleDuration) / segmentDuration);
	int nextSegment = (currentSegment + 1) % _colours.size();

	_interpolatedColor = glm::mix(_colours[currentSegment],_colours[nextSegment], segmentRatio);
	_interpolatedColor = glm::vec3(_interpolatedColor.r / 255.f, _interpolatedColor.g / 255.f, _interpolatedColor.b / 255.f);
	glClearColor(_interpolatedColor.r, _interpolatedColor.g, _interpolatedColor.b, 1.0f);
}

