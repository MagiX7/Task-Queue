#include "App.h"
#include "Input.h"

#include "TaskManager.h"

#include "SDL/include/SDL_scancode.h"


TaskManager::TaskManager()
{
	// TODO 1: Instantiate the tasks
	keyW = new MoveUp();
	keyA = new MoveLeft();
	keyS = new MoveDown();
	keyD = new MoveRight();
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
	if (tasks.start != nullptr)
	{
		Task* tmp = tasks.start->data;
		tmp->Execute(dt, actor);
		tasks.Pop(tmp);
	}
	
	return true;
}

bool TaskManager::CleanUp()
{
	// TODO 1: Don't forget to clear the list and delete the tasks
	RELEASE(keyW);
	RELEASE(keyA);
	RELEASE(keyS);
	RELEASE(keyD);

	tasks.Clear();

	return true;
}

bool TaskManager::EnqueueTask(Task* task)
{
	tasks.Push(task);

	return true;
}

Task* TaskManager::HandleInput()
{
	// TODO 2: Check if W,A,S or D is pressed to move the player, and return the corresponding task
	if (app->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT) return keyW;
	if (app->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT) return keyA;
	if (app->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT) return keyS;
	if (app->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT) return keyD;

	if (app->input->GetKey(SDL_SCANCODE_E) == KEY_DOWN)
	{
		// Horizontal axis
		Task* aux = keyA;
		keyA = keyD;
		keyD = aux;

		// Vertical axis
		aux = keyW;
		keyW = keyS;
		keyS = aux;
	}

	return nullptr;
}