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

	// TODO 3: Instantiate the Task Manager
	taskManager = new TaskManager();
}

bool SceneGameplay::Start()
{
	map->Load("Assets/Map/gameplay.tmx");
	player->Load();

	// TODO 3: Start it
	taskManager->Start();

	return true;
}

bool SceneGameplay::Update(float dt)
{
	// TODO 4: Check if there is a task coming from an input and enqueue it
	//		   Also call the update method of the task manager
	Task* tmp = taskManager->HandleInput();
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

	// TODO 3: And call the clean up
	taskManager->CleanUp();

	return true;
}