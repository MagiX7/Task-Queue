#pragma once

#include "Entity.h"

class Task
{
public:
	Task(Entity* act) : actor(act) {}
	virtual ~Task() {}
	
	virtual void Execute(float dt) {}

	inline void SetActor(Entity* act) { actor = act; }

protected:
	Entity* actor;

};

class MoveLeft : public Task
{
public:
	MoveLeft(Entity* act) : Task(act) {}
	virtual ~MoveLeft() {};

	void Execute(float dt) override
	{
		actor->bounds.x -= 200 * dt;
	}
};

class MoveRight : public Task
{
public:
	MoveRight(Entity* act) : Task(act) {}
	virtual ~MoveRight() {};

	void Execute(float dt) override
	{
		actor->bounds.x += 350 * dt;
	}
};

class MoveUp : public Task
{
public:
	MoveUp(Entity* act) : Task(act) {}
	virtual ~MoveUp() {};

	void Execute(float dt) override
	{
		actor->bounds.y -= 200 * dt;
	}
};

class MoveDown : public Task
{
public:
	MoveDown(Entity* act) : Task(act) {}
	virtual ~MoveDown() {};

	void Execute(float dt) override
	{
		actor->bounds.y += 350 * dt;
	}
};
