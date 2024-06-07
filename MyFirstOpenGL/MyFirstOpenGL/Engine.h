#pragma once
#include "Model.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "ModelManager.h"
#include "MapManager.h"
#include "MeteoObjectsManager.h"


class Engine
{
public:
	//Singleton to call from everywhere
	static Engine& getInstance() { static Engine instance; return instance; }
	Engine();

	//Functions utils
	void Init();
	void Update(GLFWwindow* window);
	void Render(glm::mat4 view);
	

	//Getters
	InputManager* getInputManager() { return _inputManager; };
	TimeManager* getTimeManager() { return _timeManager; };
	ModelManager* GetModelManager() { return _modelManager; };
	MeteoObjectsManager* GetMeteoManager() { return _meteoObjManager; };
	ColorPalette* GetDayNightManager() { return _dayNightCycleManager; };
	
private:
	InputManager* _inputManager;
	TimeManager* _timeManager;
	ModelManager* _modelManager;
	MapManager* _mapManager;
	MeteoObjectsManager* _meteoObjManager;
	ColorPalette * _dayNightCycleManager;
	
	Engine(const Engine&) = delete;
	Engine& operator=(const Engine&) = delete;
};

