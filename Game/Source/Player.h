#pragma once

#include "Entity.h"

#include "Task.h"
#include "Animation.h"
#include "Point.h"

class SDL_Texture;

class Player : public Entity
{
public:
	Player(EntityType type, iPoint pos);
	virtual ~Player() {};

	bool Load() override;
	bool Update(float dt) override;
	void Draw() override;
	bool UnLoad() override;

	bool HandleInput(float dt);

private:

	SDL_Texture* texture;

	pugi::xml_document pushbacksFile;
	pugi::xml_node pushbacksNode;
	pugi::xml_node playerNode;

	Animation* currentAnim;
	Animation idleAnim;
	Animation walkLeftAnim;
	Animation walkRightAnim;

	int direction; // 0 right 1 left

	// TODO : Create the tasks
	MoveLeft* moveLeft;
	MoveRight* moveRight;
	MoveUp* moveUp;
	MoveDown* moveDown;

};