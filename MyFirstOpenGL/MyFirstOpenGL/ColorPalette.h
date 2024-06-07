#pragma once
#include <vector>
#include <glm.hpp>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <gtc/type_ptr.hpp>
#include <gtc/matrix_transform.hpp>


class ColorPalette
{
public:
	ColorPalette();
	void CycleDayNight();
	glm::vec3 GetInterpolatedColor() { return _interpolatedColor; }

private:
	std::vector<glm::vec3> _colours;
	glm::vec3 _interpolatedColor;

};

