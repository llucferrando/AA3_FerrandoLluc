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
	float sunY = sin(angle) * radius; 
	float sunZ = cos(angle) * radius;
	float moonY = sin(angle + glm::pi<float>()) * radius;
	float moonZ = cos(angle + glm::pi<float>()) * radius;

	float sunX = 0.0f;
	float moonX = 0.0f;

	_sunTransform->_position = glm::vec3(sunX, sunY, sunZ);
	_moonTransform->_position = glm::vec3(moonX, moonY, moonZ);


	float segmentDuration = cycleDuration / _cycleManager->_colours.size();
	float segmentRatio = fmod(Engine::getInstance().getTimeManager()->GetElapsedTime(), segmentDuration) / segmentDuration;

	int currentSegment = static_cast<int>(fmod(Engine::getInstance().getTimeManager()->GetElapsedTime(), cycleDuration) / segmentDuration);
	int nextSegment = (currentSegment + 1) % _cycleManager->_colours.size();

	_interpolatedColor = glm::mix(_cycleManager->_colours[currentSegment], _cycleManager->_colours[nextSegment], segmentRatio);
	_interpolatedColor = glm::vec3(_interpolatedColor.r / 255.f, _interpolatedColor.g / 255.f, _interpolatedColor.b / 255.f);

	glClearColor(_interpolatedColor.r, _interpolatedColor.g, _interpolatedColor.b, 1.0f);

	
	

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
