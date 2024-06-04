#include "MeteoObjectsManager.h"
#include "Engine.h"

MeteoObjectsManager::MeteoObjectsManager()
{
	InitObjects();
	_cycleManager = new DayNightCycleManager();
}

void MeteoObjectsManager::Update()
{

	_timeElapsed += Engine::getInstance().getTimeManager()->getDeltaTime();

	float cycleDuration = 40.0f;
	float timeRatio = fmod(_timeElapsed, cycleDuration) / cycleDuration;
	float angle = timeRatio * glm::two_pi<float>();

	const float radius = 1500.0f;
	float sunY = sin(angle) * radius; // Ajuste para que comience en y=0
	float sunZ = cos(angle) * radius;
	float moonY = sin(angle + glm::pi<float>()) * radius;
	float moonZ = cos(angle + glm::pi<float>()) * radius;

	float sunX = 0.0f;
	float moonX = 0.0f;

	_sunTransform->_position = glm::vec3(sunX, sunY, sunZ);
	_moonTransform->_position = glm::vec3(moonX, moonY, moonZ);

	std::vector<glm::vec3> colors = {

	   glm::vec3(0.9f, 0.6f, 0.3f), // Mañana
	   glm::vec3(0.8f, 1.0f, 1.0f), // Mediodía
	   glm::vec3(0.7f, 0.9f, 1.0f), // Tarde
	   glm::vec3(0.9f, 0.4f, 0.2f), // Atardecer
	   glm::vec3(0.8f, 0.3f, 0.1f), // Atardecer más oscuro
	   glm::vec3(0.6f, 0.2f, 0.0f), // Atardecer más oscuro
	   glm::vec3(0.4f, 0.1f, 0.0f), // Anochecer
	   glm::vec3(0.2f, 0.05f, 0.0f),// Anochecer más oscuro
	   glm::vec3(0.0f, 0.1f, 0.3f), // Noche
	   glm::vec3(0.0f, 0.05f, 0.25f),// Noche más oscuro
	   glm::vec3(0.0f, 0.1f, 0.6f), // Noche
	   glm::vec3(0.0f, 0.1f, 0.7f), // Noche
	   glm::vec3(0.0f, 0.2f, 0.4f), // Amanecer más oscuro
	   glm::vec3(0.1f, 0.3f, 0.5f), // Amanecer
	   glm::vec3(0.2f, 0.4f, 0.6f), // Amanecer
	   glm::vec3(0.3f, 0.5f, 0.7f), // Amanecer
	   glm::vec3(0.4f, 0.6f, 0.8f), // Amanecer
	   glm::vec3(0.5f, 0.7f, 0.9f), // Amanecer
	   glm::vec3(0.6f, 0.8f, 1.0f), // Amanecer
	};

	int colorIndex1 = static_cast<int>(floor(timeRatio * (colors.size() - 1)));
	int colorIndex2 = (colorIndex1 + 1) % colors.size();

	float interpolationValue = fmod(timeRatio * (colors.size() - 1), 1.0f);

	glm::vec3 interpolatedColor = glm::mix(colors[colorIndex1], colors[colorIndex2], interpolationValue);

	glClearColor(interpolatedColor.r, interpolatedColor.g, interpolatedColor.b, 1.0f);

	
	

}

void MeteoObjectsManager::RenderObjects(glm::mat4 view)
{
	
	_sun->GetComponent<MeshRenderer>()->Render(view);
	_moon->GetComponent<MeshRenderer>()->Render(view);
}

void MeteoObjectsManager::InitObjects()
{
	_sun = new GameObject;
	_moon = new GameObject;
	_sunTransform = _sun->GetComponent<Transform>();
	_moonTransform = _moon->GetComponent<Transform>();

	_sun->AddComponent<MeshRenderer>(new Model(*Engine::getInstance().GetModelManager()->GetModelByType(ModelType::Sun)), _sun);
	_sunTransform->_position = glm::vec3{ 1500.f,0.f,0.f };
	_sunTransform->_direction = glm::vec3{ 0.f,0.f,0.f };
	_sunTransform->_rotation = glm::vec3{ 0.f,0.f,0.f };
	_sunTransform->_scale = glm::vec3{ 5.f,5.f,5.f };
	_sun->AddComponent<Light>(_sun,_sunTransform->_position,_sunTransform->_direction);

	_moon->AddComponent<MeshRenderer>(new Model(*Engine::getInstance().GetModelManager()->GetModelByType(ModelType::Moon)), _moon);
	_moonTransform->_position = glm::vec3{ -1500.f,0.f,0.f };
	_moonTransform->_direction = glm::vec3{ 0.f,0.f,0.f };
	_moonTransform->_rotation = glm::vec3{ 0.f,0.f,0.f };
	_moonTransform->_scale = glm::vec3{ 5.f,5.f,5.f };
	_moon->AddComponent<Light>(_moon,_moonTransform->_position,_moonTransform->_direction);
	
}
