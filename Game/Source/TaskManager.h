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
	bool Update(float dt);
	bool CleanUp();

	bool EnqueueTask(Task* task);
	bool DequeueTask();

public:
	// TODO 1: Create a task queue
	Queue<Task*> tasks;
	Task* currentTask;

};