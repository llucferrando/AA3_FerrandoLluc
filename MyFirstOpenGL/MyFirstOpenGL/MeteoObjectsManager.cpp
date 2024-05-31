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
	glm::vec3(0.9f, 0.6f, 0.3f),   // Color del cielo al amanecer


	// Mañana
   glm::vec3(0.8f, 1.0f, 1.0f),    // Color del cielo por la mañana
   // Mediodía
   glm::vec3(0.8f, 1.0f, 1.0f),    // Color del cielo al mediodía
   // Tarde
   glm::vec3(0.7f, 0.9f, 1.0f),    // Color del cielo por la tarde
   // Atardecer
   glm::vec3(0.9f, 0.4f, 0.2f),    // Color del cielo al atardecer
   glm::vec3(0.8f, 0.3f, 0.1f),    // Color del cielo al atardecer más oscuro
   glm::vec3(0.6f, 0.2f, 0.0f),    // Color del cielo al atardecer más oscuro
   // Anochecer
   glm::vec3(0.4f, 0.1f, 0.0f),    // Color del cielo al anochecer
   glm::vec3(0.2f, 0.05f, 0.0f),   // Color del cielo al anochecer más oscuro
   // Noche
   glm::vec3(0.0f, 0.1f, 0.3f),    // Color del cielo nocturno

   // Noche
  glm::vec3(0.0f, 0.1f, 0.3f),    // Color del cielo nocturno
  glm::vec3(0.0f, 0.05f, 0.25f),  // Color del cielo nocturno más oscuro
  glm::vec3(0.0f, 0.1f, 0.6f),    // Color del cielo nocturno
  glm::vec3(0.0f, 0.1f, 0.7f),    // Color del cielo nocturno
  // Amanecer
  glm::vec3(0.0f, 0.2f, 0.4f),    // Color del cielo al amanecer más oscuro
  glm::vec3(0.1f, 0.3f, 0.5f),    // Color del cielo al amanecer
  glm::vec3(0.2f, 0.4f, 0.6f),    // Color del cielo al amanecer
  glm::vec3(0.3f, 0.5f, 0.7f),    // Color del cielo al amanecer
  glm::vec3(0.4f, 0.6f, 0.8f),    // Color del cielo al amanecer
  glm::vec3(0.5f, 0.7f, 0.9f),    // Color del cielo al amanecer
  glm::vec3(0.6f, 0.8f, 1.0f),    // Color del cielo al amanecer
	};

	
	int colorIndex1 = static_cast<int>(floor(timeRatio * (colors.size() - 1)));
	int colorIndex2 = (colorIndex1 + 1) % colors.size();

	float interpolationValue = fmod(timeRatio * (colors.size() - 1), 1.0f);

	// Interpolación lineal entre los dos colores adyacentes
	glm::vec3 interpolatedColor = glm::mix(colors[colorIndex1], colors[colorIndex2], interpolationValue);

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
