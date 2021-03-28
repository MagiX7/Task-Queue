#include "App.h"
#include "Input.h"
#include "SceneGameplay.h"
#include "Player.h"
#include "Map.h"
#include "TaskManager.h"


SceneGameplay::SceneGameplay()
{
	map = new Map();
	player = new Player(EntityType::PLAYER, iPoint(64, 70));

}

bool SceneGameplay::Start()
{
	map->Load("Assets/Map/gameplay.tmx");
	player->Load();

	return true;
}

bool SceneGameplay::Update(float dt)
{
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

	return true;
}