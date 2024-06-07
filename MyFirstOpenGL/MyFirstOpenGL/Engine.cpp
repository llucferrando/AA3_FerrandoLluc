#include "Engine.h"

Engine::Engine()
{
}

void Engine::Init()
{
	_inputManager = new InputManager();
	_timeManager = new TimeManager();
	_modelManager = new ModelManager();
	_mapManager = new MapManager();
	_meteoObjManager = new MeteoObjectsManager();
	_dayNightCycleManager = new ColorPalette();
	_mapManager->InitMap();

}

void Engine::Update(GLFWwindow* window)
{
	_timeManager->HandleTime();

	_inputManager->HandleInputs(window);

	_meteoObjManager->Update();

	_dayNightCycleManager->CycleDayNight();

	Camera::getInstance().Update(window);
}

void Engine::Render(glm::mat4 view)
{
	_mapManager->PrintObj(view);
	_meteoObjManager->RenderObjects(view);
}

