//#include "App.h"
#include "Input.h"
#include "SceneGameplay.h"
#include "Player.h"
#include "Map.h"
#include "TaskManager.h"

#include "Queue.h"


SceneGameplay::SceneGameplay()
{
	map = new Map();
	player = new Player(EntityType::PLAYER, iPoint(64, 70));

	taskManager = new TaskManager();
}

bool SceneGameplay::Start()
{
	map->Load("Assets/Map/gameplay.tmx");
	player->Load();
	taskManager->Start();

	return true;
}

bool SceneGameplay::Update(float dt)
{
	Task* tmp = player->HandleInput(dt);
	if (tmp) taskManager->EnqueueTask(tmp);

	taskManager->Update(dt, player);

	map->Update(dt);
	player->Update(dt);
		
	return true;
}

bool SceneGameplay::PostUpdate()
{
	map->Draw();
	player->Draw();

	return true;
}

bool SceneGameplay::CleanUp()
{
	map->CleanUp();
	player->UnLoad();
	taskManager->CleanUp();

	return true;
}