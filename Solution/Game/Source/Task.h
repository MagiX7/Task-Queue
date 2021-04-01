#pragma once

#include "Entity.h"

class Task
{
public:
	Task() {}
	virtual ~Task() {}
	
	virtual void Execute(float dt, Entity* actor) {}
};

class MoveLeft : public Task
{
public:
	MoveLeft() {}
	virtual ~MoveLeft() {}
	void Execute(float dt, Entity* actor) override
	{
		actor->bounds.x -= 200 * dt;
	}
};

class MoveRight : public Task
{
public:
	MoveRight() {}
	virtual ~MoveRight() {}
	void Execute(float dt, Entity* actor) override
	{
		actor->bounds.x += 350 * dt;
	}
};

class MoveUp : public Task
{
public:
	MoveUp() {}
	virtual ~MoveUp() {}
	void Execute(float dt, Entity* actor) override
	{
		actor->bounds.y -= 200 * dt;
	}
};

class MoveDown : public Task
{
public:
	MoveDown() {}
	virtual ~MoveDown() {}
	void Execute(float dt, Entity* actor) override
	{
		actor->bounds.y += 350 * dt;
	}
};
