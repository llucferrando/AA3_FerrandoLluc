#pragma once
#include <vector>
#include <glm.hpp>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <gtc/type_ptr.hpp>
#include <gtc/matrix_transform.hpp>


class DayNightCycleManager
{
public:
	DayNightCycleManager();
	void CycleDayNight();
	std::vector<glm::vec3> _colours;

};

