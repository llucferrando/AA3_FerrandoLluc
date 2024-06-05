#include "DayNightCycleManager.h"
#include "Engine.h"

DayNightCycleManager::DayNightCycleManager()
{

    _colours.push_back(glm::vec3(5.f / 255.f, 84.f / 255.f, 123.f / 255.f));
    _colours.push_back(glm::vec3(13.f / 255.f, 115.f / 255.f, 47.f / 255.f));
    _colours.push_back(glm::vec3(65.f / 255.f, 171.f / 255.f, 185.f / 255.f));
    _colours.push_back(glm::vec3(168.f / 255.f, 223.f / 255.f, 200.f / 255.f));
    _colours.push_back(glm::vec3(205.f / 255.f, 224.f / 255.f, 137.f / 255.f));
    _colours.push_back(glm::vec3(245.f / 255.f, 216.f / 255.f, 116.f / 255.f));
    _colours.push_back(glm::vec3(255.f / 255.f, 202.f / 255.f, 106.f / 255.f));
    _colours.push_back(glm::vec3(253.f / 255.f, 202.f / 255.f, 106.f / 255.f));
    _colours.push_back(glm::vec3(247.f / 255.f, 170.f / 255.f, 87.f / 255.f));
    _colours.push_back(glm::vec3(245.f / 255.f, 137.f / 255.f, 105.f / 255.f));
    _colours.push_back(glm::vec3(22.f / 255.f, 117.f / 255.f, 123.f / 255.f));
    _colours.push_back(glm::vec3(166.f / 255.f, 75.f / 255.f, 132.f / 255.f));
    _colours.push_back(glm::vec3(88.f / 255.f, 43.f / 255.f, 128.f / 255.f));
    _colours.push_back(glm::vec3(54.f / 255.f, 28.f / 255.f, 117.f / 255.f));
    _colours.push_back(glm::vec3(41.f / 255.f, 35.f / 255.f, 107.f / 255.f));
    _colours.push_back(glm::vec3(24.f / 255.f, 33.f / 255.f, 95.f / 255.f));
    _colours.push_back(glm::vec3(1.f / 255.f, 25.f / 255.f, 77.f / 255.f));
    _colours.push_back(glm::vec3(0.f / 255.f, 29.f / 255.f, 68.f / 255.f));
    _colours.push_back(glm::vec3(0.f / 255.f, 20.f / 255.f, 44.f / 255.f));
    _colours.push_back(glm::vec3(0.f / 255.f, 30.f / 255.f, 55.f / 255.f));
    _colours.push_back(glm::vec3(1.f / 255.f, 34.f / 255.f, 71.f / 255.f));
    _colours.push_back(glm::vec3(1.f / 255.f, 44.f / 255.f, 78.f / 255.f));
    _colours.push_back(glm::vec3(1.f / 255.f, 60.f / 255.f, 90.f / 255.f));
}

void DayNightCycleManager::CycleDayNight()
{
	

}
