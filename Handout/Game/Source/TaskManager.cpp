#include "App.h"
#include "Input.h"

#include "TaskManager.h"

#include "SDL/include/SDL_scancode.h"


TaskManager::TaskManager()
{
	// TODO 1: Instantiate the tasks

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
	// TODO 5: Check if the queue is not empty and execute the task.
	//		   Don't forget to pop it from the list.


	return true;
}

bool TaskManager::CleanUp()
{
	// TODO 1: Don't forget to clear the list and delete the tasks

	return true;
}

bool TaskManager::EnqueueTask(Task* task)
{
	// Uncomment to use it
	//tasks.Push(task);

	return true;
}

bool TaskManager::DequeueTask()
{
	// Uncomment to use it
	//return tasks.Pop(tasks.start->data);
	return true;
}

Task* TaskManager::HandleInput(Entity* actor)
{
	// TODO 2: Check if W,A,S or D is pressed to move the player, and return the corresponding task

	if (app->input->GetKey(SDL_SCANCODE_E) == KEY_DOWN)
	{
		// TODO 6: Redefine the keys so the horizontal axis is swapped.
		//		   Do the same with the vertical axis.

	}

	return nullptr;
}