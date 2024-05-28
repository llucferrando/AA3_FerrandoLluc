#pragma once
#include "Model.h"
#include "Texture.h"


class Utils
{
public:
	//Singleton to call from everywhere
	static Utils& getInstance() { static Utils instance; return instance; }
	Utils();

    static float RandomNumber(float min, float max);
    static int RandomNumber(int min, int max);
	glm::vec3 OrbitRotation(glm::vec3 pos);

	static glm::vec3 SpawnRandomPoint(std::vector<glm::vec3>& positions);



private:
	Utils(const Utils&) = delete;
	Utils& operator=(const Utils&) = delete;
};



