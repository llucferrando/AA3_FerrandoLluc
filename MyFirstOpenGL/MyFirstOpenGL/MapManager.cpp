#include "MapManager.h"
#include "Engine.h"


MapManager::MapManager()
{
}

void MapManager::PrintObj(glm::mat4 obj)
{

	for (GameObject* gameObject : gameObjects)
	{
		gameObject->GetComponent<MeshRenderer>()->Render(obj);
		
	}
}

void MapManager::InitMap()
{

	std::vector<glm::vec3>positions;
	
	positions.push_back(glm::vec3(-300.f, 0.f, -300.f));
	positions.push_back(glm::vec3(-300.f, 0.f, 300.f));
	positions.push_back(glm::vec3(300.f, 0.f, 300.f));
	positions.push_back(glm::vec3(300.f, 0.f, -300.f));
	positions.push_back(glm::vec3(150.f, 0.f, 150.f));
	positions.push_back(glm::vec3(150.f, 0.f, -150.f));
	positions.push_back(glm::vec3(-150.f, 0.f, 150.f));
	positions.push_back(glm::vec3(550.f, 0.f, -200.f));
	positions.push_back(glm::vec3(0.f, 0.f, 0.f));



	//----------LANDSCAPE--------------
	GameObject* terrain = new GameObject();
	terrain->AddComponent<MeshRenderer>(new Model(*Engine::getInstance().GetModelManager()->GetModelByType(ModelType::Landscape)), terrain);
	Transform* transform = terrain->GetComponent<Transform>();
	transform->_position = glm::vec3{ 0.f,0.f,0.f };
	transform->_rotation = glm::vec3{ 0.f,0.f,0.f };
	transform->_scale = glm::vec3{ .5f,.5f,.5f };
	gameObjects.push_back(terrain);

	//---------GENERATE ROCKS-----------
	GameObject* rock1 = new GameObject();
	rock1->AddComponent<MeshRenderer>(new Model(*Engine::getInstance().GetModelManager()->GetModelByType(ModelType::Rock)), rock1);
	rock1->GetComponent<Transform>()->_position = Utils::getInstance().SpawnRandomPoint(positions);
	rock1->GetComponent<Transform>()->_rotation = { Utils::getInstance().RandomNumber(0, 5), Utils::getInstance().RandomNumber(0, 50), 0.f};
	float scale = Utils::getInstance().RandomNumber(0.5f,2.f);
	rock1->GetComponent<Transform>()->_scale = { scale, scale, scale };

	GameObject* rock2 = new GameObject();
	rock2->AddComponent<MeshRenderer>(new Model(*Engine::getInstance().GetModelManager()->GetModelByType(ModelType::Rock)), rock2);
	rock2->GetComponent<Transform>()->_position = Utils::getInstance().SpawnRandomPoint(positions);
	rock2->GetComponent<Transform>()->_rotation = { Utils::getInstance().RandomNumber(0, 5), Utils::getInstance().RandomNumber(0, 50), 0.f};
	scale = Utils::getInstance().RandomNumber(0.5f, 2.f);
	rock2->GetComponent<Transform>()->_scale = { scale, scale, scale };

	GameObject* rock3 = new GameObject();
	rock3->AddComponent<MeshRenderer>(new Model(*Engine::getInstance().GetModelManager()->GetModelByType(ModelType::Rock)), rock3);
	rock3->GetComponent<Transform>()->_position = Utils::getInstance().SpawnRandomPoint(positions);
	rock3->GetComponent<Transform>()->_rotation = { Utils::getInstance().RandomNumber(0, 5), Utils::getInstance().RandomNumber(0, 50), 0.f };
	scale = Utils::getInstance().RandomNumber(1.f, 3.f);
	rock3->GetComponent<Transform>()->_scale = { scale, scale, scale };

	gameObjects.push_back(rock1);
	gameObjects.push_back(rock2);
	gameObjects.push_back(rock3);


	//---------GENERATE PALM TREES-----------
	GameObject* palmTree = new GameObject();
	palmTree->AddComponent<MeshRenderer>(new Model(*Engine::getInstance().GetModelManager()->GetModelByType(ModelType::PalmTree)), palmTree);
	palmTree->GetComponent<Transform>()->_position = Utils::getInstance().SpawnRandomPoint(positions);
	palmTree->GetComponent<Transform>()->_rotation = { Utils::getInstance().RandomNumber(0, 5), Utils::getInstance().RandomNumber(0, 50), 0.f };
	scale = Utils::getInstance().RandomNumber(1.f, 3.f);
	palmTree->GetComponent<Transform>()->_scale = { scale, scale, scale };

	GameObject* palmTree2 = new GameObject();
	palmTree2->AddComponent<MeshRenderer>(new Model(*Engine::getInstance().GetModelManager()->GetModelByType(ModelType::PalmTree)), palmTree2);
	palmTree2->GetComponent<Transform>()->_position = Utils::getInstance().SpawnRandomPoint(positions);
	palmTree2->GetComponent<Transform>()->_rotation = { Utils::getInstance().RandomNumber(0, 5), Utils::getInstance().RandomNumber(0, 50), 0.f };
	scale = Utils::getInstance().RandomNumber(1.f, 3.f);
	palmTree2->GetComponent<Transform>()->_scale = { scale, scale, scale };

	GameObject* palmTree3 = new GameObject();
	palmTree3->AddComponent<MeshRenderer>(new Model(*Engine::getInstance().GetModelManager()->GetModelByType(ModelType::PalmTree)), palmTree3);
	palmTree3->GetComponent<Transform>()->_position = Utils::getInstance().SpawnRandomPoint(positions);
	palmTree3->GetComponent<Transform>()->_rotation = { Utils::getInstance().RandomNumber(0, 5), Utils::getInstance().RandomNumber(0, 50), 0.f };
	scale = Utils::getInstance().RandomNumber(1.f, 3.f);
	rock2->GetComponent<Transform>()->_scale = { scale, scale, scale };

	gameObjects.push_back(palmTree);
	gameObjects.push_back(palmTree2);
	gameObjects.push_back(palmTree3);


	//---------GENERATE LEAFS-----------
	GameObject* leaf = new GameObject();
	leaf->AddComponent<MeshRenderer>(new Model(*Engine::getInstance().GetModelManager()->GetModelByType(ModelType::Plants)), leaf);
	leaf->GetComponent<Transform>()->_position = Utils::getInstance().SpawnRandomPoint(positions);
	leaf->GetComponent<Transform>()->_rotation = { Utils::getInstance().RandomNumber(0, 5), Utils::getInstance().RandomNumber(0, 50), 0.f };
	scale = Utils::getInstance().RandomNumber(1.f, 3.f);
	leaf->GetComponent<Transform>()->_scale = { scale, scale, scale };

	GameObject* leaf2 = new GameObject();
	leaf2->AddComponent<MeshRenderer>(new Model(*Engine::getInstance().GetModelManager()->GetModelByType(ModelType::Plants)), leaf2);
	leaf2->GetComponent<Transform>()->_position = Utils::getInstance().SpawnRandomPoint(positions);
	leaf2->GetComponent<Transform>()->_rotation = { Utils::getInstance().RandomNumber(0, 5), Utils::getInstance().RandomNumber(0, 50), 0.f };
	scale = Utils::getInstance().RandomNumber(1.f, 3.f);
	leaf2->GetComponent<Transform>()->_scale = { scale, scale, scale };

	GameObject* leaf3 = new GameObject();
	leaf3->AddComponent<MeshRenderer>(new Model(*Engine::getInstance().GetModelManager()->GetModelByType(ModelType::Plants)), leaf3);
	leaf3->GetComponent<Transform>()->_position = Utils::getInstance().SpawnRandomPoint(positions);
	leaf3->GetComponent<Transform>()->_rotation = { Utils::getInstance().RandomNumber(0, 5), Utils::getInstance().RandomNumber(0, 50), 0.f };
	scale = Utils::getInstance().RandomNumber(0.5f, 2.f);
	leaf3->GetComponent<Transform>()->_scale = { scale, scale, scale };

	gameObjects.push_back(leaf);
	gameObjects.push_back(leaf2);
	gameObjects.push_back(leaf3);

}


