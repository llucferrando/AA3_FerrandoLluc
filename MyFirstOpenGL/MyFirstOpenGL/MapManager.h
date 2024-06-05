#pragma once
#include "MeshRenderer.h"
#include "Utils.h"
#include <vector>

class MapManager
{
public:
	MapManager();

	void InitMap();
	void PrintObj(glm::mat4 obj);

private:
	std::vector<GameObject*> gameObjects;
};

