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
	float timeRatio = _timeElapsed / cycleDuration;
	float angle = timeRatio * glm::two_pi<float>();

	const float radius = 1500.0f;
	float sunY = cos(angle) * radius;
	float sunZ = sin(angle) * radius;
	float moonY = cos(angle + glm::pi<float>()) * radius;
	float moonZ = sin(angle + glm::pi<float>()) * radius;

	float sunX = 0.0f;
	float moonX = 0.0f;

	_sunTransform->_position = glm::vec3(sunX, sunY, sunZ);
	_moonTransform->_position = glm::vec3(moonX, moonY, moonZ);

	// Calcula el valor de interpolación entre 0 y 1
	float interpolationValue = 0.5f * (1.0f + cos(angle));

	// Utiliza clamp para asegurarse de que el valor de interpolación esté dentro del rango [0, 1]
	interpolationValue = glm::clamp(interpolationValue, 0.0f, 1.0f);

	// Define los colores de día y noche
	glm::vec3 colorDay(0.0f, 0.0f, 0.3f);        // Azul oscuro
	glm::vec3 colorNight(1.0f, 1.0f, 0.7f);      // Amarillo claro

	// Interpolación lineal entre los dos colores
	glm::vec3 interpolatedColor = glm::mix(colorDay, colorNight, interpolationValue);

	// Actualiza el color de fondo
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
	_sunTransform->_rotation = glm::vec3{ 0.f,0.f,0.f };
	_sunTransform->_scale = glm::vec3{ 5.f,5.f,5.f };

	_moon->AddComponent<MeshRenderer>(new Model(*Engine::getInstance().GetModelManager()->GetModelByType(ModelType::Moon)), _moon);
	
	_moonTransform->_position = glm::vec3{ -1500.f,0.f,0.f };
	_moonTransform->_rotation = glm::vec3{ 0.f,0.f,0.f };
	_moonTransform->_scale = glm::vec3{ 5.f,5.f,5.f };

	
}
