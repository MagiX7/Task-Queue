#pragma once

#include "Module.h"
#include "Task.h"

#include "Queue.h"

class TaskManager : public Module
{
public:
	TaskManager();
	virtual ~TaskManager();

	bool Start();
	bool Update(float dt, Entity* actor);
	bool CleanUp();

	bool EnqueueTask(Task* task);
	bool DequeueTask();

	Task* HandleInput(Entity* actor);

public:

	// TODO 1: Create the tasks and the queue

};