#include "App.h"
#include "Input.h"

#include "TaskManager.h"

#include "SDL/include/SDL_scancode.h"


TaskManager::TaskManager()
{
}

TaskManager::~TaskManager()
{
}

bool TaskManager::Start()
{
	return true;
}

bool TaskManager::Update(float dt, Entity* actor)
{
	// TODO 2: Check if the list is empty and pop a task
	if (tasks.start != nullptr)
	{
		currentTask = tasks.start->data;
		currentTask->Execute(dt, actor);
		tasks.Pop(currentTask);
		
		// Ejecutar dos tasks en vez de una solo?
	}
	

	return true;
}

bool TaskManager::CleanUp()
{
	// TODO 1: Dont forget to clear the list
	tasks.Clear();

	return true;
}

bool TaskManager::EnqueueTask(Task* task)
{
	tasks.Push(task);

	return task;
}

bool TaskManager::DequeueTask()
{
	return tasks.Pop(tasks.start->data);
}