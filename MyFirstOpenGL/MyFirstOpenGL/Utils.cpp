#include "Utils.h"
#include <random>

Utils::Utils()
{
}

float Utils::RandomNumber(float min, float max)
{
   
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(min, max);
    return dis(gen);
      
}

int Utils::RandomNumber(int min, int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(min, max);
    return dis(gen);
}

glm::vec3 Utils::OrbitRotation(glm::vec3 pos)
{
    const float radius = 15.0f;
    float camX = sin(glfwGetTime()) * radius;
    float camZ = cos(glfwGetTime()) * radius;
    return pos = glm::vec3(0.f, camX, camZ);
}

glm::vec3 Utils::SpawnRandomPoint(std::vector<glm::vec3>& positions)
{
    int index = RandomNumber(0, positions.size() - 1);
    glm::vec3 pos = positions[index]; 
    positions.erase(positions.begin() + index);
    return pos;
}

