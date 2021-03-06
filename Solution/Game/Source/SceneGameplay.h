#pragma once

#include "Module.h"
#include "Queue.h"

class Map;
class Player;
class TaskManager;

class SceneGameplay : public Module
{
public:
	SceneGameplay();

	virtual ~SceneGameplay() {};

	bool Start() override;

	bool Update(float dt) override;

	bool PostUpdate() override;

	bool CleanUp() override;

private:
	// TODO 3: Create a Task Manager
	TaskManager* taskManager;

	Map* map;
	Player* player;

};
