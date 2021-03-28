#pragma once

#include "Module.h"

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

	Map* map;
	Player* player;

};
