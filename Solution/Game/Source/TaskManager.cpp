#include "App.h"
#include "Input.h"

#include "TaskManager.h"

#include "SDL/include/SDL_scancode.h"


TaskManager::TaskManager()
{
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
	if (tasks.start != nullptr)
	{
		Task* tmp;
		tmp = tasks.start->data;
		tmp->Execute(dt, actor);
		tasks.Pop(tmp);
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

	return true;
}

bool TaskManager::DequeueTask()
{
	return tasks.Pop(tasks.start->data);
}

Task* TaskManager::HandleInput(Entity* actor)
{
	if (app->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT) return keyW;
	if (app->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT) return keyA;
	if (app->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT) return keyS;
	if (app->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT) return keyD;

	if (app->input->GetKey(SDL_SCANCODE_E) == KEY_DOWN)
	{
		// Redefine the keys

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