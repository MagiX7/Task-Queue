#include "App.h"
#include "Input.h"
#include "Textures.h"
#include "Render.h"

#include "Player.h"
#include "TaskManager.h"

#include "Log.h"

#define SPEED_X 100.0f
#define SPEED_Y 100.0f

Player::Player(EntityType type, iPoint pos) : Entity(type)
{
	name.Create("player");

	bounds.x = pos.x;
	bounds.y = pos.y;

	pugi::xml_parse_result result = pushbacksFile.load_file("pushbacks.xml");

	if (result == NULL)
	{
		LOG("Could not load the file, pugi error: ", result.description());
	}
	else
	{
		pushbacksNode = pushbacksFile.child("pushbacks");
		playerNode = pushbacksNode.child("player");

		// Load pushbacks animations for each animation
		pugi::xml_node n;

		for (n = playerNode.child("idle_animation").child("pushback"); n; n = n.next_sibling("pushback"))
		{
			idleAnim.PushBack({ n.attribute("x").as_int(), n.attribute("y").as_int(), n.attribute("w").as_int(), n.attribute("h").as_int() });
		}

		for (n = playerNode.child("walk_left_animation").child("pushback"); n; n = n.next_sibling("pushback"))
		{
			walkLeftAnim.PushBack({ n.attribute("x").as_int(), n.attribute("y").as_int(), n.attribute("w").as_int(), n.attribute("h").as_int() });
		}

		for (n = playerNode.child("walk_right_animation").child("pushback"); n; n = n.next_sibling("pushback"))
		{
			walkRightAnim.PushBack({ n.attribute("x").as_int(), n.attribute("y").as_int(), n.attribute("w").as_int(), n.attribute("h").as_int() });
		}
	}

	keyW = new MoveUp();
	keyA = new MoveLeft();
	keyS = new MoveDown();
	keyD = new MoveRight();
}

bool Player::Load()
{
	texture = app->tex->Load("Assets/Textures/Player/player.png");
	currentAnim = &idleAnim;

	// 0 right, 1 left
	direction = 0;

	return true;
}

bool Player::Update(float dt)
{
	bool ret = true;

	idleAnim.speed = 5.0f * dt;
	walkLeftAnim.speed = 7.0f * dt;
	walkRightAnim.speed = 7.0f * dt;

	//ret = HandleInput(dt);

	currentAnim->Update();

	return ret;
}

void Player::Draw()
{
	app->render->DrawTexture(texture, bounds.x, bounds.y, &currentAnim->GetCurrentFrame());
}

bool Player::UnLoad()
{
	app->tex->UnLoad(texture);

	return true;
}

Task* Player::HandleInput(float dt)
{
	if (app->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT)
	{
		if (direction == 0)
		{
			currentAnim = &walkRightAnim;
		}
		else if (direction == 1)
		{
			currentAnim = &walkLeftAnim;
		}
		return keyW;
	}

	else if (app->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT)
	{
		if (direction == 0)
		{
			currentAnim = &walkRightAnim;
		}
		else if (direction == 1)
		{
			currentAnim = &walkLeftAnim;
		}
		return keyS;
		//app->taskManager->EnqueueTask(keyS);
	}

	else if (app->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
	{
		direction = 1;

		if (currentAnim != &walkLeftAnim)
		{
			walkLeftAnim.Reset();
			currentAnim = &walkLeftAnim;
		}
		return keyA;
		//app->taskManager->EnqueueTask(keyA);
	}

	else if (app->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
	{
		direction = 0;

		if (currentAnim != &walkRightAnim)
		{
			walkRightAnim.Reset();
			currentAnim = &walkRightAnim;
		}
		return keyD;
		//app->taskManager->EnqueueTask(keyD);
	}

	if (app->input->GetKey(SDL_SCANCODE_W) == KEY_IDLE &&
		app->input->GetKey(SDL_SCANCODE_S) == KEY_IDLE &&
		app->input->GetKey(SDL_SCANCODE_A) == KEY_IDLE &&
		app->input->GetKey(SDL_SCANCODE_D) == KEY_IDLE)
	{
		currentAnim = &idleAnim;
	}


	return nullptr;
}