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

	Task* HandleInput();

public:

	// TODO 1: Create the tasks and the queue

};